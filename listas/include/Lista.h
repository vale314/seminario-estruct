#ifndef LISTA_H
#define LISTA_H

using namespace std;
class Lista
{
    public:
        Lista();
        int mostrar (), insertar (int, int);
        bool estaVacia(), estaLlena(), suprimir (int);
        int localizar (int), primero(), ultim0 (), anterior (int), siguiente (int);
        virtual ~Lista();
        int ultimo;
};

#endif // LISTA_H
