#ifndef ELLIPSEFIGURE_H
#define ELLIPSEFIGURE_H

#include "figure.h"
#include <QRect>

class EllipseFigure : public Figure
{
public:
    EllipseFigure();
    EllipseFigure(const QRect& ellipseBounds);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;

private:
    QRect ellipseBounds;
};

#endif // ELLIPSEFIGURE_H
