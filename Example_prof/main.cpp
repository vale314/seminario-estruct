#include <iostream>
#include <string>

using namespace std;

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

    cout << "Escriba el nombre de la cancion";
    getline(cin,primera.nombre);
    cout << "Escriba el nombre del artista";
    getline(cin,primera.artista);
    cout << "Escribe la duracion";
    cin >> primera.duracion;
    cout << "Escribe el anio";
    cin >> primera.anio;

    cout << " Nombre: " <<primera.nombre << endl
        <<"Artista: " << primera.artista <<endl
        <<"Duarcion: " << primera.duracion << endl
        << "Genero: " <<primera.genero <<endl
        << "Anio: " <<primera.anio << endl;


    return 0;
}
