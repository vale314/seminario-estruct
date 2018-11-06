#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_H
#include <iostream>

using namespace  std;

class Player
{
private:
   string nombre;
   int monedas;
    enum{
        menuInfo=1,
        menuExit
    };
public:
    Player();
    void menu();
    void info();


    string getNombre() const;
    void setNombre(const string &value);
    int getModendas() const;
    void setModendas(int value);
};
#endif // PLAYER_H
