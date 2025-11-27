#include "Rgraphic.h"
#include <QPainter>
#include "rectangle.h"
#include <QGraphicsPathItem>

Rgraphic::Rgraphic(rectangle* m, QGraphicsItem* parent)
    : QGraphicsPathItem(parent), model(m)
{
    QPainterPath path;
    path.addRoundedRect(0, 0, width, height, cornerRadius, cornerRadius);
    setPath(path);

    borderPen = QPen(Qt::black, 2);
    setPen(borderPen);

    updateAppearance();

    float spacing = 3;
    float xPos = model->x * (width + spacing);
    float yPos = model->y * (height + spacing);

    if (model->y % 2 != 0) xPos += (width + spacing) / 2.0f;

    setPos(xPos, yPos);
    setZValue(1);
}

void Rgraphic::updateAppearance()
{
    setBrush(Qt::darkGray);

    if (!backgroundBrush.texture().isNull()) setBrush(backgroundBrush);
}

void Rgraphic::setBackground(const QPixmap& pixmap, const QRect& sourceRect)
{
    QPixmap cropped = pixmap.copy(sourceRect);
    backgroundBrush = QBrush(cropped);
    updateAppearance();
}
