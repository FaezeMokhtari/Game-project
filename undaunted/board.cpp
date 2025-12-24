#include "board.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QFile>
#include "Rgraphic.h"

board::board()  {
    screen = nullptr;
}

int board::pars(const QString& map)
{

    QFile file(map);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Can not open file:" << map;
        return 0;
    }

    QTextStream in(&file);
    QList<QString> strings;

    while (!in.atEnd()) {
        QString trimmeed = in.readLine().trimmed();
        if (!trimmeed.isEmpty())
            strings.append(trimmeed);
    }
    file.close();

    numberofh = strings.size();

    for (int row = 0; row < strings.size(); ++row) {

        QString temp = strings[row];

        QStringList tokens = temp.split("|", Qt::SkipEmptyParts);

        int x = 0;

        for (int i = 0; i < tokens.size(); ++i) {
            QString tk = tokens[i];
            if (tk.isEmpty()) continue;

            QStringList parts = tk.split(":");

            QString part1 = parts[0];
            int s = parts[1].toInt();
            cell* c = new cell{ x, row, s, part1};
            grid.push_back(c);

            rectangle* r = new rectangle{x, row, s, part1};
            R.push_back(r);

            x++;
        }

 }
    return 1;
}

void board::graphic(QGraphicsScene* scn,float w,float h)
{
    screen = scn;
    if (!screen) return;
    float spacing = 4.0f;
    float newh = (h-numberofh*spacing)/numberofh;
    for (int i = 0 ; i < R.size() ; i++) {

        Rgraphic* g = new Rgraphic(R[i]);

        g->setw(w);
        g->seth(newh);

        float xPos = R[i]->x * (w + spacing);
        float yPos = R[i]->y * (newh + spacing);

        if (R[i]->y % 2 != 0)
            xPos += (w + spacing) / 2.0f;
        g->setPos(xPos, yPos);

        QString path;
        if (R[i]->s == 0){
            if(bac(i) != "0") path = bac(i);
            else
            path = ":/new/prefix1/1ns.jpg";
        }
        else if (R[i]->s == 1) {
           if(bac(i) != "0") path = bac(i);
            else
            path = ":/new/prefix1/2ns.jpg";
        }
        else if (R[i]->s == 2) {
            if(bac(i) != "0") path = bac(i);
            else
                path = ":/new/prefix1/3ns.jpg";
        }
        QPixmap pix(path);
        g->setBackground(pix, pix.rect());
        if(R[i]->player == "A"){
            g->borderPen = QPen(Qt::blue, 2);
            g->updateAppearance();
        }else if(R[i]->player == "B"){
            g->borderPen = QPen(Qt::red, 2);
            g->updateAppearance();
        }

        screen->addItem(g);
    }
}

int board::seting(const QString& setText)
{
    QFile file(setText);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Can not open file:" << setText;
        return 0;
    }

    QTextStream in(&file);
    QList<QString> strings;

    while (!in.atEnd()) {
        QString trimmeed = in.readLine().trimmed();
        if (!trimmeed.isEmpty())
            strings.append(trimmeed);
    }
    file.close();

    for (int row = 0; row < strings.size(); ++row) {

        QString temp = strings[row];

        QStringList tokens = temp.split(":", Qt::SkipEmptyParts);

        for (int i = 0; i < R.size(); ++i) {

            if(R[i]->name == tokens[0]){

            QStringList parts = tokens[1].split(",");
            R[i]->player = parts[0];
            if (parts[1] == "Mark") {
                R[i]->mark = true;
            }
            else if (parts[1] == "Sniper") {
                R[i]->sniper = true;
            }
            else if (parts[1] == "Seargeant") {
                R[i]->seargeant = true;
            }
            else if (parts[1] == "Scout") {
                R[i]->scout = true;
            }
            else if (parts[1] == "Control"){
                R[i]->control =  true;
            }

        }

    }
  }
    return 1;
    }
QString board::bac(int i){
    QString path;
    if (R[i]->mark) {
        path = ":/new/prefix1/1s.webp";
    }
    else if (R[i]->sniper) {
        path = ":/new/prefix1/1s.webp";
    }
    else if (R[i]->seargeant) {
        path = ":/new/prefix1/1s.webp";
    }
    else if (R[i]->control) {
        path = ":/new/prefix1/1s.webp";
    }
    else if (R[i]->scout){
        path = ":/new/prefix1/1s.webp";
    } else
        path = "0";
    return path;
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

    if (screen) {
        QList<QGraphicsItem*> itemsToRemove = screen->items();
       for (QGraphicsItem* item : itemsToRemove) {
            Rgraphic* rg = dynamic_cast<Rgraphic*>(item);
         if (rg) {
               screen->removeItem(rg);
                delete rg;
           }
        }
   }

}
