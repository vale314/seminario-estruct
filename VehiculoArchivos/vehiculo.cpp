#include "vehiculo.h"

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

string Vehiculo::getMarca() const{
    return marca;
}

int Vehiculo::getModelo(){
    return modelo;
}

ostream& operator <<(ostream& os,const Vehiculo &obj){
    os << obj.marca <<"|"
       << obj.descripcion <<"|"
       << obj.modelo<<endl;
       return os;
}



Vehiculo::Vehiculo(const string &linea){
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    setMarca(aux);
    getline(stream,aux,'|');
    setDescripcion(aux);
    getline(stream,aux, '|');
    setModelo(std::stoi(aux));
}
