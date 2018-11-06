#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "./Player.h"


using namespace  std;


class Game
{
private:
    vector<Player> partida;
    vector<Player>::iterator it;
    int max;

    enum{
        menuCrearPartida=1,
        menuCargarPartida,
        menuEliminarPartida,
        menuExit
    };
    struct playerEst{
        string nombre;
    };

public:
    Game();
    void menu();
    void crearPartida();
    void cargarPartida(size_t idx);
    void eliminarPartida(size_t idx);
    size_t mostrarPartidas();
};

#endif // GAME_H
