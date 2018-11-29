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
    //cargar();
}

Player::Player(const string &linea)
{
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    setNombre(aux);
    getline(stream,aux,'|');
    setModendas(stoi(aux));
    cargar();
    cargarTienda();
}

void Player::cargar()
{

    ifstream archivoB("./Backpack/"+nombre+".txt");
    string lineaB;
    if(!archivoB.is_open()){
//        cout <<" No se pudo abrir el archivo";
        return;
    }

    while(getline(archivoB,lineaB)){

        Item r(lineaB);
        backpack.push_back(r);
    }

        ifstream archivo("./Pekemones/"+nombre+".txt");
        string linea;
        if(!archivo.is_open()){
            return;
        }
        while(getline(archivo,linea)){
            Pekemon s(linea);


            pekemones.push_back(s);
        }


}

void Player::actualizarPlayer()
{
    const string var = "./Player/"+nombre+".txt";
    char * cstr = new char [var.length()+1];
    strcpy(cstr,var.c_str());
    remove(cstr);

    ofstream archivo("./Player/"+nombre+".txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivo <<nombre+"|"+to_string (monedas);
    archivo.close();

}

void Player::cargarTienda()
{
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

void Player::ActualizarTienda()
{
    if(!backpack.empty()){

        for(itB=backpack.begin();itB!=backpack.end();itB++){
            if(searchTienda()){
                cout<<itB->getStock()<<endl;
                itP->setStockV(itB->getStock());
            }
        }
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
    int opc,opcT;
    do{
        ActualizarTienda();
        system("cls");
        cout<<menuTiendaShow<<" shopProdructs"<<endl;
        cout<<menuTiendaSell<<" sellProdructs"<<endl;
        cout<<menuTiendaShowBack<< " menuTiendaShowBack"<<endl;
        cout<<menuTiendaExit<< " ExitMenu" <<endl;
        cin>>opc;
        switch (opc) {
        case menuTiendaShow:
            menuTiendaShowFunc(&opcT);
            menuTiendaComprar(&opcT);
            break;
        case menuTiendaSell:
            showBackpack(&opcT);
            sellProducts(&opcT);
            break;
        case menuTiendaShowBack:
            showBackpack();
            break;
        case menuTiendaExit:
            break;
        default:
            break;
        }
    }while(opc != menuTiendaExit);
}
void Player::menuTiendaShowFunc(){
    int i=0;
    cout<<setw(15)<<"#"<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(25)<<"stock"<< endl;
    for(itP=productos.begin();itP!=productos.end();itP++){
        cout<<setw(15)<<i;
        itP->printf();
        i++;
    }
    system("pause");
}

void Player::menuTiendaShowFunc(int *opc){
    int i=0;
    cout<<setw(15)<<"#"<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(25)<<"stock"<< endl;
    for(itP=productos.begin();itP!=productos.end();itP++){
        cout<<setw(15)<<i;
        itP->printf();
        i++;
    }
    cout<<"Seleccione una Opcion:"<<endl;
    cin>>*opc;
    system("pause");
}

void Player::menuTiendaComprar(int *opc){
    int can;
    itP=productos.begin();
    itB=backpack.begin();
    for(int i=0;i<*opc;i++){
        itP++;
    }
    cout<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(25)<<"stock"<< endl;
    itP->printf();
    cout<<"Cantidad Que Desea Comprar"<<endl;
    cin>>can;

    //funcition search


        if(monedas>=(itP->getPrice()*can)){
            monedas=monedas-itP->getPrice()*can;
            if(!searchBackpack()){
                itP->shopStock(can);
                backpack.push_front(*itP);
            }else{
                itP->shopStock(can);
                itB->shopStock(can);
            }
            for(itB=backpack.begin();itB!=backpack.end();itB++){
               itB->printf();
            }
            actualizarPlayer();
        }else
            cout<<"No tienes Suficientes Creditos"<<endl;
    system("pause");
    guardarBackpack();
}

bool Player::searchBackpack()
{
   bool search;
   search=false;
   itB=backpack.begin();
   for(itB=backpack.begin();itB!=backpack.end();itB++){
       if(itB->getName()==itP->getName()){
           return true;
       }
       search=false;
   }
   return search;
}



void Player::showBackpack(int *opc)
{
    int i=0;
    cout<<setw(15)<<"#"<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(25)<<"stock"<< endl;
    for(itB=backpack.begin();itB!=backpack.end();itB++){

        if(itB->getStock()){
            cout<<setw(15)<<i;
            itB->printf();
        }
        i++;
    }
    if(backpack.size()>0){
        cout<<"Seleccione una Opcion:"<<endl;
        cin>>*opc;
    }else{
        *opc=-1;
    }
    system("pause");
}

void Player::showBackpack()
{
    int i=0;
    cout<<setw(15)<<"#"<<setw(15)<< "Name"<<setw(15)<<"Price"<<setw(15)<<"value"<<setw(15)<<"Descriptions"<<setw(25)<<"stock"<< endl;
    for(itB=backpack.begin();itB!=backpack.end();itB++){

        if(itB->getStock()){
            cout<<setw(15)<<i;
            itB->printf();
        }
        i++;
    }
    system("pause");
}



void Player::guardar()
{
    deleteAllP();
    ofstream archivo("./Pekemones/"+getNombre()+".txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    size_t  i=0;

    if(pekemones.empty())
        cout<<"La Lista Esta Vacia"<<endl;
    if(pekemones.size()>0){
        it = pekemones.begin();
        while(i!=pekemones.size()){
            archivo << *it;
            it++;
            i++;
        }
    }

    archivo.close();
    guardarBackpack();
}

void Player::deleteAll(){

    string file="./Backpack/";
    file.append(nombre);
    file.append(".txt");
    const char *c = file.c_str();
    remove(c);
}

void Player::deleteAllP()
{
    string file="./Pekemones/";
    file.append(nombre);
    file.append(".txt");
    const char *c = file.c_str();
    remove(c);
}

void Player::guardarBackpack()
{
    deleteAll();
    ofstream archivo("./Backpack/"+getNombre()+".txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    size_t  i=0;

    if(backpack.size()>0){
        for(itP=backpack.begin();itP!=backpack.end();itP++){
            archivo<<*itP;
        }
    }

    archivo.close();
}

ostream& operator <<(ostream& os, const Player& obj){
    os << obj.getNombre() << "|" << obj.getModendas() <<endl;
    return os;
}


void Player::sellProducts(int *opc)
{
    int can;
    if(*opc==-1)
        throw invalid_argument("No Hay Productos");
    itB=backpack.begin();
    for(int i=0;i<*opc;i++){
        itB++;
    }
    cout<<"Productos que desea Vender"<<endl;
    cin>>can;
    if(can<=itB->getStock()){
        itB->setStock(can);
        if(itB->getStock()==0)
            backpack.erase(itB);
        monedas=monedas+((itB->getPrice()*can)/2);
        if(searchTienda()){
            itP->setStock(can);
//            if(itP->getStock()==0)
//                productos.erase(itP);
        }
        actualizarPlayer();
    }else{
        cout<<"No Se Puede Vender" << endl;
    }

    system("pause");
    guardarBackpack();
}


bool Player::searchTienda()
{
    bool search;
    search=false;
    itP=productos.begin();
    for(itP=productos.begin();itP!=productos.end();itP++){
        if(itP->getName()==itB->getName()){
            return true;
        }
        search=false;
    }
    return search;
}

