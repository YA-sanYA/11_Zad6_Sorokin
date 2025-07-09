#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QList>
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

    Figure* createFigureFromPoints(const QPoint& p1, const QPoint& p2);
    void deleteAllFigures();
};

#endif // CANVAS_H
