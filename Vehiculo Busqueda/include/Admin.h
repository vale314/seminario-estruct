#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "ListaEstatica.h"
#include "Vehiculo.h"
#include <algorithm>
#include <vector>


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
            BusquedaBinaria,
            MenuSalir
        };
        void menu();
        void comprar();
        void vender();
        void consultar();
        void busquedaLineal();
        void ordenar();
        static bool functionOrdenar( Vehiculo & a,  Vehiculo & b){
            if(a.getMarca() < b.getMarca())
                return true;

            return false;
        }

        static bool functionSearch(Vehiculo &a, Vehiculo & b){

                return true;
            return false;
        }

        void busquedaBinaria();
        struct VehiculoS{
            string marca;
            string desc;
            int anio;
        };

    //inline bool operator< (Vehiculo & c){return  operator< (rhs,lhs);}
    protected:

    private:
        vector <Vehiculo> vehiculos;
        vector <Vehiculo>::iterator low;
        //vector<Vehiculo> vehiculos3;
};

#endif // ADMIN_H
