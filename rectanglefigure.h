#ifndef RECTANGLEFIGURE_H
#define RECTANGLEFIGURE_H

#include "figure.h"
#include <QRect>
#include <QColor>

class RectangleFigure : public Figure
{
    QRect rect;
    QColor color;

public:
    RectangleFigure();
    RectangleFigure(const QRect& r, const QColor& c = Qt::black);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;
    QRect boundingRect() const override;
    Figure* clone() const override;
};

#endif // RECTANGLEFIGURE_H
