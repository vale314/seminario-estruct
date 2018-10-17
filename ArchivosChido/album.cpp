#include "album.h"

Album::Album()
{
    cargar();
    //ctor
}

Album::~Album()
{
    //dtor
}

void Album::agregar(){
    Song s;
    string title;
    string author;
    int year;
    unsigned int duration;

    cout << "Nombre: " <<endl;
    getline(cin,title);
    cout << "Author:" <<endl;
    getline(cin,author);
    cout<< "Año" << endl;
    cin >> year;
    cout << "Duration " << endl;
    cin >> duration;

    s.setTitle(title);
    s.setDuration(duration);
    s.setAuthor(author);
    s.setYear(year);

    songs._insert(s);
    guardar(s);
}
void Album::consultar(){
    for(size_t i=0; i< songs._size(); i++)
        cout << songs[i];
}
void Album::cargar(){
    ifstream archivo("album.txt");
    string linea;
    if(!archivo.is_open()){
        cout <<" No se pudo abrir el archivo";
        return;
    }
    while(getline(archivo,linea)){
        Song s(linea);
        songs._insert(s);
    }
}
void Album::guardar(const Song& obj){
    //(nameFile,modo de apertura)
    ofstream archivo("album.txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivo << obj;
    archivo.close();
}
void Album::menu(){
    int opc;
    do{
        cout << "\t\t\t\tMenu" <<endl
        << Menu_agregar<<" Agregar" << endl
        << Menu_consultar << " Consultar" << endl
        << Menu_cargar << " Cargar" << endl
        << Menu_guardar << " Guardar" << endl
        << Menu_salir << " Salir" << endl;
        cin >> opc;
        cin.ignore();

        switch(opc){
            case Menu_agregar:
                agregar();
            break;

            case Menu_cargar:
                cargar();
            break;

            case Menu_consultar:
                consultar();
            break;


            case Menu_guardar:
            break;

            case Menu_salir:
            break;

            default:
                cout <<"Opcion no valida" << endl;

        }
    }while( opc != Menu_salir);

}
