#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> intVector;
    list<int> intList;

    for(unsigned int i=0;i<10;i++){
        intVector.push_back(i);
    }
    //intVector.at(5) = 33;
    intVector[5] =33;
    sort(intVector.begin(),intVector.end());
    for(unsigned int i=0; i<intVector.size(); i++)
        cout<< "intVector.at(" <<i<<")" <<intVector.at(i) <<endl
             <<"intVector[" << i << " =" << intVector[i] <<endl;

    //[i] podemos modificasr el elemento. (i) no podemos modificar el elemento es un (constante)

    for(unsigned int i=0; i<10;i++)
        intList.push_back(i*10);
    intList.push_front(55);

    list<int>::iterator it = intList.begin();
    //recorre a it 7 posiciones
    advance(it,7);

    intList.insert(it,77);
    intList.sort();
    for(it=intList.begin(); it != intList.end();it++)
        cout <<*it<< endl;
    return 0;
}
