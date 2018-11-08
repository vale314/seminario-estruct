#include "Pekemon.h"

Pekemon::Pekemon(types t,string nameS)
{
    tipo = t;
    llenarMovimientos();
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

void Pekemon::llenarMovimientos()
{

  ifstream archivo("tipos/"+returnTypes()+".txt");
  string linea;
  if(!archivo.is_open()){
      cout <<" No se pudo abrir el archivo";
      system("pause");
      return;
  }
  while(getline(archivo,linea)){
      string aux;
      stringstream stream(linea);
      getline(stream,aux,' ');
      Move moveAux(aux,10,10);
      moves.push_front(moveAux);
      cout<<aux<<endl;
  }
  system("pause");
}

string Pekemon::returnTypes()
{
    switch (tipo) {
    case acero:
        return("acero");
        break;
    case agua:
        return("agua");
        break;
    case dragon:
        return("dragon");
        break;
    case electrico:
        return("electrico");
        break;
    case fantasma:
        return("fantasma");
        break;
    case fuego:
        return("fuego");
        break;
    case hada:
        return("hada");
        break;
    case hielo:
        return("hielo");
        break;
    case hierba:
        return("hierba");
        break;
    case insecto:
        return("insecto");
        break;
    case normal:
        return("normal");
        break;
    case oscuro:
        return("oscuro");
        break;
    case pelea:
        return("pelea");
        break;
    case psiquico:
        return("psiquico");
        break;
    case roca:
        return("roca");
        break;
    case tierra:
        return("tierra");
        break;
    case venenoso:
        return("venenoso");
        break;
    case volador:
        return("volador");
        break;
    default:
        return("normal");
        break;
    }
}
