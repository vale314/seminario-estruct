#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int array[]={1,3,5,7,9,11};
    //apuntador para almacenar el resultado de la busqueda
    int *p;

    //busqueda secuencial
    //find(inicio,  hasta que posicion, elemento a  buscar  )
    p = find(array,array+6,7);

    //si no se encntra en el arrelog se manda un elementos o posiciopn mas alta de la que tiene osea 7
    if(p !=array+6)
    {
        cout << *p << "Se ecuantra en el arreglo" << endl
            //distance le mandamos el arreglo y la poscion en que lo encontro
            << "y esta en la posicion "<<distance(array,p)<<endl;

    }
    else{
        cout << "El elemento no se encuentra"<< endl;
    }
    return 0;
}


