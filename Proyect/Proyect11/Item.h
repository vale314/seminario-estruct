#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

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
    Item(const string &);
    friend ostream& operator<<(std::ostream&, const Item&);
};

#endif // ITEM_H
