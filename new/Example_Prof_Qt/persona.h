#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
public:
    persona();
    ~Persona();
            void setNombre(const string &value);
            string getNombre() const;

        private:
            string nombre;
            float peso;
            string nacionalidad;
};

#endif // PERSONA_H
