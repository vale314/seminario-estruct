#include "player.h"


Player::Player()
{
    modenas=1000;
}

void Player::menu()
{
    int opc;
    Console c;
    do{
        c.clearScreen();
        cout<<"\t\t\tMenu Player"<< endl;
        cout<<menuInfo<<" MenuInfo"<<endl
           <<menuExit << " Salir"<<endl;
        cin>>opc;
        switch (opc) {
        case menuInfo:
            info();
            break;
        case menuExit:
            cout<<"Gracias"<<endl<<"Desarollador Valentine"<<endl;
            break;
        default:
            break;
        }

    }while(op !=menuExit);
}

void Player::info()
{
    c.clearScreen();
    cout<<"\t\t\Info Player"<< endl;
    cout<<" Nombre: "<< nombre<<endl
       <<" Monedas: "<< modendas<<endl;
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
    return modendas;
}

void Player::setModendas(int value)
{
    modendas = value;
}
