#include <iostream>
#include "Persona.h"

using namespace std;

int main()
{
    Persona visitante;
    visitante.setNombre("Don Pepe y los Globos");
    visitante.setNacionalidad("Memejicana");
    visitante.setPeso(72.38);
    cout<<"Datos:"<<endl<<endl
        <<"Nombre: "<<visitante.getNombre()<<endl
        <<"Nacionalidad: "<<visitante.getNacionalidad()<<endl
        <<"Peso: "<<visitante.getPeso()<<"kg."<<endl<<endl;
    return 0;
}

/*



*/
