#ifndef MOVE_H
#define MOVE_H
#include <string>

using namespace std;

class Move
{
public:
    Move();
private:
    string name;
    unsigned int max; //Cantidad máxima de veces que se puede realizar el movimiento
    unsigned int available;
};

#endif // MOVE_H
