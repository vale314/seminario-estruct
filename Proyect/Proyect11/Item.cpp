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
    getline(stream,aux,'|');
    bool valid = false;
    try{
        stock=stoi(aux);
        valid = true;
    }catch(invalid_argument){
        stock=0;
        valid = false;
    }
}

bool Item::shop(unsigned int can)
{
    stock=can;
}

unsigned int Item::getValue()
{
    return value;
}

void Item::shopStock(int can)
{
    stock=stock+can;
}

string Item::getName()
{
    return name;
}

unsigned int Item::getPrice()
{
    return price;
}

unsigned int Item::getStock()
{
    return stock;
}

void Item::setStock(unsigned int can)
{
    stock=stock-can;
}

void Item::printf()
{
    cout<<setw(15)<<setw(15)<< name<< setw(15) << price<<setw(15) <<value<<setw(15)<<description<<setw(15)<<stock<< endl;
}

void Item::setStockV(unsigned int value)
{
    stock=value;
}

ostream& operator <<(ostream& os, const Item& obj){
    os << obj.name << "|"<<obj.price<<"|"<<obj.value<<"|"<<obj.description<<"|"<<obj.stock<<endl;
    return os;
}

//std::ostream& operator<<(ostream& os, const Item& obj) {
//        os<<setw(15)<<setw(15)<< obj.name<< setw(15) << obj.price<<setw(15) <<obj.value<<setw(15)<<obj.description<<setw(15)<<obj.stock<< endl;
//       return os;
//  }
