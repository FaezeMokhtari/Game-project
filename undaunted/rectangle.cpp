#include "rectangle.h"

rectangle::rectangle(int nx, int ny, int ns, QString nr): x(nx),y(ny),s(ns),name(nr){
    control = false;
    mark = false;
    sniper = false;
    seargeant = false;
    scout = false;
}

