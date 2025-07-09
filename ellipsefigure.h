#ifndef ELLIPSEFIGURE_H
#define ELLIPSEFIGURE_H

#include "figure.h"
#include <QRect>
#include <QColor>

class EllipseFigure : public Figure
{
    QRect ellipseBounds;
    QColor color;

public:
    EllipseFigure();
    EllipseFigure(const QRect& bounds, const QColor& c = Qt::black);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;
    QRect boundingRect() const override;
    Figure* clone() const override;
};

#endif // ELLIPSEFIGURE_H
