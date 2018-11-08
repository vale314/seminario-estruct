#include "Pekemon.h"

Pekemon::Pekemon(types t,string nameS)
{
    tipo = t;
    //llenarMovimientos();
    cout<<"Pokemon: "<< t <<endl;

    name=nameS;
    level = 5;
    hp = 15;
    maxHp = 15;
    attack = 10;
    experience = 20;
}

string Pekemon::getName() const
{
    return name;
}

void Pekemon::setName(const string &value)
{
    name = value;
}

unsigned int Pekemon::getLevel() const
{
    return level;
}

void Pekemon::setLevel(unsigned int value)
{
    level = value;
}

int Pekemon::getHp() const
{
    return hp;
}

void Pekemon::setHp(int value)
{
    hp = value;
}

unsigned int Pekemon::getMaxHp() const
{
    return maxHp;
}

void Pekemon::setMaxHp(unsigned int value)
{
    maxHp = value;
}

unsigned int Pekemon::getAttack() const
{
    return attack;
}

void Pekemon::setAttack(unsigned int value)
{
    attack = value;
}

unsigned int Pekemon::getExperience() const
{
    return experience;
}

void Pekemon::setExperience(unsigned int value)
{
    experience = value;
}
