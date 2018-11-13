#include "Item.h"

Item::Item(string nameV,unsigned int priceV, unsigned int valueV, string descriptionV, unsigned int stockV)
{
    name=nameV;
    price=priceV;
    value=valueV;
    description=descriptionV;
    stock=stockV;
}

ostream& operator<<(ostream& os, const Item& obj) {
       os << obj.name<<endl << obj.price<<endl <<obj.value<<endl<<obj.description<<endl<<obj.stock<< '\n';
       return os;
   }
