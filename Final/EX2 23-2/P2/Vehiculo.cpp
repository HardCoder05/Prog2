
/* 
 * File:   Vehiculo.cpp
 * Author: 
 * 
 * Created on 16 de junio de 2024, 04:51 PM
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    carga_actual = 0;
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
    *this = orig;
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::setCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculo::getCarga_actual() const {
    return carga_actual;
}

void Vehiculo::setCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculo::getCarga_maxima() const {
    return carga_maxima;
}

void Vehiculo::setPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::getPlaca() const {
    return placa;
}

void Vehiculo::setDni(int dni) {
    this->dni = dni;
}

int Vehiculo::getDni() const {
    return dni;
}

void Vehiculo::operator =(const Vehiculo& ori){
    dni = ori.dni;
    placa = ori.placa;
    carga_maxima = ori.carga_maxima;
    carga_actual = ori.carga_actual;
}

void Vehiculo::lee(ifstream &arch){
    arch>>dni;
    arch.get();
    char placaa[8];
    arch.getline(placaa, 8, ',');
    arch>>carga_maxima;
    arch.get();
    
    placa = placaa;
}

void Vehiculo::imprime(ofstream &arch){
    arch<<"Codigo Cliente: "<<dni<<endl;
    arch<<"Placa: "<<setw(16)<<placa<<endl;
    arch<<"Carga Maxima: "<<setw(5)<<carga_maxima<<endl;
    arch<<"Carga Actual: "<<setw(5)<<carga_actual<<endl;
}


