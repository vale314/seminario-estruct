#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numeros[]={99,88,77,66,55,44,33,22,11};

    for(int i=0; i<9; i++){
        cout << numeros[i] << "";
    }
    cout << endl;
    sort(numeros,numeros + 9);

    for(int i=0; i<9; i++){
        cout << numeros[i] << "";
    }
    cout << endl;

    cout << numeros+9<<endl;
    return 0;
}
