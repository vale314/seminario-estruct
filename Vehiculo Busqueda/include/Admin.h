#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "ListaEstatica.h"
#include "Vehiculo.h"
#include <algorithm>

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
            BusquedaLineal,
            Ordenar,
            MenuSalir
        };
        void menu();
        void comprar();
        void vender();
        void consultar();
        void busquedaLineal();
        void ordenar();
        bool functionOrdenar(Vehiculo& a, Vehiculo& b);
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
