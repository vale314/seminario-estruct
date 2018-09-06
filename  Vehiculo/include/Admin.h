#ifndef ADMIN_H
#define ADMIN_H
#include "ListaEstatica.h"

class Admin
{
    public:
        Admin();
        virtual ~Admin();
        typedef struct Vehiculo{
            string marca;
            int modelo;
            string descripcion;
        };
        void comprar();
        void vender();
        void consultar();

    protected:

    private:
        ListaEstatica<Vehiculo> Vehiculo;

};

#endif // ADMIN_H
