#ifndef VEHICULO_H
#define VEHICULO_H


class Vehiculo
{
    public:
        Vehiculo();
        virtual ~Vehiculo();

        void setMarca(string marca);
        void setModelo(int modelo);
        void setDescricion(string descripcion);

    protected:

    private:
        string marca;
        int modelo;
        string descripcion;
};

#endif // VEHICULO_H
