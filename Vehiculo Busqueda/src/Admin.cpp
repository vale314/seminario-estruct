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
        << BusquedaLineal << " Busqueda Lineal" <<endl
        << Ordenar  << " Ordenar"<< endl
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
                busquedaLineal();
            break;
            case 5:
                ordenar();
            break;
            case 6:

            break;

            default:
                cout << "Opcion INCORRECTA" <<endl;
        }
    }while(opcion !=6);
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

void Admin::busquedaLineal(){
    string busqueda;
    bool f;
    int i=0;
    cout << "Ingrese Su Marca "<<endl;
    cin.ignore();
    getline(cin,busqueda);
    while(i<vehiculos._size()){
        if(vehiculos[i].getMarca()==busqueda){
            f=true;
            break;
        }
        f=false;
        i++;
    }
    if(f)
        cout << vehiculos[i]<<endl;
    else
        cout << "No encontrado"<<endl;
    system("pause");
}

bool Admin:: functionOrdenar(Vehiculo& a, Vehiculo& b){
    cout<< "a " << a<<endl << "b " << b<<endl;
    return true;
}
void Admin::ordenar(){
    sort (vehiculos, vehiculos._size(), functionOrdenar());
}

