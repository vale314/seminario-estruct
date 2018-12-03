#include "Pekemon.h"

Pekemon::Pekemon()
{
    tipo = normal;
    llenarMovimientos();
    name="Nombre";
    level = 5;
    hp = 15;
    maxHp = 15;
    attack = 10;
    experience = 20;
}

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

Pekemon::Pekemon(types t,string nameS,unsigned int levelP,int hpP,unsigned int maxHpP,unsigned int attackP, unsigned int exp)
{
    tipo = t;
    llenarMovimientos();
    cout<<"Pokemon: "<< t <<endl;
    name=nameS;
    level = levelP;
    hp = hpP;
    maxHp = maxHpP;
    attack = attackP;
    experience = exp;
}

Pekemon::Pekemon(const string &linea)
{
        string aux;
        stringstream stream(linea);

        getline(stream,aux, '|');
        setName(aux);
        getline(stream,aux, '|');
        setTipo(returnTypes(stoi(aux)));
        getline(stream,aux, '|');
        setLevel(stoi(aux));
        getline(stream,aux, '|');
        setHp(stoi(aux));
        getline(stream,aux, '|');
        setMaxHp(stoi(aux));
        getline(stream,aux, '|');
        setAttack(stoi(aux));
        getline(stream,aux, '|');
        setExperience(stoi(aux));
}

string Pekemon::getName() const
{
    return name;
}

void Pekemon::setName(const string &value)
{
    name = value;
}

Pekemon::types Pekemon::returnTypes(int tipo)
{
    switch (tipo) {
    case acero:
        return acero;

    case agua:
        return agua;

    case dragon:
        return dragon;

    case electrico:
        return electrico;

    case fantasma:
        return fantasma;

    case fuego:
        return fuego;

    case hada:
        return hada;

    case hielo:
        return hielo;

    case hierba:
        return hierba;

    case insecto:
        return insecto;

    case normal:
        return normal;

    case oscuro:
        return oscuro;

    case pelea:
        return pelea;

    case psiquico:
        return psiquico;

    case roca:
        return roca;

    case tierra:
        return tierra;

    case venenoso:
        return venenoso;

    case volador:
        return volador;

    default:
        return normal;

    }
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
  cout<<returnTypes()<<endl;
  string linea;
  if(!archivo.is_open()){
      cout <<" No se pudo abrir el archivo";
      return;
  }
  while(getline(archivo,linea)){
      string aux;
      stringstream stream(linea);
      getline(stream,aux,' ');
      Move moveAux(aux,10,10);
      moves.push_front(moveAux);
  }
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

void Pekemon::getMenu()
{
    size_t i;
    int showAB=0;
    cout<<"Tipo: "<<tipo<<endl
        <<"Name: "<<name<<endl
        <<"Level: "<<level<<endl
        <<"Hp: "<<hp<<endl
        <<"maxHp:"<<maxHp<<endl
        <<"Atack: "<<attack<<endl
        <<"Experience: "<<experience<<endl;
    cout<<"0 Regreasar 1 Mostrar Ataques "<<endl;
    cin>>showAB;
    if(showAB==1){
        for (it = moves.begin(); it != moves.end(); ++it){
            it->showMoves();
        }
    }
    system("pause");
}

void Pekemon::setTipo(const Pekemon::types &value)
{
    tipo=value;
}

Pekemon &Pekemon::operator=(const Pekemon &pekemon)
{
    tipo = normal;
    llenarMovimientos();
    name=pekemon.getName();
    level = pekemon.getLevel();
    hp = pekemon.getHp();
    maxHp = pekemon.maxHp;
    attack = pekemon.getAttack();
    experience = pekemon.getExperience();
    return *this;
}

ostream& operator <<(ostream& os, const Pekemon& obj){
    os << obj.name << "|"<<obj.tipo<<"|"<<obj.level<<"|"<<obj.hp<<"|"<<obj.maxHp<<"|"<<obj.attack<<"|"<<obj.experience<<endl;
    return os;
}
