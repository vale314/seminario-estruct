#include<iostream>

using namespace std;

int arreglo_return(int []);

int main()
{
    int a[5],i;
    cout << "Bienvenido al programa\n";


    for(i=0;i<5;i++){
        cout << "Ingrese el numero" << i+1 <<"\n";
        cin >> a[i];
    }
    arreglo_return(a);
}


int arreglo_return(int a[5]){
    int i,b;

    for(i=0;i<5;i++){
        if(i==0){
           b=a[i];
        }
        if(b>a[i]){
            b=a[i];
        }
    }
    cout << "El Numero mas Pequeño es " << b;
}
