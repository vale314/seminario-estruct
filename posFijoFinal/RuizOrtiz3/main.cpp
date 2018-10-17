#include <iostream>
#include <stack>

using namespace std;


int PDP(char d){
    if(d == '+' || d == '-')
        return 1;
    if(d=='*' || d == '/')
        return 2;
    if(d=='^')
        return 3;

    return 0;
}

int PFP(char d){
    if(d=='+' || d=='-')
        return 1;
    if(d=='*' || d=='/')
        return 2;
    return 4;
}


int switchs(char exp, char pila){
    //cout << "    Exp: " << exp <<endl<< "   Pila "<< pila << endl;
    if(exp==')'){
        return 4;
    }
    if(PDP(exp)<PDP(pila)){
        return 1;
    }
    if(PDP(exp)== PDP(pila)){
        return 2;
    }
    if(PDP(exp)>PDP(pila)){
        return 3;
    }
    return 0;
}

int main()
{
    stack <char> pila;
    //char exp[]={'a','+','(','-','c','*','d','^','e',')','/','a'};
    cout << "ingrese su cadena" << endl;
    string exp;
    getline(cin,exp);
    int a;

    for(int i=0;i< exp.size();i++){
        if(exp[i]=='a'||exp[i]=='b'||exp[i]=='c'||exp[i]=='d'||exp[i]=='e')
            cout << exp[i] ;
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^'|| exp[i]==')'){
            if(pila.size()>0)
                a=switchs(exp[i],pila.top());
            a=switchs(exp[i],'!');
            switch(a){
                case 1:
                        while(pila.size()>0){
                            if(PDP(exp[i])<PDP(pila.top())){
                                cout<<pila.top();
                                pila.pop();
                            }else{
                                break;
                            }
                        }

                        break;
                case 2:
                        if(pila.size()>0){
                            while(PDP(exp[i])== PDP(pila.top())){
                                 cout << pila.top();
                                 pila.pop();
                                 pila.push(exp[i]);
                            }
                        }
                        break;
                case 3:
                        if(pila.size()>0){
                            if(PDP(exp[i])>PDP(pila.top())){
                                pila.push(exp[i]);
                            }
                        }else{
                            pila.push(exp[i]);
                        }
                        break;
                case 4:

                        if(exp[i]==')'){
                            while(pila.size() >0){
                                cout << pila.top();
                                pila.pop();
                            }
                        }
                        break;
            }





        }
    }

                                while(pila.size() >0){
                                cout << pila.top();
                                pila.pop();
                            }


    return 0;
}
