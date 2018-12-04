#include "Move.h"

Move::Move(string nameV,unsigned int maxV,unsigned int availableV)
{
    name=nameV;
    max=maxV;
    available=availableV;
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


ostream& operator <<(ostream& os, const Move& obj){
    os << obj.getName() << "|"<<obj.getMax()<<"|"<<obj.getAvailable()<<endl;
    return os;
}
