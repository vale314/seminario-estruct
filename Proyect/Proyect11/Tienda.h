#ifndef TIENDA_H
#define TIENDA_H
#include <list>
#include "Item.h"

using namespace std;

class Tienda
{
private:
    list<Item> productos;
    list<Item>::iterator it;
public:
    Tienda();
    void showProducts();
};

#endif // TIENDA_H
