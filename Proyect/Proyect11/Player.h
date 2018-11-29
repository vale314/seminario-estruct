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

using namespace  std;

class Player
{
private:
   string nombre;
   int monedas;
   list<Pekemon> pekemones;
   list<Pekemon>::iterator it;


   list<Item> productos;
   list<Item>::iterator itP;
   list<Item> backpack;
   list<Item>::iterator itB;


    enum{
        menuInfo=1,
        menuPekemones,
        menuTienda,
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


};
#endif // PLAYER_H
