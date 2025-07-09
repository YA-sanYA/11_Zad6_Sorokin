#include "linefigure.h"
#include <QPainter>
#include <cmath>

LineFigure::LineFigure() : line(0, 0, 0, 0), color(Qt::black) {}

LineFigure::LineFigure(const QLine& l, const QColor& c)
    : line(l), color(c) {}

void LineFigure::draw(QPainter* painter)
{
    painter->setPen(color);
    painter->drawLine(line);
}

void LineFigure::serialize(QDataStream& out)
{
    out << QString("Line") << line << color;
}

void LineFigure::deserialize(QDataStream& in)
{
    in >> line >> color;
}

bool LineFigure::contains(const QPoint& pt) const
{
    // Проверка близости к линии (в радиусе 3 пикселей)
    double x0 = pt.x(), y0 = pt.y();
    double x1 = line.x1(), y1 = line.y1();
    double x2 = line.x2(), y2 = line.y2();

    double dx = x2 - x1, dy = y2 - y1;
    double len = std::hypot(dx, dy);
    if (len == 0.0) return false;

    double dist = std::abs(dy * x0 - dx * y0 + x2*y1 - y2*x1) / len;
    return dist <= 3;
}

void LineFigure::moveBy(int dx, int dy)
{
    line.translate(dx, dy);
}

QRect LineFigure::boundingRect() const
{
    return QRect(line.p1(), line.p2()).normalized();
}

QLine LineFigure::getLine() const
{
    return line;
}

Figure* LineFigure::clone() const {
    return new LineFigure(line, color);
}
