#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QList>
#include <QStack>
#include <QPoint>
#include "figure.h"

enum class ToolType {
    None,
    Rectangle,
    Ellipse,
    Line,
    Select
};

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

    void setTool(ToolType tool);
    bool saveToFile(const QString& filename);
    bool loadFromFile(const QString& filename);
    void clearAll();
    void deleteSelected();
    void setBackgroundColor(const QColor& color);
    void setBrushColor(const QColor& color);
    QColor getBrushColor() const;
    void copySelectedFigure();
    void pasteFigure();
    void pushToUndo();
    void undo();
    void redo();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QList<Figure*> figures;
    Figure* currentFigure;
    Figure* selectedFigure;
    QPoint startPoint;
    ToolType currentTool;
    Figure* copiedFigure = nullptr;

    Figure* createFigureFromPoints(const QPoint& p1, const QPoint& p2);
    void deleteAllFigures();
    QStack<QVector<Figure*>> undoStack;
    QStack<QVector<Figure*>> redoStack;

    QColor backgroundColor = Qt::white;
    QColor brushColor = Qt::black;

};

#endif // CANVAS_H
