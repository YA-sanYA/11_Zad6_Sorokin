#ifndef LINEFIGURE_H
#define LINEFIGURE_H

#include "figure.h"
#include <QLine>
#include <QColor>

class LineFigure : public Figure
{
    QLine line;
    QColor color;

public:
    LineFigure();
    LineFigure(const QLine& l, const QColor& c = Qt::black);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;
    QRect boundingRect() const override;
    QLine getLine() const;
    Figure* clone() const override;
};

#endif // LINEFIGURE_H
