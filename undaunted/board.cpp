#include "board.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QFile>
#include "Rgraphic.h"

board::board() : scene() {}

QVector<cell*> board::pars(const QString& filename)
{
    QVector<cell*> grid;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << filename;
        return grid;
    }

    QTextStream in(&file);
    QList<QString> lines;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty())
            lines.append(line);
    }
    file.close();

    for (int visualRow = 0; visualRow < lines.size(); ++visualRow) {
        QString line = lines[visualRow];

        QStringList tokens = line.split("|", Qt::SkipEmptyParts);


        int colOffset = (visualRow % 2 == 0) ? 0 : 0;
        int x = colOffset;

        for (const QString& t : tokens) {
            QString trimmed = t.trimmed();
            if (trimmed.isEmpty()) continue;


            QStringList parts = trimmed.split(":");
            if (parts.size() != 2) continue;

            QString name = parts[0];
            int s = parts[1].toInt();

            if (name.length() < 2) continue;
            QChar r = ' ';
            int n = name.mid(1).toInt();
            cell* c = new cell{ x, visualRow, n, s, ' ' };
            grid.push_back(c);

            x++;
    }
 }
    return grid;
}


void board::graphic(QGraphicsScene* scn, QVector<cell*> grid)
{
    scene = scn;
    for (cell* c : grid) {
        rectangle* r = new rectangle(c->n, c->x, c->y, c->s, c->r);
        R.push_back(r);

        Rgraphic* g = new Rgraphic(r);
        scene->addItem(g);
    }
}

board::~board()
{
    // حذف همه rectangleها
    for (rectangle* r : R) {
        delete r;
    }
    R.clear();

    // حذف همه cellها
  //  for (cell* c : pars) {
  //      delete c;
  //  }
  //  grid.clear();

}
