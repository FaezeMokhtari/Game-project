#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QPen>


class rectangle
{
public:
    int x;
    int y;
    int s;
    QString name;
    bool control;
    bool mark;
    bool scout;
    bool seargeant;
    bool sniper;
    QString player;

    rectangle( int nx, int ny, int ns, QString nname);
    friend class board;
};

#endif // RECTANGLE_H
