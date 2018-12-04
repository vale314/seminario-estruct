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

void Player::menuExploreF()
{
    int opc = rand()%99;

      switch (opc) {
        case menuExploreNadaInicio ... menuExploreNadaFin:
          exploreNada();
          break;
        case menuExploreDineroInicio ... menuExploreDineroFin:
          exploreDinero();
          break;
        case menuExploreEncuentroInicio ... menuExploreEncuentroFin:
          exploreEncuentro();
          break;
        default:
            break;
      }
}

void Player::exploreNada()
{
     system("cls");
     cout<<"No ha pasado nada"<<endl;
     system("pause");
}

void Player::exploreDinero()
{
    system("cls");
    int opc = rand()% 1000 +1;
    cout<<"Te Encontraste: "<<opc<<endl;
    system("pause");
    setModendas(monedas+opc);
}

double Player::RandNum(double min, double max)
{
    return min + (max - min) * ((double)rand()
                                / (double)RAND_MAX);
}

int Player::RandInt(int min, int max)
{
    return (int)RandNum((double)min + 0.000001,
                           (double)max + 0.999999);
}

void Player::exploreEncuentro()
{
    system("cls");
    itPActual=pekemones.begin();
    cout<<"Te Encontraste Un Pokemon"<<endl;
    //Falta pekemon random function

    const int newLevel = RandInt(itPActual->getLevel()-2,itPActual->getLevel()+1);
    const unsigned int newMaxHp = RandInt(itPActual->getMaxHp()-2,itPActual->getMaxHp()+1);
    const int newHp = newMaxHp;
    const unsigned  int newAttack = RandInt(itPActual->getAttack()-2,itPActual->getAttack()+1);
    const unsigned int newExp = RandInt(itPActual->getExperience()-2,itPActual->getExperience()+1);
    Pekemon auxPek1(Pekemon::types::normal,"Pikachu",newLevel,newHp,newMaxHp,newAttack,newExp);
    auxPek=auxPek1;

    cout<<"Su nombre es: "<<auxPek.getName()<<endl
        <<"Su nivel es: "<< auxPek.getLevel()<<endl
        <<"Su Hp es: "<< auxPek.getHp()<<endl
        <<"Su Attack es: "<< auxPek.getAttack()<<endl
        <<"Su Experiencia es"<< auxPek.getExperience()<<endl;

    bool ocultar;
    ocultar=false;
    bool tienesVida;
    tienesVida=false;
    unsigned int opc;
    bool cambio;
    cambio=true;
    do{
        tienesVida=validarHpTu();
        if(!ocultar&&tienesVida){
           cout<<"Cambiar Pekemon: "<<menuEncuentroCambiar<<endl
               <<"Selecionar Item: "<<menuEncuentroItem<<endl
               <<"Run: "<<menuEncuentroRun<<endl
               <<"Pelea: "<<menuEncuentroPelea<<endl;
        }else{
            cout<<"Cambiar Pekemon: "<<menuEncuentroCambiar<<endl
                <<"Selecionar Item: "<<menuEncuentroItem<<endl
                <<"Run: "<<menuEncuentroRun<<endl;
        }
        cin>>opc;
        switch (opc) {
        case menuEncuentroPelea:
               if(validarHpEnemigo())
                  ocultar=encuentroPelea();
            break;
        case menuEncuentroItem:
                encuentroItem();
            break;
        case menuEncuentroCambiar:
                cambio=encuentroCambiar();
            break;
        case menuEncuentroRun:
                encuentroRun();
                return;
        default:
            cout<<"Selecciona una opcion correcta"<<endl;
            system("pause");
            break;
        }
    }while((opc!=menuEncuentroRun)||!cambio||!validarWin());
    if(validarWin()||!cambio)
        pekemonCentroMenu();
}

