#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona
{
public:
    Persona();
    ~Persona();

    void setNombre(const string &value);
    string getNombre() const;

    void setNacionalidad(const string &value);
    string getNacionalidad() const;

    void setPeso(const float &value);
    float getPeso() const;


private:
    string nombre;
    string nacionalidad;
    float peso;
};

#endif // PERSONA_H
