#include "Persona.h"

Persona::Persona()
{
    cout<<"Holaaaaaa enfermera :D"<<endl;
}
Persona::~Persona()
{
    cout<<"No me quiero ir sr. programador :'c"<<endl;
}

void Persona::setNombre(const string &value)
{
    nombre=value;
}

string Persona::getNombre()const
{
    return nombre;
}

void Persona::setNacionalidad(const string &value)
{
    nacionalidad=value;
}

string Persona::getNacionalidad()const
{
    return nacionalidad;
}

void Persona::setPeso(const float &value)
{
    peso=value;
}

float Persona::getPeso()const
{
    return peso;
}
