#include <iostream>
#include "ListaEstatica.h"

using namespace std;

int main()
{
    ListaEstatica<int> enteros;
    ListaEstatica<char> simbolos;

    enteros._insert(33);
    enteros._insert(44);
    enteros._insert(59);

    //nos permite agrgar un elemento a la lista de forma normal con la funcion operator habilitas ese operador
    enteros[1]= 99;

    simbolos._insert('A');

    cout << "Enteros empty " << enteros._empty() << endl
         << "Enteros full " << enteros.full() << endl
         << "Enteros Size " << enteros._size() << endl
         <<"Simbolos empty " << simbolos._empty() << endl
         << "Simbolos full " <<simbolos.full() << endl
         << "Simbolos size " << simbolos._size() << endl;

         enteros.print();
         cout<< "Elemento se encontro en " << enteros._find(59) << endl;
         enteros._remove(1);
         enteros.print();

    return 0;
}
