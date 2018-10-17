#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "ListaEstatica.h"
#include "vehiculo.h"
#include <algorithm>
#include <vector>
#include <string>
#include <fstream> /*Manejar el archivo*/
#include <stdio.h>


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
        void guardar(const Vehiculo& obj);
        void cargar();
        void menu();
        void comprar();
        void vender();
        void consultar();
        void busquedaLineal();
        void ordenar();
        void deleteFile();
        void recargar();
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
