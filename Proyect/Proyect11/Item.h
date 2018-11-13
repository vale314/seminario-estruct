#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

using namespace std;

class Item
{
private:
    string name;
    unsigned int price;
    unsigned int value;
    string description;
    unsigned int stock;
public:
    Item();
    Item(string,unsigned int,unsigned int,string,unsigned int);
    friend ostream& operator<<(std::ostream&, const Item&);
};

#endif // ITEM_H
