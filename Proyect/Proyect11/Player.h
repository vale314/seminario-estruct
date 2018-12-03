#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_H
#include <iostream>
#include <list>
#include <Pekemon.h>
#include "Item.h"
#include<ostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdint>
#include <dirent.h>
#include <cstdlib>
#include <ctime>

using namespace  std;

class Player
{
private:
   string nombre;
   int monedas;
   list<Pekemon> pekemones;
   list<Pekemon>::iterator it;
   list<Pekemon>::iterator itPActual;


   list<Item> productos;
   list<Item>::iterator itP;
   list<Item> backpack;
   list<Item>::iterator itB;
   Pekemon auxPek;

    enum{
        menuInfo=1,
        menuPekemones,
        menuTienda,
        menuExplore,
        menuExit
    };
    enum{
        menuTiendaShow=1,
        menuTiendaSell,
        menuTiendaShowBack,
        menuTiendaExit
    };

    enum{
        Bulbasaur=1,
        Squirtle,
        Charizard,
        Pikachu
    };

    enum{
      menuEncuentroPelea=1,
      menuEncuentroItem,
      menuEncuentroCambiar,
      menuEncuentroRun
    };

    enum{
      menuExploreNadaInicio=0,
      menuExploreNadaFin=32,
      menuExploreDineroInicio=33,
      menuExploreDineroFin=65,
      menuExploreEncuentroInicio=66,
      menuExploreEncuentroFin=99
    };

    enum{
      itemPekeBall=0,
      itemGreatBall,
      itemUltraBall,
      itemMaxPotion,
      itemHyperPotion,
      itemSuperPotion,
      itemPotion,
      itemHpUp,
      itemProtein
    };

public:
    Player();
    Player(const string& linea);
    void menu();
    void info();
    void getPekemones();
    void getPekemones(int *);
    void getPekemon(int);
    void setPekemones(const Pekemon &value);
    string getNombre() const;
    void setNombre(const string &value);
    int getModendas() const;
    void setModendas(int value);
    void menuTiendaFunc();
    void menuTiendaShowFunc();
    void menuTiendaShowFunc(int *);
    void menuTiendaComprar(int *);
    bool searchBackpack();
    void sellProducts(int *);
    void showBackpack(int *);
    bool searchTienda();
    void showBackpack();
    friend ostream& operator <<(ostream& os, const Player& obj);
    void guardar();

    void guardarBackpack();
    void deleteAll();
    void deleteAllP();
    void cargar();
    void actualizarPlayer();
    void cargarTienda();
    void ActualizarTienda();

    void menuExploreF();
    void exploreNada();
    void exploreDinero();
    double RandNum (double min, double max);
    int RandInt (int min, int max);
    void exploreEncuentro();

    void encuentroPelea();

    void encuentroItem();
    int returnNameItem(string name);
    void usarItem(int *opc);
    void ataquePekemonSalvaje();
    void usarPosition(list<Item>::iterator itL);
    void usarProtein();
    bool usarBall(int opc);

    void encuentroCambiar();
    void encuentroRun();

};
#endif // PLAYER_H
