#include "linefigure.h"

LineFigure::LineFigure() : line(0, 0, 0, 0) {}

LineFigure::LineFigure(const QLine& l) : line(l) {}

void LineFigure::draw(QPainter* painter)
{
    painter->drawLine(line);
}

void LineFigure::serialize(QDataStream& out)
{
    out << QString("Line") << line;
}

void LineFigure::deserialize(QDataStream& in)
{
    in >> line;
}

bool LineFigure::contains(const QPoint& point) const
{
    QPointF p1 = line.p1();
    QPointF p2 = line.p2();
    QPointF p = point;

    QPointF v = p2 - p1;
    QPointF w = p - p1;

    double lenSquared = v.x() * v.x() + v.y() * v.y();
    if (lenSquared == 0.0)
        return (p - p1).manhattanLength() < 3;

    double t = (w.x() * v.x() + w.y() * v.y()) / lenSquared;
    if (t < 0.0 || t > 1.0)
        return false;

    QPointF projection = p1 + t * v;
    double distance = std::hypot(p.x() - projection.x(), p.y() - projection.y());
    return distance < 5.0;
}

void LineFigure::moveBy(int dx, int dy)
{
    line.translate(dx, dy);
}
