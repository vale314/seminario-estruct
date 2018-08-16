#include <iostream>
#include <string>

using namespace std;

#define MAX 5

struct Cancion{
    string nombre;
    string artista;
    int duracion;
    string genero;
    int anio;
};

int main(int argc, char *argv[])
{
    Cancion primera;
    Cancion disco[MAX];

    int canciones,r,r1;
    string name;
    r1=0;
    cout << "Cuantas canciones tiene el disco";
    cin >> canciones;


    do{
        cout << "1 Agregar Cancion" << endl;
        cout << "2 Consultar disco" <<endl;
        cout << "3 Buscar cancion" <<endl;
        cout << "4 Salir" << endl;

        cin >> r;

        switch (r) {
        case 1:
            cin.ignore();
            if(r1 >= canciones){
                cout << "El Disco Se Encuentra Lleno" << endl;
                break;
            }
                cout << "Escriba el nombre de la cancion" << endl;
                getline(cin,disco[r1].nombre);
                cout << "Escriba el nombre del artista" << endl;
                getline(cin,disco[r1].artista);
                cout << "Escribe la duracion" << endl ;
                cin >> disco[r1].duracion;
                cout << "Escribe el anio" << endl;
                cin >> disco[r1].anio;
                cin.ignore();
                cout << "Escriba el nombre del genero" << endl;
                getline(cin,disco[r1].genero);
                r1++;
            break;
        case 2:
            if(!r1){
                cout << "No se encuentran canicones en el disco" << endl;
                break;
            }
            for(int i =0;i< r1; i++){
                cout << " Nombre: " <<disco[i].nombre << endl
                    <<"Artista: " << disco[i].artista <<endl
                    <<"Duarcion: " << disco[i].duracion << endl
                    << "Genero: " <<disco[i].genero <<endl
                    << "Anio: " <<disco[i].anio << endl;
            }
            break;
        case 3:
            if(!r1){
                cout << "No se encuntran canciones" << endl;
                break;
            }
                cin.ignore();
                cout << "Por favor introdusca el nombre" << endl;
                cin >> name;

                for(int i=0; i<r1; i++){
                    if(disco[i].nombre.compare(name) ==0){
                        cout << " Nombre: " <<disco[i].nombre << endl
                            <<"Artista: " << disco[i].artista <<endl
                            <<"Duarcion: " << disco[i].duracion << endl
                            << "Genero: " <<disco[i].genero <<endl
                            << "Anio: " <<disco[i].anio << endl;
                        break;
                    }

                }
                cout << "No encontrada cancion" <<endl;

            break;
        case 4:

            break;
        default:
            cout << " Adios";
            break;
        }

    }while(r!=4);




    return 0;
}
