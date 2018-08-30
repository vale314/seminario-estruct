#include "../include/Conductor.h"
#include "Automovil.h"
#include <iostream>

Conductor::Conductor()
{

}

Conductor::~Conductor()
{
    //dtor
}

void Conductor:: menu(){
    int opcion;
    do{
        cout << "\tBienvenido A El Automovil" << endl
        << OpcionEnceder << " Encender" <<endl
        << OpcionApagar << " Apagar" <<endl
        << OpcionAcelerar << " Acelerar" <<endl
        << OpcionFrenar << " Frenar" <<endl
        << OpcionCargarGasolina << " Cargar Gasolina" <<endl
        << OpcionSalir <<" Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch(opcion){
            case OpcionEnceder:
                setEncender();
            break;

            case OpcionApagar:
                setApagar();
            break;

            case OpcionAcelerar:
                setAcelerar();
            break;

            case OpcionFrenar:
                setFrenar();
            break;

            case OpcionCargarGasolina:
                setCargarGasolina();
            break;

            case OpcionSalir:
            break;
        }
    }while(opcion !=6);
}




void Conductor :: setEncender(){
    if(!carro.getEstado()){
        carro.setEstado(true);
        cout << "ENCENDIENDO" << endl;
        return;
    }
    cout << "El auto estaba encendido" <<endl;

}
void Conductor :: setApagar(){
    if(carro.getEstado()){
        carro.setEstado(false);
        cout << "APAGANDO" << endl;
        return;
    }
    cout << "El auto estaba apagado" <<endl;
}
void Conductor :: setAcelerar(){
    if(carro.getEstado() && carro.getGasolina()){


        carro.setMasVelociadad(2.0);
        carro.setMenosGasolina(0.25);
        if(!carro.getGasolina()){
            cout << "El Auto Ya No Tiene Gasolina" << endl;
            carro.setVelocidad(0);
            carro.setEstado(false);
            return;
        }

        cout << "Velocidad: " << carro.getVelocidad()<<endl
        << "Gasolina" << carro.getGasolina() <<endl;
        return;
    }
    cout << "El auto esta apagado o no tiene gasolina" << endl;
}

void Conductor :: setFrenar(){
    if(carro.getVelocidad()>0){
        carro.setMenosVelocidad(5.0);
        cout << "Velocidad: " << carro.getVelocidad()<<endl;
        return;
    }
    cout << "No se puede frenar velocidad 0" << endl;
}
void Conductor :: setCargarGasolina(){
    float litros;
    cout << "Cuantos Litros Va A Cargar" <<endl;
    cin>> litros;
    carro.gasolina=carro.gasolina+litros;
    cout << "El Auto Tiene " << carro.gasolina << "Litros De Gas" <<endl;
}
