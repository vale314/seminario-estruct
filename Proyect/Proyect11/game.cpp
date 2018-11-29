#include "Game.h"

Game::Game()
{
 max=0;
 cargar();
}

void Game::menu()
{
    int opc;
    size_t p;
  do{
    system("cls");
    cout<<"\t\t\tMenu Game"<< endl;
    cout<<menuCrearPartida<<" Crear Partida"<<endl
        <<menuCargarPartida<< " Cargar Partida"<<endl
        <<menuEliminarPartida<< " Eliminar Partida"<< endl
        <<menuExit<< " Salir"<< endl;
        cin>>opc;
        system("cls");
        switch (opc) {
        case menuCrearPartida:
            crearPartida();
            break;
        case menuCargarPartida:
            p=mostrarPartidas();
            cargarPartida(p);
            break;
        case menuEliminarPartida:
            p=mostrarPartidas();
            eliminarPartida(p);
            break;
        case menuExit:
            cout<<"Gracias"<<endl<<"Desarollador Valentine"<<endl;
            break;
        default:
            break;
        }

    }while(opc !=menuExit);
}


void Game::crearPartida()
{

    if(max>=3)
        throw invalid_argument("Instance max 3");
    Player aux;
    playerEst playerE;
    cout<<"Name: "<<endl;
    cin.ignore();
    getline(cin,playerE.nombre);
    aux.setNombre(playerE.nombre);

    escogerPeekemons(&playerE.nombreP);
    Pekemon auxPek(Pekemon::types::normal,playerE.nombreP);
    aux.setPekemones(auxPek);
    partida.push_back(aux);
    max++;
    guardarAll();

}

void Game::escogerPeekemons(string *pek){
    int opc;
    do{
        cout<<PekBulbasaur<<" Bulbasaur"<<endl
            <<PekSquirtle<<" Squirtle"<<endl
            <<PekCharizard<<" Charizard"<<endl
            <<PekPikachu<<" Pikachu"<<endl;
        cin>>opc;
        switch(opc){
            case PekBulbasaur:
            *pek="Bulbasaur";
            break;
        case PekSquirtle:
            *pek="Squirtle";
            break;
        case PekCharizard:
            *pek="Charizard";
            break;
        case PekPikachu:
            *pek="Pikachu";
            break;
        default:
            cout<<"Opcion Incorrecta"<<endl;
        }
    }while(opc>PekPikachu);
}


void Game::cargarPartida(size_t idx)
{

    if(partida.size()>idx)
        partida[idx].menu();

}

void Game::eliminarPartida(size_t idx)
{
    size_t  i=0;
    if(partida.empty())
        cout<<"La Lista Esta Vacia"<<endl;
    if(partida.size()>idx){
        it = partida.begin();
        while(i!=idx){
            it++;
            i++;
        }
        cout<<"i "<<i<<endl;
        it->deleteAll();
        it->deleteAllP();
        partida.erase(it);
    }
    guardarAll();
}


void Game::guardarAll()
{
    deleteAll();
    deleteAllNombres();
    size_t i;
    if(partida.size()){
        for(i=0; i<partida.size(); i++)
            guardar(partida[i],partida.at(i).getNombre());
    }
}

void Game::deleteAll()
{

    DIR *theFolder = opendir("./Player");
        struct dirent *next_file;
        char filepath[256];

        while ((next_file = readdir(theFolder)) != NULL)
        {
         // build the path for each file in the folder
         sprintf(filepath, "%s/%s", "./Player", next_file->d_name);
         remove(filepath);
        }
        closedir(theFolder);

}

void Game::guardarList()
{
    size_t i;
    if(!partida.size())
        throw invalid_argument ("Esta Vacia Vector");
    for(i=0; i<partida.size(); i++){
        ofstream archivo("./Player/"+partida.at(i).getNombre()+".txt", ios::app);

        if(!archivo.is_open()){
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }

        archivo << partida.at(i);
        archivo.close();
        partida.at(i).guardar();
    }
}

void Game::leerString(const string &linea){
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    nombres.push_back(aux);
    cout<<aux<<endl;
}

void Game::cargar()
{

       ifstream archivo("./Nombres/Nombres.txt");
       string linea;
       if(!archivo.is_open()){
           cout <<" No se pudo abrir el archivo";
           return;
       }
       while(getline(archivo,linea)){
           string aux;
           stringstream stream(linea);
           leerString(linea);
       }



     for(size_t i=0; i<nombres.size(); i++){
        ifstream archivo("./Player/"+nombres.at(i)+".txt");
        string linea;
        if(!archivo.is_open()){
            cout <<" No se pudo abrir el archivo";
            return;
        }
        while(getline(archivo,linea)){
            Player s(linea);
            partida.push_back(s);
        }
     }



}

void Game::deleteAllNombres()
{
    DIR *theFolder = opendir("./Nombres");
        struct dirent *next_file;
        char filepath[256];

        while ((next_file = readdir(theFolder)) != NULL)
        {
         // build the path for each file in the folder
         sprintf(filepath, "%s/%s", "./Nombres", next_file->d_name);
         remove(filepath);
        }
        closedir(theFolder);
}

void Game::guardar(Player &obj,const string name)
{
    ofstream archivo("./Player/"+name+".txt", ios::app);
    ofstream archivoN("./Nombres/Nombres.txt", ios::app);

    if(!archivo.is_open() || !archivoN.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivoN<<name+"\n";
    archivoN.close();
    archivo<< obj;
    archivo.close();
    obj.guardar();
}

size_t Game::mostrarPartidas()
{
    size_t i;
    size_t opc;
    if(partida.size())
    {
        for(i=0; i<partida.size(); i++)
            cout<<i<<" " <<partida.at(i).getNombre() <<endl;
        cout<<"Ingrese Su Partdia Numero: "<<endl;
        cin>>opc;
        return opc;
    }
}
