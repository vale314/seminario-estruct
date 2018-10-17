#include "admin.h"
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

Admin::Admin()
{
    cargar();
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
        << BusquedaBinaria << " Busqueda Binaria" <<endl
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
                busquedaBinaria();
            break;
            case 7:

            break;
            default:
                cout << "Opcion INCORRECTA" <<endl;
        }
    }while(opcion !=7);
}

void Admin::guardar(const Vehiculo& obj){
    //(nameFile,modo de apertura)
    ofstream archivo("album.txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivo << obj;
    archivo.close();
}

void Admin::cargar(){
    ifstream archivo("album.txt");
    string linea;
    if(!archivo.is_open()){
        cout <<" No se pudo abrir el archivo";
        return;
    }
    while(getline(archivo,linea)){
        Vehiculo s(linea);
        vehiculos.push_back(s);
    }
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

    vehiculos.push_back(vehiculo1);

    guardar(vehiculo1);
}

void Admin::consultar(){
    for(int i =0; i < vehiculos.size();i++){
        cout << vehiculos[i] <<endl;
    }
    system("pause");
}

void Admin::deleteFile(){
    if( remove( "album.txt" ) != 0 )
        perror( "Error deleting file" );
}

void Admin::recargar(){
    for(size_t i=0;i<vehiculos.size();i++){
        guardar(vehiculos[i]);
    }
}


void Admin::vender(){
    int num;
    cout << "Ingrese La Posicion Que Desea Quitar " << endl;
    cin >> num;
    if(num<vehiculos.size()){
        vehiculos.erase(vehiculos.begin()+num);
        deleteFile();
        recargar();
        return ;
    }
    cout << "Posicion no se encuentra" <<endl;
    system("pause");
}

void Admin::busquedaLineal(){
    string busqueda;
    bool f;
    int i=0;
    cout << "Ingrese Su Marca "<<endl;
    cin.ignore();
    getline(cin,busqueda);
    while(i<vehiculos.size()){
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

void Admin::ordenar(){
    std::sort (vehiculos.begin(), vehiculos.end(),functionOrdenar);
    deleteFile();
    recargar();
    return ;
}

void Admin:: busquedaBinaria(){
    ordenar();
    string busqueda;
    Vehiculo vehiculo1;
    cout << "Ingrese Su Marca "<<endl;
    cin.ignore();
    getline(cin,busqueda);
    vehiculo1.setMarca(busqueda);
    //Vehiculo *lower_bounder;
    low=std::lower_bound(vehiculos.begin(),vehiculos.end(),vehiculo1);
    //cout <<  *lower_bounder << endl;
    if(low.base()->getMarca()!=busqueda){
        cout<< "No Encontrado "<<endl;
        system("pause");
        return;
    }
    cout<<*low.base()<<endl;
    system("pause");
}
