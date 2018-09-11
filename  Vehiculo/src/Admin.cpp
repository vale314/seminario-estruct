#include "Admin.h"
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

Admin::Admin()
{
    //ctor
}

Admin::~Admin()
{
    //dtor
}

void Admin::menu(){
    int opcion;
    do{
    system("cls");
    cout << MenuComprar << " Comprar" << endl
        << MenuVender << " Vender" <<endl
        << MenuConsultar << " Consultar" <<endl
        << MenuSalir << " Salir" <<endl;
    cin>>opcion;
        switch(opcion){
            case 1:
                comprar();
            break;

            case 2:
                vender();
            break;

            case 3:
                consultar();
            break;

            case 4:
            break;

            default:
                cout << "Opcion INCORRECTA" <<endl;
        }
    }while(opcion !=4 );
}


void Admin::comprar(){
    Vehiculo vehiculo1;
    VehiculoS vehiculoS;

    cin.ignore();
    cout << "Ingrese la marca" << endl;
    getline(cin,vehiculoS.marca);
    cout << "Ingrese la Descipcion" << endl;
    getline(cin,vehiculoS.desc);
    cout << "Ingrese la anio" << endl;
    cin >> vehiculoS.anio;

    vehiculo1.setMarca(vehiculoS.marca);
    vehiculo1.setDescripcion(vehiculoS.desc);
    vehiculo1.setModelo(vehiculoS.anio);

    vehiculos._insert(vehiculo1);
}

void Admin::consultar(){
    for(int i=0; i<vehiculos._size();i++){
        cout << vehiculos[i]<<endl;
    }
    system("pause");
}

void Admin::vender(){
    int num;
    cout << "Ingrese La Posicion Que Desea Quitar " << endl;
    cin >> num;
    vehiculos._remove(num);
}
