#include "game.h"

Game::Game()
{

}

void Game::menu()
{
    int opc;
    size_t p;
    cout<<"\t\t\tMenu Game"<< endl;
    cout<<menuCrearPartida<<" Crear Partida"<<endl
        <<menuCargarPartida<< " Cargar Partida"<<endl
        <<menuEliminarPartida<< " Eliminar Partida"<< endl
        <<menuExit<< " Salir"<< endl;
    do{
        cout<<"\t\t\tMenu"<< endl;
        cin>>opc;
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
    Player aux;
    playerEst playerE;
    cout<<"Name: "<<endl;
    getline(cin,playerE.nombre);
    aux.setNombre(playerE.nombre);

    partida.push_back(aux);
}

void Game::cargarPartida(size_t idx)
{
    if(partida.empty())
        throw invalid_argument("Empty cargarPartida()");
    if(partida.size()>idx)
        partida[idx].menu();
}

void Game::eliminarPartida(size_t idx)
{
    if(partida.empty())
        throw invalid_argument("Empty cargarPartida()");
    if(partida.size()>idx){
        it = partida.begin();
        for (size_t i=0;i<=partida.size();i++)
            it++;
        partida.erase(it);
    }
}

size_t Game::mostrarPartidas()
{
    size_t i;
    size_t opc;
    if(!partida.size())
        cout<<"No mames esta vacia"<<endl;
    for(i=0; i<partida.size(); i++)
        cout<< "intVector.at(" <<i<<")" <<partida.at(i).getNombre() <<endl;
    cout<<"Ingrese Su Partdia Numero: "<<endl;
    cin>>opc;
    return opc;
}
