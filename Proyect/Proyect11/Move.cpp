#include "Move.h"

Move::Move(string nameV,unsigned int maxV,unsigned int availableV)
{
    name=nameV;
    max=maxV;
    available=availableV;
}

Move::Move(const string &linea)
{
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    setName(aux);
    getline(stream,aux, '|');
    setMax(stoi(aux));
    getline(stream,aux, '|');
    setAvailable(stoi(aux));

}

void Move::showMoves()
{
    cout<<"name: "<<name<<endl
        <<"Max: "<<max<<endl
        <<"available: "<<available<<endl;
}

string Move::getName() const
{
    return name;
}

unsigned int Move::getMax() const
{
    return max;
}

unsigned int Move::getAvailable() const
{
    return available;
}

void Move::setName(const string &value)
{
    name = value;
}

void Move::setMax(unsigned int value)
{
    max = value;
}

void Move::setAvailable(unsigned int value)
{
    available = value;
}


ostream& operator <<(ostream& os, const Move& obj){
    os << obj.getName() << "|"<<obj.getMax()<<"|"<<obj.getAvailable()<<endl;
    return os;
}
