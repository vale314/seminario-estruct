#include "Menu.h"

Menu::Menu()
{
    contador = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu:: mostrar(){
    int  opc;
    do{
        cout << "\t Menu" << endl
        <<OPCION_AGREGAR<< "Agregar" <<endl
        <<OPCION_BUSCAR<< "Buscar" << endl
        <<OPCION_CONSULTAR<< "Consultar" <<endl
        <<OPCION_SALIR<< "Salir" << endl;
        cin >> opc;
    }while(opc != OPCION_SALIR);
}
