
/* 
 * File:   Camion.cpp
 * Author: rio88
 * 
 * Created on 9 de junio de 2024, 11:21 AM
 */

#include "Camion.h"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"Ejes:"<<setw(14)<<ejes<<endl;
    arch<<"Llantas:"<<setw(11)<<llantas<<endl;
    arch<<"Pedidos:"<<endl;
    imprimirPedidos(arch);
    arch<<endl;
}

