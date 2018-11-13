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
   list<Pekemon> pekemones;
   list<Pekemon>::iterator it;

    enum{
        menuInfo=1,
        menuPekemones,
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

    void getPekemones();
    void getPekemones(int *);
    void getPekemon(int);
    void setPekemones(const Pekemon &value);
    string getNombre() const;
    void setNombre(const string &value);
    int getModendas() const;
    void setModendas(int value);

};
#endif // PLAYER_H
