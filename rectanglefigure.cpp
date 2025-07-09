#include "rectanglefigure.h"

RectangleFigure::RectangleFigure() : rect(0, 0, 0, 0) {}

RectangleFigure::RectangleFigure(const QRect& r) : rect(r) {}

void RectangleFigure::draw(QPainter* painter) {
    painter->drawRect(rect);
}

void RectangleFigure::serialize(QDataStream& out) {
    out << QString("Rectangle") << rect;
}

void RectangleFigure::deserialize(QDataStream& in) {
    in >> rect;
}

bool RectangleFigure::contains(const QPoint& point) const
{
    const int tolerance = 5;

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

void RectangleFigure::moveBy(int dx, int dy) {
    rect.translate(dx, dy);
}
