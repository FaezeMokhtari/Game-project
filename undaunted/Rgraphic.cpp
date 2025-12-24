#include "Rgraphic.h"
#include <QPainter>

Rgraphic::Rgraphic(rectangle* m, QGraphicsItem* parent)
    : QGraphicsPathItem(parent), model(m)
{
    borderPen = QPen(Qt::black, 2);
    setPen(borderPen);

    updateAppearance();
    setZValue(1);
}


void Rgraphic::setw(float w)
{
    width = w;
    updateAppearance();
}


void Rgraphic::seth(float h)
{
    height = h;
    updateAppearance();
}

void Rgraphic::updateAppearance()
{
    prepareGeometryChange();

    QPainterPath path;
    path.addRoundedRect(0, 0, width, height, cornerRadius, cornerRadius);
    setPath(path);

    if (!backgroundBrush.texture().isNull())
        setBrush(backgroundBrush);
    else
        setBrush(Qt::darkGray);

     setPen(borderPen);
}

void Rgraphic::setBackground(const QPixmap& pixmap, const QRect& sourceRect)
{
    QPixmap cropped = pixmap.copy(sourceRect);

    QPixmap scaled = cropped.scaled(
        width,
        height,
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation
        );

    backgroundBrush = QBrush(scaled);
    updateAppearance();
}
