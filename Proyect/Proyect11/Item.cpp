#include "Item.h"

Item::Item(string nameV,unsigned int priceV, unsigned int valueV, string descriptionV, unsigned int stockV)
{
    name=nameV;
    price=priceV;
    value=valueV;
    description=descriptionV;
    stock=stockV;
}

Item::Item(const string &linea){
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    name=aux;
    getline(stream,aux,'|');
    price=stoi(aux);
    getline(stream,aux, '|');
    value=stoi(aux);
    getline(stream,aux,'|');
    description=aux;
    stock=0;
}

std::ostream& operator<<(ostream& os, const Item& obj) {
       os<<setw(15)<< obj.name<< setw(15) << obj.price<<setw(15) <<obj.value<<setw(15)<<obj.description<<setw(15)<<obj.stock<< endl;
       return os;
  }
