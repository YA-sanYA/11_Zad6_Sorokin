#include "rectanglefigure.h"
#include <QPainter>

RectangleFigure::RectangleFigure() : rect(0, 0, 0, 0), color(Qt::black) {}

RectangleFigure::RectangleFigure(const QRect& r, const QColor& c)
    : rect(r), color(c) {}

void RectangleFigure::draw(QPainter* painter)
{
    painter->setPen(color);
    painter->drawRect(rect);
}

void RectangleFigure::serialize(QDataStream& out)
{
    out << QString("Rectangle") << rect << color;
}

void RectangleFigure::deserialize(QDataStream& in)
{
    in >> rect >> color;
}

bool RectangleFigure::contains(const QPoint& point) const
{
    const int tolerance = 5; // в пикселях, "насколько рядом" с контуром

    int left   = rect.left();
    int right  = rect.right();
    int top    = rect.top();
    int bottom = rect.bottom();

    int x = point.x();
    int y = point.y();

    bool onLeft   = qAbs(x - left)   <= tolerance && y >= top    && y <= bottom;
    bool onRight  = qAbs(x - right)  <= tolerance && y >= top    && y <= bottom;
    bool onTop    = qAbs(y - top)    <= tolerance && x >= left   && x <= right;
    bool onBottom = qAbs(y - bottom) <= tolerance && x >= left   && x <= right;

    return onLeft || onRight || onTop || onBottom;
}


void RectangleFigure::moveBy(int dx, int dy)
{
    rect.translate(dx, dy);
}

QRect RectangleFigure::boundingRect() const
{
    return rect;
}

Figure* RectangleFigure::clone() const {
    return new RectangleFigure(rect, color);
}
