#ifndef PEKEMON_H
#define PEKEMON_H
#include "Move.h"
#include <list>
#include <string>
#include <iostream>
#include<ostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

class Pekemon
{
public:
    enum types{
       acero=1,
       agua,
       dragon,
       electrico,
       fantasma,
       fuego,
       hada,
       hielo,
       hierba,
       insecto,
       normal,
       oscuro,
       pelea,
       psiquico,
       roca,
       tierra,
       venenoso,
       volador
   };
    Pekemon(types t,string);
    string getName() const;
    void setName(const string &value);

    unsigned int getLevel() const;
    void setLevel(unsigned int value);

    int getHp() const;
    void setHp(int value);

    unsigned int getMaxHp() const;
    void setMaxHp(unsigned int value);

    unsigned int getAttack() const;
    void setAttack(unsigned int value);

    unsigned int getExperience() const;
    void setExperience(unsigned int value);

    void llenarMovimientos();
    string returnTypes();

private:

    types tipo;
    string name;
    unsigned int level;
    int hp;
    unsigned int maxHp;
    unsigned int attack;
    unsigned int experience;
    list<Move> moves;


};

#endif // PEKEMON_H
