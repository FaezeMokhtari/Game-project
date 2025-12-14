#ifndef BOARD_H
#define BOARD_H

#include "rectangle.h"
#include "cell.h"
#include <QGraphicsScene>
#include <QVector>
#include <QString>

class board
{
public:
    QVector<rectangle*> R;
    QVector<cell*> grid;
    QGraphicsScene* scene;
    float numberofh;
    board();
    ~board();
    int pars(const QString& mapText);
    void graphic(QGraphicsScene* scene,float w,float h);
};

#endif // BOARD_H
