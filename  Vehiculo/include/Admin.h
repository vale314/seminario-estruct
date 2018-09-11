#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "ListaEstatica.h"
#include "Vehiculo.h"

using namespace std;

class Admin
{
    public:
        Admin();
        virtual ~Admin();
        enum Menu{
            MenuComprar=1,
            MenuVender,
            MenuConsultar,
            MenuSalir
        };
        void menu();
        void comprar();
        void vender();
        void consultar();
        struct VehiculoS{
            string marca;
            string desc;
            int anio;
        };
    protected:

    private:
        ListaEstatica<Vehiculo> vehiculos;
};

#endif // ADMIN_H
