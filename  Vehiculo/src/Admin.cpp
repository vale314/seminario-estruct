#include "Admin.h"

Admin::Admin()
{
    //ctor
}

Admin::~Admin()
{
    //dtor
}


void Admin::comprar(){
    Vehiculo vehiculo;
    cout << "Marca de auto" << endl;
    cin >> vehiculo.marca
    cout << "Marca de modelo" << endl;
    cin >> vehiculo.modelo;
    cout << "Marca de description" << endl;
    cin >> vehiculo.descripcion;

}

void Admin::consultar(){
}

void Admin::vender(){
}