bool Player::encuentroPelea()
{

    if(!itPActual->getHp())
        return true;
    cout<<"Su nombre es: "<<auxPek.getName()<<endl
        <<"Su nivel es: "<< auxPek.getLevel()<<endl
        <<"Su Hp es: "<< auxPek.getHp()<<endl
        <<"Su Attack es: "<< auxPek.getAttack()<<endl
        <<"Su Experiencia es"<< auxPek.getExperience()<<endl;

    cout<<"Tu Estas En Combate"<<endl;
    if(itPActual->getAttack())
        //rebajar el atque con el que se hizo
        itPActual->setAttack(itPActual->getAttack()-1);
    else{
        cout<<"Ya No Tienes Ataques"<<endl;
        return true;
    }

    if((int)((auxPek.getHp()-itPActual->getAttack()))>0)
        auxPek.setHp(auxPek.getHp()-itPActual->getAttack());
    else{
        auxPek.setHp(0);
        cout<<"Haz Ganado!"<<endl;
        encuentroGanaste();
        return true;
    }
    ataquePekemonSalvaje();
    system("pause");
    return false;
}

void Player::encuentroGanaste()
{
    itPActual->setExperience(itPActual->getExperience()+(itPActual->getExperience()/2));
    if(itPActual->getExperience()>=pow(2,itPActual->getLevel()+1)){
        itPActual->setHp(itPActual->getHp()+(itPActual->getHp()/2));
        itPActual->setMaxHp(itPActual->getMaxHp()+(itPActual->getMaxHp()/2));
        itPActual->setAttack(itPActual->getAttack()+(itPActual->getAttack()/2));
        itPActual->setLevel(itPActual->getLevel()+1);
    }
}

bool Player::validarHpEnemigo()
{
    if(auxPek.getHp())
        return true;
    else
        return false;
}

bool Player::validarHpTu()
{
    if(itPActual->getHp())
        return true;
    else{
        cout<<"Ya No Tienes Vida"<<endl;
        system("pause");
    }
    return false;
}

bool Player::validarWin()
{
    if(auxPek.getHp()>0)
        return false;
    else
        return true;
}

void Player::encuentroItem()
{
    int opc;
    cout<<"Tu vas elegir un item"<<endl;
    showBackpack(&opc);
    usarItem(&opc);
    system("pause");
}

int Player::returnNameItem(string name)
{
    if(name=="Peke Ball")
        return itemPekeBall;
    if(name== "Great Ball")
        return itemGreatBall;
    if(name== "Ultra Ball")
        return itemUltraBall;
    if(name=="Max Potion")
        return itemMaxPotion;
    if(name=="Hyper Potion")
        return itemHyperPotion;
    if(name=="Super Potion")
        return itemSuperPotion;
    if(name == "Potion")
        return itemPotion;
    if(name== "Hp Up")
        return itemHpUp;
    if(name=="Protein")
        return itemProtein;
    throw invalid_argument("Error Name Item");
}

void Player::usarItem(int *opc)
{
    if(*opc==-1){
        cout<<"No Hay Productos"<<endl;
        return;
    }
    itB=backpack.begin();
    for(int i=0;i<*opc;i++){
        itB++;
    }

    cout<<itB->getName()<<endl;

    int item;
    bool atrapado;
    atrapado=false;
    item=returnNameItem(itB->getName());
    switch (item) {
    case itemPekeBall:
            atrapado=usarBall(item);
        break;
    case itemGreatBall:
            atrapado=usarBall(item);
        break;
    case itemUltraBall:
            atrapado=usarBall(item);
        break;
    case itemMaxPotion:
        usarPosition(itB);
        break;
    case itemHyperPotion:
        usarPosition(itB);
        break;
    case itemSuperPotion:
        usarPosition(itB);
        break;
    case itemPotion:
        usarPosition(itB);
        break;
    case itemHpUp:
        usarPosition(itB);
        break;
    case itemProtein:
        usarProtein();
        break;
    default:
        break;
    }
    if(atrapado){
        cout<<"Felicidades atrapaste a el pokemon"<<endl;
        pekemones.push_back(auxPek);
        return;
    }
    cout<<"Golpe De Pokemon Contrario"<<endl;
    ataquePekemonSalvaje();
}

