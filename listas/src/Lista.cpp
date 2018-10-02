#include "Lista.h"

Lista::Lista()
{

}

Lista::~Lista()
{
    //dtor
}
void Lista ::insertar(int e, int p)
{
    int i;
    if((estaLlena()) or (p < 0) or (p > ultimo + 1)) {
        std::cout << "Posicion invalida" << std::endl;
        return;
        }
    if(estaVacia()) {
        elementos[0] = e;
        }
    else {
        i = ultimo + 1;
        while (i > p) {
            elementos[i] = elementos[i - 1];
            i--;
            }
        elementos[p] = e;
        }
    ultimo++;
}
void Lista ::suprimir(int p)
{
    int i;
    if ((estaVacia()) or (p < 0) or (p > ultimo)) {
        std::cout << "Ya no hay mas elementos a suprimir" << std::endl;
        return;
        }
    for (i = p; i < ultimo; i++) {
        elementos[i] = elementos[i + 1];
        }
    ultimo--;
}
bool Lista::estaVacia()
{
    if(ultimo == -1)
        return true;
    return false;
}
bool Lista::estaLlena()
{
if(ultimo >= 9){
    return true;
    }
return false;
}
bool Lista::suprimir (int p)
{

}
void Lista::mostrar()
{
    if(estaVacia()) {
        std::cout << "La lista esta vacia" << std::endl;
        return;
        }
    for(int i  = 0; i <= ultimo; i++) {
        std::cout << "#" << i+1 << "\t" << elementos[i] << std::endl;
        }
}
int Lista::localizar (int e)
{
if(estaVacia())
        return -1;
    for(int i=0; i<=ultimo; i++) {
        if(e == elementos[i])
            return i;
        }
    return -1;

}
int Lista::primero()
{
if(!estaVacia())
        return elementos[0];
}
int Lista:: ultimo ()
{
    if(!estaVacia())
        return elementos[ultimo];
}
int Lista::anterior(int e)
{
 if(e!=0)
        return elementos[localizar(e)-1];
}
int Lista::siguiente (int e)
{
  if(e!=9) {
        return elementos[localizar(e)+1];
        }
}
