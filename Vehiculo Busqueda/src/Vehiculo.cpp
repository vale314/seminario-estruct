#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    //ctor
}

Vehiculo::~Vehiculo()
{
    //dtor
}
void Vehiculo:: setMarca(string marca){
    this->marca = marca;
}

void Vehiculo::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

void Vehiculo::setModelo(int modelo){
    this->modelo = modelo;
}

string Vehiculo::getDescripcion(){
    return descripcion;
}

string Vehiculo::getMarca(){
    return marca;
}

int Vehiculo::getModelo(){
    return modelo;
}

ostream& operator <<(ostream& os,const Vehiculo &obj){
    os <<"Marca: " << obj.marca << endl
       << "Modelo: " << obj.modelo <<endl
       << "Descripcion: " <<obj.descripcion;

       return os;
}

