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
