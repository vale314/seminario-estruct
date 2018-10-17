#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <ListaEstatica.h>
#include <sstream>
#include<ostream>

using namespace std;


class Vehiculo
{
    public:
        Vehiculo();
        Vehiculo(const string& linea);
        virtual ~Vehiculo();
        void setMarca(string marca);
        void setModelo(int modelo);
        void setDescripcion(string descripcion);

        int getModelo();
        string getMarca() const;
        string getDescripcion();

        friend ostream& operator <<(ostream& os,const Vehiculo &obj);
        friend bool operator< (const Vehiculo& lhs, const Vehiculo& rhs)
        {
           return lhs.getMarca() < rhs.getMarca();
        }
    protected:

    private:
        string marca;
        int modelo;
        string descripcion;

};

#endif // VEHICULO_H
