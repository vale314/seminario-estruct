#include "Player.h"


Player::Player()
{
    monedas=1000;

}

void Player::menu()
{
    int opc;
    do{
        system("cls");
        cout<<"\t\t\tMenu Player"<< endl;
        cout<<menuInfo<<" MenuInfo"<<endl
           <<menuPekemones<<" MenuPekemones"<<endl
           <<menuExit << " Salir"<<endl;
        cin>>opc;
        switch (opc) {
        case menuInfo:
            info();
            break;
        case menuPekemones:
            getPekemones();
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

void Player::getPekemones()
{
    size_t  i=0;

    if(pekemones.empty())
        cout<<"La Lista Esta Vacia"<<endl;
    if(pekemones.size()>0){
        it = pekemones.begin();
        while(i!=pekemones.size()){
            cout<<"Pekemon: "<<it->getName()<<endl;
            it++;
            i++;
        }
    }
    system("pause");
}

void Player::setPekemones(const Pekemon &value)
{
    pekemones.push_front(value);
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
