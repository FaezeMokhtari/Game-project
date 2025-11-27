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

    board();
    ~board();
    void pars(const QString& mapText);
    void graphic(QGraphicsScene* scene);
};

#endif // BOARD_H
