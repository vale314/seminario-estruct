#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <ListaEstatica.h>

using namespace std;


class Vehiculo
{
    public:
        Vehiculo();
        virtual ~Vehiculo();
        void setMarca(string marca);
        void setModelo(int modelo);
        void setDescripcion(string descripcion);

        int getModelo();
        string getMarca();
        string getDescripcion();

    protected:

    private:
        string marca;
        int modelo;
        string descripcion;

};

#endif // VEHICULO_H
