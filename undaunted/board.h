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
    QGraphicsScene* scene;

    board();
    ~board();
    QVector<cell*> pars(const QString& mapText);
    void graphic(QGraphicsScene* scene, QVector<cell*> grid);
};

#endif // BOARD_H
