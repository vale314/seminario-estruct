#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdexcept>

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
    size_t mostrarPartidas();
    void escogerPeekemons(string*);
};

#endif // GAME_H
