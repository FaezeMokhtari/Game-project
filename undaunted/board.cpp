#include "board.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QFile>
#include "Rgraphic.h"

board::board() : scene() {}

void board::pars(const QString& filename)
{

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << filename;
        return ;
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

        int x = 0;

        for (int i = 0; i < tokens.size(); ++i) {
            QString trimmed = tokens[i].trimmed();
            if (trimmed.isEmpty()) continue;

            QStringList parts = trimmed.split(":");
            if (parts.size() != 2) continue;

            QString name = parts[0];
            int s = parts[1].toInt();

            if (name.length() < 3) continue;

            char r = name[0].toLatin1();
            int n = name.mid(1).toInt();
            cell* c = new cell{ x, visualRow, n, s, r};
            grid.push_back(c);

            x++;
        }

 }

}


void board::graphic(QGraphicsScene* scn)
{
    scene = scn;
    for (int i = 0; i < grid.size(); ++i) {
        rectangle* r = new rectangle(grid[i]->n, grid[i]->x, grid[i]->y, grid[i]->s, grid[i]->r);
        R.push_back(r);

        Rgraphic* g = new Rgraphic(r);
        scene->addItem(g);
    }
}

board::~board()
{

    for (int i = 0; i < grid.size(); ++i) {
        delete grid[i];
    }
    grid.clear();

    for (int i = 0; i < R.size(); ++i) {
        delete R[i];
    }
    R.clear();


}
