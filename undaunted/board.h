#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "rectangle.h"
#include <string>

using namespace std;

class board
{
    vector <rectangle*> R;

public:
    board();
    rectangle& pars(const string& b);

};

#endif // BOARD_H
