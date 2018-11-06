#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_H
#include <iostream>
#include <list>
#include <Pekemon.h>

using namespace  std;

class Player
{
private:
   string nombre;
   int monedas;
   list<Pekemon> pekemon;

    enum{
        menuInfo=1,
        menuExit
    };

    enum{
        Bulbasaur=1,
        Squirtle,
        Charizard,
        Pikachu
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
