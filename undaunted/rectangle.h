#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
    int n;
    int x;
    int y;
    int s;
    char r;

public:
    rectangle(int nn, int nx, int ny, int ns, char nr);
    friend class board;
};

#endif // RECTANGLE_H
