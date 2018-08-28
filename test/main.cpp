#include <iostream>

using namespace std;

class funcion{
private:
    string funcion;

public:
    void agregar_now(string _funcion){
    funcion=_funcion;

    }

    void mostrar_now(){
                 cout<<"Nombre De La Funcion:"<<funcion<<endl;
    }
};



class cliente{
private:
    int num_entradas;

public:
    void agregar_cliente(int x){

    num_entradas=x;
    }


    void mostrar_cliente(){
    cout<<"Numero De Entradas:"<<num_entradas<<endl;

    }
};


class nombre: public funcion,public cliente{
private:
    string nombre;

public:
    void agregar_noe(string _now,int x,string _funcion){
    nombre=_nombre;


    }

    void mostrar_now(){
        cout<<"Nombre Del Cliente:"<<nombre<<endl;
        mostrar_now();
        mostrar_cliente();
    }
};

int main()
{
    cliente a;
    a.agregar_cliente("Juanito",7,"Predator");
    a.mostrar_cliente();
    return 0;
}
