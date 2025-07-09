#include "ellipsefigure.h"
#include <QPainter>
#include <cmath>

EllipseFigure::EllipseFigure() : ellipseBounds(0, 0, 0, 0), color(Qt::black) {}

EllipseFigure::EllipseFigure(const QRect& bounds, const QColor& c)
    : ellipseBounds(bounds), color(c) {}

void EllipseFigure::draw(QPainter* painter)
{
    painter->setPen(color);
    painter->drawEllipse(ellipseBounds);
}

void EllipseFigure::serialize(QDataStream& out)
{
    out << QString("Ellipse") << ellipseBounds << color;
}

void EllipseFigure::deserialize(QDataStream& in)
{
    in >> ellipseBounds >> color;
}

bool EllipseFigure::contains(const QPoint& pt) const
{
    double dx = pt.x() - ellipseBounds.center().x();
    double dy = pt.y() - ellipseBounds.center().y();
    double rx = ellipseBounds.width() / 2.0;
    double ry = ellipseBounds.height() / 2.0;

    if (rx == 0 || ry == 0)
        return false;

    double value = (dx*dx)/(rx*rx) + (dy*dy)/(ry*ry);
    return std::abs(value - 1.0) <= 0.15; // Только по контуру
}

void EllipseFigure::moveBy(int dx, int dy)
{
    ellipseBounds.translate(dx, dy);
}

QRect EllipseFigure::boundingRect() const
{
    return ellipseBounds;
}

Figure* EllipseFigure::clone() const {
    return new EllipseFigure(ellipseBounds, color);
}
