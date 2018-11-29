#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include<ostream>
#include <string>
#include <sstream>


#include "Player.h"
#include "Pekemon.h"


using namespace  std;


class Game
{
private:
    enum{
       PekBulbasaur=1,
       PekSquirtle,
       PekCharizard,
       PekPikachu
    };
    vector<Player> partida;
    vector<Player>::iterator it;
    vector<string>nombres;
    vector<string>::iterator itN;
    int max;

    enum{
        menuCrearPartida=1,
        menuCargarPartida,
        menuEliminarPartida,
        menuExit
    };
    enum{

    };
    struct playerEst{
        string nombre;
        string nombreP;
    };

public:
    Game();
    void menu();
    void crearPartida();
    void cargarPartida(size_t idx);
    void eliminarPartida(size_t idx);
    void guardar(Player& obj,const string name);
    size_t mostrarPartidas();
    void escogerPeekemons(string*);
    void guardarAll();
    void deleteAll();
    void guardarList();
    void cargar();
    void guardarNames();
    void deleteAllNombres();
    void leerString(const string &linea);
};

#endif // GAME_H
