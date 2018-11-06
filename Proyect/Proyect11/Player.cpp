#include "Player.h"


Player::Player()
{
    monedas=1000;
}

void Player::menu()
{
    int opc;
    do{
        cout<<"\t\t\tMenu Player"<< endl;
        cout<<menuInfo<<" MenuInfo"<<endl
           <<menuExit << " Salir"<<endl;
        cin>>opc;
        switch (opc) {
        case menuInfo:
            info();
            break;
        case menuExit:
            cout<<"Gracias"<<endl;
            break;
        default:
            break;
        }

    }while(opc !=menuExit);
}

void Player::info()
{

    cout<<"\t\t Info Player"<< endl;
    cout<<" Nombre: "<< nombre<<endl
       <<" Monedas: "<< monedas<<endl;
    system("pause");
}


string Player::getNombre() const
{
    return nombre;
}

void Player::setNombre(const string &value)
{
    nombre = value;
}

int Player::getModendas() const
{
    return monedas;
}

void Player::setModendas(int value)
{
    monedas = value;
}
