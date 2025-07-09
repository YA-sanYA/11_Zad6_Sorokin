#ifndef RECTANGLEFIGURE_H
#define RECTANGLEFIGURE_H

#include "figure.h"
#include <QRect>

class RectangleFigure : public Figure
{
public:
    RectangleFigure();
    RectangleFigure(const QRect& rect);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;

private:
    QRect rect;
};

#endif // RECTANGLEFIGURE_H
