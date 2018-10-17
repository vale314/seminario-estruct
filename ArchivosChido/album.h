#ifndef ALBUM_H
#define ALBUM_H
#include "Song.h"
#include "ListaEstatica.h"
#include <fstream> /*Manejar el archivo*/

class Album
{
    public:
        Album();
        virtual ~Album();
        void agregar();
        void consultar();
        void cargar();
        void guardar(const Song& obj);
        void menu();

        enum Menu{
            Menu_agregar=1,
            Menu_consultar,
            Menu_cargar,
            Menu_guardar,
            Menu_salir
        };

    protected:

    private:
        ListaEstatica <Song> songs;
};

#endif // ALBUM_H
