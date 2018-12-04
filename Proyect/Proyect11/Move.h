#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Move
{
public:
    Move(string nameV,unsigned int maxV,unsigned int avalibleV);
    Move(const string &linea);
    void showMoves();
    string getName() const;

    unsigned int getMax() const;

    unsigned int getAvailable() const;

    void setName(const string &value);

    void setMax(unsigned int value);

    void setAvailable(unsigned int value);

private:
    string name;
    unsigned int max; //Cantidad máxima de veces que se puede realizar el movimiento
    unsigned int available;
    friend ostream& operator <<(ostream& os, const Move& obj);
};

#endif // MOVE_H
