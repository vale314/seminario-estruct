#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> pila;

    pila.push(33);
    pila.push(4);

    cout<<"Vacia: "<<pila.empty() << endl;
    cout<<"Tamaño: "<<pila.size() << endl;

    while(!pila.empty()){
        cout << pila.top() << endl;
        pila.pop();
    }
    return 0;
}
