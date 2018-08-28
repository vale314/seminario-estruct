#include "Automovil.h"
#include <iostream>

Automovil::Automovil()
{
   marca="";
   modelo=0;
   velocidad=0.0;
   estado=false;
   gasolina=2;
}

Automovil::~Automovil()
{
    //dtor
}

void Automovil::setMarca(string marca){
}
void Automovil::setVelocidad(float velocidad){
    this->velocidad = velocidad;
}
void Automovil::setModelo(int modelo){
}
void Automovil::setEstado(bool estado){
    this->estado=estado;
}
void Automovil::setGasolina(float gasolina){
    this->gasolina=gasolina;
}

void Automovil::setMenosGasolina(float gasolina){
    this->gasolina = this->gasolina-gasolina;
}

void Automovil::setMasVelociadad(float velocidad){
    this->velocidad = this -> velocidad+velocidad;
}

void Automovil::setMenosVelocidad(float velocidad){
    this->velocidad = this -> velocidad-velocidad;
}

string Automovil::getMarca(){
}
int Automovil::getModelo(){
}
float Automovil::getVelocidad(){
    return this->velocidad;
}
bool Automovil::getEstado(){
    return this->estado;
}
float Automovil::getGasolina(){
    return this->gasolina;
}
