#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QPen>

class rectangle
{
public:
    int n;
    int x;
    int y;
    int s;
    char r;

    rectangle(int nn, int nx, int ny, int ns, char nr);
    friend class board;
};

#endif // RECTANGLE_H
