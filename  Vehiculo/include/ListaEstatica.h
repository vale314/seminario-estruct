#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include <iostream>


using namespace std;

template <typename T>

typedef struct vehiculo {
    string marca;
    int modelo:
    string descripcion;
}

class ListaEstatica
{
    public:
        ListaEstatica():index(0);
        virtual ~ListaEstatica();
        void _insert(struct vehiculo autoN);
        void _delete(size_t num);
        void _show();
        bool _empty();
        bool full();

    protected:

    private:
        static const size_t CAPACITY = 1000;
        T elements[CAPACITY];
            size_t index;
};

template <typename T>
bool ListaEstatica<T>::_empty(){
    return index == 0;
}

template <typename T>
bool ListaEstatica<T>::full(){
    return index == CAPACITY;
}

<template T>
void ListaEstatica<T>::_insert(){

}

<template T>
void ListaEstatica<T>::_delete(){

}

<template T>
void ListaEstatica<T>::_show(){

}

#endif // LISTAESTATICA_H
