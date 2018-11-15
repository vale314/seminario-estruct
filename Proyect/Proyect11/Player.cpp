#include "Player.h"


Player::Player()
{
    monedas=1000;

    ifstream archivo("items.txt");
       string linea;
       if(!archivo.is_open()){
           cout <<" No se pudo abrir el archivo";
           return;
       }
       while(getline(archivo,linea)){
           Item i(linea);
           productos.push_front(i);
       }
}

void Player::menu()
{
    int opc;
    int iPek;
    do{
        system("cls");
        cout<<"\t\t\tMenu Player"<< endl;
        cout<<menuInfo<<" MenuInfo"<<endl
           <<menuPekemones<<" MenuPekemones"<<endl
           <<menuTienda<<" MenuTienda"<<endl
           <<menuExit << " Salir"<<endl;
        cin>>opc;
        switch (opc) {
        case menuInfo:
            info();
            break;
        case menuPekemones:
            getPekemones(&iPek);
            getPekemon(iPek);
            break;
        case menuTienda:
             menuTiendaFunc();
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
            cout<< i <<"  Pekemon: "<<it->getName()<<endl;
            it++;
            i++;
        }
    }
    system("pause");
}

void Player::getPekemones(int *iPek)
{
    size_t  i=0;

    if(pekemones.empty())
        cout<<"La Lista Esta Vacia"<<endl;
    if(pekemones.size()>0){
        it = pekemones.begin();
        while(i!=pekemones.size()){
            cout<< i <<"  Pekemon: "<<it->getName()<<endl;
            it++;
            i++;
        }
    }
    cin>>*iPek;
    system("pause");
}

void Player::getPekemon(int iPek)
{
    it=pekemones.begin();
    advance(it,iPek);
    it->getMenu();
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

void Player::menuTiendaFunc()
{
    int opc;
    do{
        system("cls");
        cout<<menuTiendaShow<<" showProdructs"<<endl;
        cout<<menuTiendaExit<< " ExitMenu" <<endl;
        cin>>opc;
        switch (opc) {
        case menuTiendaShow:
            menuTiendaShowFunc();
            break;
        case menuTiendaExit:
            break;
        default:
            break;
        }
    }while(opc != menuTiendaExit);
}
void Player::menuTiendaShowFunc(){

    cout<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(15)<<"stock"<< endl;
    for(itP=productos.begin();itP!=productos.end();itP++)
        cout<<*itP;
    system("pause");
}
