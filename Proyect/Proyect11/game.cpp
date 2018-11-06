#include "Game.h"

Game::Game()
{
 max=0;
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

    cout<<"Seleccione el Pekeemon"<<endl;
//    //vector<Pekemon::types> it;
//    //it=Pekemon::types::acero;
////    for ( int i = Pekemon::types::acero; i != Pekemon::types::volador; i++ ){
////        Pekemon foo = static_cast<Pekemon>(i);
////    }
//    for ( int fooInt =acero; fooInt != volador; fooInt++ )
//    {
//       types foo = static_cast<types>(fooInt);
//       cout<<foo<<endl;
//    }
    //mostrarTiposPeekemons();
    cin>>playerE.nombreP;
    partida.push_back(aux);
    max++;
}

void Game::mostrarTiposPeekemons(){
//    cout<<"acero"<< Pekemon::acero<<endl
//        <<"agua"<<Pekemon::agua <<endl
//        <<"dragon"<<Pekemon::dragon <<endl
//        <<"electrico"<<Pekemon::electrico <<endl
//        <<"fantasma"<<Pekemon::fantasma <<endl
//        <<"fuego"<<Pekemon::fuego<<endl
//        <<"hada"<<Pekemon::hada <<endl
//        <<"hielo"<<Pekemon::hielo <<endl
//        <<"hierba"<<Pekemon::hierba <<endl
//        <<"insecto"<<Pekemon::insecto <<endl
//        <<"normal"<<Pekemon::normal <<endl
//        <<"oscuro"<<Pekemon::oscuro <<endl
//        <<"pelea"<<Pekemon::pelea <<endl
//        <<"psiquico"<<Pekemon::psiquico <<endl
//        <<"roca"<<Pekemon::roca <<endl
//        <<"tierra"<<Pekemon::tierra <<endl
//        <<"venenoso"<<Pekemon::venenoso <<endl
//        <<"volador"<<Pekemon::volador <<endl;
}

void Game::cargarPartida(size_t idx)
{
    if(partida.empty())
        throw invalid_argument("Empty cargarPartida()");
    if(partida.size()>idx)
        partida[idx].menu();
    if(partida.size()<idx)
        throw invalid_argument("Size is minor CragarPartida()");
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
        partida.erase(it);
    }
}

size_t Game::mostrarPartidas()
{
    size_t i;
    size_t opc;
    if(!partida.size())
        throw invalid_argument ("Esta Vacia Vector");
    for(i=0; i<partida.size(); i++)
        cout<<i<<" " <<partida.at(i).getNombre() <<endl;
    cout<<"Ingrese Su Partdia Numero: "<<endl;
    cin>>opc;
    return opc;
}
