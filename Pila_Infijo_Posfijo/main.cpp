#include <iostream>
#include <stack>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int valor(char);

int main()
{
    stack<char> pila;
    stack<char> _string;

    string texto;
    int v, vP;

    cout << "Ingrese su texto" << endl;
    getline(cin,texto);

    for(int i=0; i<texto.length(); i++){
        if(texto[i]==')'){
            while(pila.size()!=0){
                _string.push(pila.top());
                pila.pop();
            }
        }

        //cout << typeid(texto[i]).name() << endl;


        if(texto[i] != '(' && texto[i] != ')'){

                vP=0;
                if(pila.size() !=0)
                    vP=valor(pila.top());
                v=valor(texto[i]);



                if(v == vP){
                    if(pila.size() !=0 ){
                        _string.push(pila.top());
                        pila.pop();
                        pila.push(texto[i]);
                    }
                }

                if(v > vP){
                    pila.push(texto[i]);
                }

                if(v!=0 && vP !=0){
                    while(v <= vP){
                        if(v == vP){
                            if(pila.size() != 0){
                                _string.push(pila.top());
                                pila.pop();
                                pila.push(texto[i]);
                            }
                        }


                        if(v < vP){
                            if(pila.size() != 0){
                                _string.push(pila.top());
                                pila.pop();
                            }
                        }


                        vP=valor(pila.top());


                    }
                }

        _string.push(texto[i]);

        cout << vP << v << endl;

        }

    }
        while(_string.size() != 0){
            cout << _string.top() ;
            _string.pop();
        }

    return 0;

}

int valor(char car){
    if(car == '^')
        return 3;
    if(car == '*' || car == '/')
        return 2;
    if(car == '+' || car ==  '-')
        return 1;
    return 0;
}

