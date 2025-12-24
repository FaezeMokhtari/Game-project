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
    QGraphicsScene* screen;
    float numberofh;
    board();
    ~board();
    int pars(const QString& mapText);
    void graphic(QGraphicsScene* screen,float w,float h);
    int seting(const QString& setText);
    QString bac(int i);
};

#endif // BOARD_H
