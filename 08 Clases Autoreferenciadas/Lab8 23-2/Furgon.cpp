
/* 
 * File:   Furgon.cpp
 * Author: rio88
 * 
 * Created on 9 de junio de 2024, 11:22 AM
 */

#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();
}

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"Filas: "<<setw(12)<<filas<<endl;
    arch<<"Puertas: "<<setw(10)<<puertas<<endl;
    arch<<"Pedidos:"<<endl;
    imprimirPedidos(arch);
    arch<<endl;
}