void Player::ataquePekemonSalvaje()
{
    if((int)(itPActual->getHp()-auxPek.getAttack())>0)
        itPActual->setHp(itPActual->getHp()-auxPek.getAttack());
    else
        itPActual->setHp(0);
}


void Player::usarPosition(list<Item>::iterator itL)
{
    if((itPActual->getHp()+itL->getValue())>itPActual->getMaxHp())
        itPActual->setHp(itPActual->getMaxHp());
    else
        itPActual->setHp(itPActual->getHp()+itL->getValue());
}

void Player::usarProtein()
{
    cout<<"Subiendo Ataque +: "<< 25 <<endl;
    system("pause");
}

bool Player::usarBall(int opc)
{
    int new_number;
    new_number = RandInt(0,100);

    bool atrape;
    atrape=false;
    if(opc==itemPekeBall)
        return (new_number<=50);
    if(opc==itemGreatBall)
        return (new_number<=75);
    if(opc==itemUltraBall)
        return (new_number<=90);
    return false;
}

bool Player::encuentroCambiar()
{
    int opc;
    int again;
    cout<<"Tu vas a cambiar de pekemon"<<endl
        <<"Selecciona un Pekemon Con vida de lo contraio saldras de la pela "<<endl;
    do{
        getPekemones(&opc);
        itPActual=pekemones.begin();
        advance(itPActual,opc);
        again=0;
        if(!itPActual->getHp()){
            cout<<"El pekemon selecionado no tiene vida Para Seleccionar otro 1 Para Salir 0"<<endl;
            cin>>again;
            if(!again)
                return false;
        }
    }while(again);

    cout<<"Nuevo Pekemon Elegido: "<<itPActual->getName()<<endl;
    system("pause");
    ataquePekemonSalvaje();
    return true;
}

void Player::encuentroRun()
{
    cout<<"Tu estas Corriendo"<<endl;
    system("pause");
}

void Player::pekemonCentroMenu()
{
    int opc;
    cout<<"Bienvenido a el centro pekemon"<<endl;
    cout<<"Desea recuperar a todos sus pekemones 1 si 0 no"<<endl;
    cin>>opc;
    if(!opc)
        return;
    pekemonCentroRecargarTodo();
}

void Player::pekemonCentroRecargarTodo()
{
    size_t i=0;
    if(pekemones.empty())
        cout<<"La Lista Esta Vacia"<<endl;
    if(pekemones.size()>0){
        it = pekemones.begin();
        while(i!=pekemones.size()){
            it->setHp(it->getMaxHp());
            it++;
            i++;
        }
    }
    system("pause");
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
           <<menuExplore<< "MenuExplore"<<endl
           <<menuCentroPekemon<< "MenuCentroPekemon"<<endl
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
        case menuExplore:
            menuExploreF();
            break;
        case menuCentroPekemon:
            pekemonCentroMenu();
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
    string file = "./Pekemones/"+getNombre();
    mkdir(file.c_str());

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
            it->guardar(getNombre());
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
    deleteAllMovesFolders();
    string file="./Pekemones/";
    file.append(nombre);
    rmdir(file.c_str());
    file.append(".txt");
    const char *c = file.c_str();
    remove(c);
}

void Player::deleteAllMovesFolders()
{
    string dir="./Pekemones/"+getNombre();
    DIR *theFolder = opendir(dir.c_str());
        struct dirent *next_file;
        char filepath[256];

        while ((next_file = readdir(theFolder)) != NULL)
        {
         // build the path for each file in the folder
         sprintf(filepath, "%s/%s", dir.c_str(), next_file->d_name);
         remove(filepath);
        }
        closedir(theFolder);
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

