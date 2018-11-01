#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "console.h"

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace  std;


class Game
{
private:
    vector<Player> partida;
    vector<Player>::iterator it;

    enum{
        menuCrearPartida=1,
        menuCargarPartida,
        menuEliminarPartida,
        menuPlayer,
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
    void mostrarPartdidas();
};

#endif // GAME_H
