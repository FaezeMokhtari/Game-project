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

    void setw(float w){width = w;};
    void seth(float h){height = h;};
    void setBackground(const QPixmap& pixmap, const QRect& sourceRect);
    void updateAppearance();

private:
    rectangle* model;
    QBrush backgroundBrush;
    QPen borderPen;
    float width = 60;
    float height = 70;
    float cornerRadius = 5;
};

#endif // RGRAPHIC_H
