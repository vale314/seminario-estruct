#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include <string>

using namespace std;

class Automovil
{
    public:
        Automovil();
        virtual ~Automovil();
        void setMarca(string);
        void setVelocidad(float);
        void setModelo(int);
        void setEstado(bool);
        void setGasolina(float);
        void setMenosGasolina(float);
        void setMasVelociadad(float );
        void setMenosVelocidad(float);

        string getMarca();
        int getModelo();
        float getVelocidad();
        bool getEstado();
        float getGasolina();

    protected:

    private:
        string marca;
        int modelo;
        float velocidad;
        bool estado;
        float gasolina;


};

#endif // AUTOMOVIL_H
