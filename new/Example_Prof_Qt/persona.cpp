#include <iostream>
#include "persona.h"

}

Persona::Persona(){
    cout <<"Hola Mundo :D" << endl;
}

Persona::~Persona(){
    cout <<"No wa AlV" << endl;
}

string persona:: getNombre() const{
    return nombre;
}

void persona ::setNombre(const string &value){
    nombre= value;
}

void Persona ::setPeso(const string &value){
    peso= value;
}

void Persona ::setNacionalidad(const string &value){
    nacionalidad= value;
}


