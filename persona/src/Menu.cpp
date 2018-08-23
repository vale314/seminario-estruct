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
        cin.ignore();
        switch(opc){

        case OPCION_AGREGAR:
            agregar();
            break;
        case OPCION_BUSCAR:
            buscar();
            break;
        case OPCION_CONSULTAR:
            consultar();
            break;
        case OPCION_SALIR:
            cout << "Nos vemos Pronto" << endl;
            break;
        default:
            break;
        }
    }while(opc != OPCION_SALIR);
}

void Menu::agregar(){

    if(contador < MAX)
    {
        Persona p;
        string nombre;
        string nacionalidad;
        float peso;


        cout << "Ingresa el nombre" <<endl;
        getline(cin,nombre);
        cout << "Ingresa la nacionalidad:" <<endl;
        getline(cin,nacionalidad);
        cout << "Ingresa El Peso" << endl;
        cin >> peso;

        p.setNombre(nombre);
        p.setNacionalidad(nacionalidad);
        p.setPeso(peso);

        personas[contador] = p;
        contador++;
    }else{
        cout << "Contador Lleno" << endl;
    }
}


void Menu::buscar(){
    string nombre;
    cout<< "Ingresa el nombre a buscar: "<<endl;
    getline(cin,nombre);
    for(int i=0; i < contador ; i++){

        if(personas[i].getNombre() == nombre)
        {
            cout << "Nombre " << personas[i].getNombre() <<endl
         << "Nacionalidad " << personas[i].getNacionalidad() << endl
         << "Peso " << personas[i].getPeso() << endl;
        }else{
            cout << "No se encontro" <<endl;
        }
    }
}


void Menu::consultar(){

    for(int i=0; i < contador; i++){
        cout << "Nombre " << personas[i].getNombre() <<endl
         << "Nacionalidad " << personas[i].getNacionalidad() << endl
         << "Peso " << personas[i].getPeso() << endl;
    }
}
