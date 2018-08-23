#ifndef MENU_H
#define MENU_H
#include "persona.h"

class Menu
{
    public:
        static const int MAX = 30;
        Menu();
        virtual ~Menu();
        enum Opciones
        {
            OPCION_AGREGAR = 1,
            OPCION_CONSULTAR,
            OPCION_BUSCAR,
            OPCION_SALIR
        };
        /*void agregar();
        void consultar();
        void buscar();*/
        void mostrar();
    protected:

    private:
        Persona persona[MAX];
        int contador;
};

#endif // MENU_H
