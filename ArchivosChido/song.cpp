#include "song.h"

Song::Song()
{
    //ctor
}

Song::~Song()
{
    //dtor
}

Song::Song(const string &linea){
    string aux;
    stringstream stream(linea);

    getline(stream,aux, '|');
    setTitle(aux);
    getline(stream,aux,'|');
    setAuthor(aux);
    getline(stream,aux, '|');
    setYear(stoi(aux));
    getline(stream,aux,'|');
    setDuration(stoi(aux));
}

string Song::getAuthor() const{
    return author;
}
void Song::setAuthor(const string &value){
    author=value;
}

void Song::setTitle(const string &value){
    title=value;
}
string Song::getTitle()const{
    return title;
}

int Song::getYear()const{
    return year;
}
void Song::setYear(int value){
    year=value;
}

unsigned int Song::getDuration() const{
    return duration;
}
void Song::setDuration(unsigned int value){
    duration=value;
}


ostream& operator <<(ostream& os, const Song& obj){
    os << obj.getTitle() << "|" << obj.getAuthor() <<"|" <<obj.getYear()
    <<"|" <<obj.getDuration() << endl;
    return os;
}
