#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "./Automovil.h"
#include <iostream>

class Conductor
{
    public:
        Conductor();
        virtual ~Conductor();
        void menu();
        void setEncender();
        void setApagar();
        void setAcelerar();
        void setFrenar();
        void setCargarGasolina();

        enum Opcion{
            OpcionEnceder=1,
            OpcionApagar,
            OpcionAcelerar,
            OpcionFrenar,
            OpcionCargarGasolina,
            OpcionSalir
        };
    protected:

    private:
        Automovil carro;

};

#endif // CONDUCTOR_H
