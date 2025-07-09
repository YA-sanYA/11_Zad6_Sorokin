#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QDataStream>
#include <QPoint>

class Figure {
public:
    virtual ~Figure() {}

    virtual void draw(QPainter* painter) = 0;
    virtual void serialize(QDataStream& out) = 0;
    virtual void deserialize(QDataStream& in) = 0;
    virtual bool contains(const QPoint& point) const = 0;
    virtual void moveBy(int dx, int dy) = 0;
};

#endif // FIGURE_H
