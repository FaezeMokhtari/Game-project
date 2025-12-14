#include "board.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QFile>
#include "Rgraphic.h"

board::board()  {
    scene = nullptr;
}

int board::pars(const QString& filename)
{

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << filename;
        return 0;
    }

    QTextStream in(&file);
    QList<QString> lines;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty())
            lines.append(line);
    }
    file.close();

    numberofh = lines.size();

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
    return 0;
}

void board::graphic(QGraphicsScene* scn,float w,float h)
{
    scene = scn;
    if (!scene) return;

    float spacing = 4.0f;
    float newh = (h-numberofh*spacing)/numberofh;
    for (auto* c : grid) {

        rectangle* r = new rectangle(
            c->n,
            c->x,
            c->y,
            c->s,
            c->r
            );
        R.push_back(r);

        Rgraphic* g = new Rgraphic(r);

        g->setw(w);
        g->seth(newh);

        float xPos = r->x * (w + spacing);
        float yPos = r->y * (newh + spacing);

        if (r->y % 2 != 0)
            xPos += (w + spacing) / 2.0f;
        g->setPos(xPos, yPos);

        QString path;
        if (r->s == 0) path = ":/new/prefix1/1ns.jpg";
        else if (r->s == 1) path = ":/new/prefix1/2ns.jpg";
        else path = ":/new/prefix1/3ns.jpg";

        QPixmap pix(path);
        g->setBackground(pix, pix.rect());
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

    if (scene) {
        QList<QGraphicsItem*> itemsToRemove = scene->items();
        for (QGraphicsItem* item : itemsToRemove) {
            Rgraphic* rg = dynamic_cast<Rgraphic*>(item);
            if (rg) {
                scene->removeItem(rg);
                delete rg;
            }
        }
    }

}
