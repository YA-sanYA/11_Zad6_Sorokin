#include "ellipsefigure.h"

EllipseFigure::EllipseFigure() : ellipseBounds(0, 0, 0, 0) {}

EllipseFigure::EllipseFigure(const QRect& eb) : ellipseBounds(eb)  {}

void EllipseFigure::draw(QPainter* painter)
{
    painter->drawEllipse(ellipseBounds);
}

void EllipseFigure::serialize(QDataStream& out)
{
    out << QString("Ellipse") << ellipseBounds;
}

void EllipseFigure::deserialize(QDataStream& in)
{
    in >> ellipseBounds;
}

bool EllipseFigure::contains(const QPoint& pt) const
{
    QPoint center = ellipseBounds.center();
    double dx = pt.x() - center.x();
    double dy = pt.y() - center.y();
    double rx = ellipseBounds.width() / 2.0;
    double ry = ellipseBounds.height() / 2.0;

    if (rx == 0 || ry == 0)
        return false;

    double value = (dx*dx) / (rx*rx) + (dy*dy) / (ry*ry);

    const double threshold = 0.15;
    return std::abs(value - 1.0) <= threshold;
}

void EllipseFigure::moveBy(int dx, int dy)
{
    ellipseBounds.translate(dx, dy);
}
