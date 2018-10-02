#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int array[]={11,11,11,22,22,22,33,33,33,44,44,44};
    int *l;
    int *u;
    //primer elemento menor a el que busco
    l=lower_bound(array,array+12,33);
    //primer elemento mayor a el que estoy buscando
    u= upper_bound(array,array+12,33);

    if(*l==33)
        cout << "encontrado" << endl;
    else
        cout << "No Existe" <<endl;


    cout << "Inferioir: "<<distance(array,l) << endl<< *l<< endl
        <<"Superior" << distance(array,u) << endl<<*u<<endl;
    return 0;
}





