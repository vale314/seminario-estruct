#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class ListaEstatica{

public:
    //index(0) da 0 al atributo index
    /*Es lo mismo que
    ListaEstatica(){
        index = 0;
    }
    */
    ListaEstatica(): index(0){
    }

    //creamos un segundo constructor donde recibe un elementos de tipo Lista Estatica y ese elemento lo copeamos uno por uno a la lista
    ListaEstatica<T>(const ListaEstatica<T>& other){
        for(size_t i=0; i < other.index; i++){
            _insert(other[i]);
        }
    }

    bool _empty();
    bool full();
    size_t _size();
    /*un paso por referencia constante */
    void _insert(const T& elem);
    void  print();
    size_t _find(const T& elem);
    void _remove(size_t idx);
    T& operator[](size_t idx);
    T& _end();

    private:
        static const size_t CAPACITY = 1000;
        T elements[CAPACITY];
            size_t index;
};

//Ocupamos indeciar que es una platilla
template <typename T>
bool ListaEstatica<T>::_empty(){
    return index == 0;
}

template <typename T>
bool ListaEstatica<T>::full(){
    return index == CAPACITY;
}

template <typename T>
size_t ListaEstatica<T>::_size(){
    return index;
}

template <typename T>
void ListaEstatica<T>::_insert(const T &elem){
    if(full())
        throw invalid_argument("full list");

    elements[index] = elem;
    index ++;
}

template <typename T>
void ListaEstatica<T>::print(){
    if(_empty())
        throw invalid_argument("Lista Esta Vacia");

    for(int i=0;i<index; i++){
        cout << "Elemento : " << elements[i]<< endl;
    }
}

template <typename T>
size_t ListaEstatica<T>::_find(const T& elem){
    int i;
    for(i=0; i <index; i++){
        if(elem == elements[i])
            return i;
    }
    if(i==index)
        return index+1;
}

template <typename T>
void ListaEstatica<T>::_remove(size_t idx){
    if(idx>index)
        throw  invalid_argument("No se puede eliminar");

    for(int i=0; i<=index; i++){
        if(idx>=i){
            elements[i] = elements[i+1];
        }
    }
    index--;
}


template <typename T>
T& ListaEstatica<T>::_end(){
    return elements[index];
}


/*No funciona para regresar un elemento del tipo template*/
template <typename T>
T& ListaEstatica<T>::operator[](size_t idx){
    if(_empty())
        throw invalid_argument("[] on empty list");
    if(idx >= index)
        throw invalid_argument("[] on invalid porsition");

    return elements[idx];
}

#endif // LISTAESTATICA_H
