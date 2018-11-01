#include "game.h"

Game::Game()
{

}

void Game::menu()
{
    int opc;
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
            info();
            break;
        case menuCargarPartida:
            cargarPartida();
            break;
        case menuEliminarPartida:
            eliminarPartida();
            break;
        case menuExit:
            cout<<"Gracias"<<endl<<"Desarollador Valentine"<<endl;
            break;
        default:
            break;
        }

    }while(op !=menuExit);
}

void Game::crearPartida()
{
    Player aux;
    playerEst playerE;
    cout<<"Name: "<< getline(cin,playerE.nombre);<<endl;
    aux.setNombre(playerE.nombre);

    partida.push_back(aux);
}

void Game::cargarPartida(size_t idx)
{
    partida[idx].menu();
}

void Game::eliminarPartida(size_t idx)
{
    it = myvector.begin();
    for (size_t i=0;i<=partida.size();i++)
        it++;
    myvector.erase(it);
}

void Game::mostrarPartdidas()
{
    size_t opc;
    if(!partida.size())
        cout<<"No mames esta vacia"<<endl;
    for(size_t i=0;i<partida.size();i++)
        cout<< i <<intVector.at(i) <<endl;
    cin>>opc;
    cargarPartida(opc);
}
