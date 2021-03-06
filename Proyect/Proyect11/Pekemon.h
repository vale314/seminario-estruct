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
    Pekemon();
    Pekemon(types t,string);
    Pekemon(const string &linea);
    Pekemon(types t,string nameS,unsigned int levelP,int hpP,unsigned int maxHpP,unsigned int attackP, unsigned int exp);

    string getName() const;
    void setName(const string &value);
    virtual types returnTypes(int tipo);
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

    void getMenu();
    void setTipo(const types &value);
    Pekemon& operator= (const Pekemon &pekemon);


    void guardar(string);
    void guardarNombres(string);
    void cargar(string);
    void cargarNombres(string);
    void leerString(const string &);


private:

    types tipo;
    string name;
    unsigned int level;
    int hp;
    unsigned int maxHp;
    unsigned int attack;
    unsigned int experience;
    list<Move> moves;
    list<Move>::iterator it;
    list<string> movesNames;
    list<string>::iterator itMovN;
    friend ostream& operator <<(ostream& os, const Pekemon& obj);

};

#endif // PEKEMON_H
