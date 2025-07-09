#include "canvas.h"
#include "rectanglefigure.h"
#include "ellipsefigure.h"
#include "linefigure.h"

#include <QPainter>
#include <QMouseEvent>
#include <QFile>
#include <QDataStream>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), currentFigure(nullptr), selectedFigure(nullptr), currentTool(ToolType::None)
{
    setMouseTracking(true);
}

void Canvas::setTool(ToolType tool)
{
    currentTool = tool;
    selectedFigure = nullptr;
}

void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.fillRect(rect(), backgroundColor);

    for (Figure* f : figures)
        f->draw(&painter);

    if (currentFigure)
        currentFigure->draw(&painter);

    if (selectedFigure) {
        QPen pen(Qt::red, 2, Qt::DashLine);
        painter.setPen(pen);

        QRect bounds = selectedFigure->boundingRect();
        bounds.adjust(-3, -3, +3, +3);
        painter.drawRect(bounds);
    }
}


void Canvas::mousePressEvent(QMouseEvent *event)
{
    startPoint = event->pos();

    if (currentTool == ToolType::Select) {
        selectedFigure = nullptr;
        for (Figure* f : figures) {
            if (f->contains(startPoint)) {
                selectedFigure = f;
                break;
            }
        }
        update();
    } else {
        delete currentFigure;
        currentFigure = nullptr;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (currentTool == ToolType::Select && selectedFigure && (event->buttons() & Qt::LeftButton)) {
        QPoint delta = event->pos() - startPoint;
        selectedFigure->moveBy(delta.x(), delta.y());
        startPoint = event->pos();
        update();
    }
    else if (event->buttons() & Qt::LeftButton) {
        delete currentFigure;
        currentFigure = createFigureFromPoints(startPoint, event->pos());
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (currentTool != ToolType::Select && currentFigure) {
        pushToUndo();
        figures.append(currentFigure);
        currentFigure = nullptr;
        update();
    }
}

Figure* Canvas::createFigureFromPoints(const QPoint& p1, const QPoint& p2)
{
    QRect rect = QRect(p1, p2).normalized();
    switch (currentTool) {
    case ToolType::Rectangle:
        return new RectangleFigure(rect, brushColor);
    case ToolType::Ellipse:
        return new EllipseFigure(rect, brushColor);
    case ToolType::Line:
        return new LineFigure(QLine(p1, p2), brushColor);
    default:
        return nullptr;
    }
}

bool Canvas::saveToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QDataStream out(&file);
    out << int(figures.size());
    for (Figure* f : figures) {
        f->serialize(out);
    }
    out << backgroundColor;

    return true;
}

bool Canvas::loadFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    deleteAllFigures();

    QDataStream in(&file);
    int count;
    in >> count;

    for (int i = 0; i < count; ++i) {
        QString type;
        in >> type;
        Figure* f = nullptr;
        if (type == "Rectangle") {
            f = new RectangleFigure();
        } else if (type == "Ellipse") {
            f = new EllipseFigure();
        } else if (type == "Line") {
            f = new LineFigure();
        }

        if (f) {
            f->deserialize(in);
            figures.append(f);
        }
    }

    in >> backgroundColor;

    update();
    return true;
}

void Canvas::clearAll()
{
    deleteAllFigures();
    backgroundColor = Qt::white;
    update();
}

void Canvas::deleteSelected()
{
    if (selectedFigure) {
        pushToUndo();
        figures.removeOne(selectedFigure);
        delete selectedFigure;
        selectedFigure = nullptr;
        update();
    }
}

void Canvas::deleteAllFigures()
{
    for (Figure* f : figures)
        delete f;
    figures.clear();

    delete currentFigure;
    currentFigure = nullptr;

    delete selectedFigure;
    selectedFigure = nullptr;
}

void Canvas::setBackgroundColor(const QColor& color)
{
    backgroundColor = color;
    update();
}

void Canvas::setBrushColor(const QColor& color)
{
    brushColor = color;
}

QColor Canvas::getBrushColor() const
{
    return brushColor;
}

void Canvas::copySelectedFigure()
{
    if (copiedFigure) {
        delete copiedFigure;
        copiedFigure = nullptr;
    }

    if (selectedFigure) {
        copiedFigure = selectedFigure->clone();
    }
}

void Canvas::pasteFigure()
{
    if (copiedFigure) {
        pushToUndo();
        Figure* newFigure = copiedFigure->clone();
        newFigure->moveBy(10, 10);
        figures.append(newFigure);
        update();
    }
}

void Canvas::pushToUndo()
{
    QVector<Figure*> snapshot;
    for (Figure* f : figures)
        snapshot.append(f->clone());

    undoStack.push(snapshot);

    for (auto& snapshot : redoStack) {
        qDeleteAll(snapshot);
    }    redoStack.clear();
}

void Canvas::undo()
{
    if (undoStack.isEmpty())
        return;

    QVector<Figure*> snapshot;
    for (Figure* f : figures)
        snapshot.append(f->clone());
    redoStack.push(snapshot);

    deleteAllFigures();
    figures = undoStack.pop();

    selectedFigure = nullptr;
    update();
}

void Canvas::redo()
{
    if (redoStack.isEmpty())
        return;

    QVector<Figure*> snapshot;
    for (Figure* f : figures)
        snapshot.append(f->clone());
    undoStack.push(snapshot);

    deleteAllFigures();
    figures = redoStack.pop();

    selectedFigure = nullptr;
    update();
}

