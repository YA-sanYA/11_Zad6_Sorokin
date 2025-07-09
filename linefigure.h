#ifndef LINEFIGURE_H
#define LINEFIGURE_H

#include "figure.h"
#include <QLine>

class LineFigure : public Figure
{
public:
    LineFigure();
    LineFigure(const QLine& line);

    void draw(QPainter* painter) override;
    void serialize(QDataStream& out) override;
    void deserialize(QDataStream& in) override;
    bool contains(const QPoint& point) const override;
    void moveBy(int dx, int dy) override;

private:
    QLine line;
};

#endif // LINEFIGURE_H
