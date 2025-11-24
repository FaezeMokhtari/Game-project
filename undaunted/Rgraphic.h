#ifndef RGRAPHIC_H
#define RGRAPHIC_H

#include "rectangle.h"
#include <QGraphicsPathItem>
#include <QBrush>
#include <QPen>
#include <QPixmap>

class Rgraphic : public QGraphicsPathItem
{
public:
    explicit Rgraphic(rectangle* model, QGraphicsItem* parent = nullptr);

    void setBackground(const QPixmap& pixmap, const QRect& sourceRect);

    void updateAppearance();

private:
    rectangle* model;
    QBrush backgroundBrush;
    QPen borderPen;
    float width = 90;
    float height = 120;
    float cornerRadius = 15;
};

#endif // RGRAPHIC_H
