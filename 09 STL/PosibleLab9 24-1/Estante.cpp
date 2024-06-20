
/* 
 * File:   Estante.cpp
 * Author: rio88
 * 
 * Created on 20 de junio de 2024, 12:38 PM
 */

#include "Estante.h"

Estante::Estante() {
}

Estante::Estante(const Estante& orig) {
    *this = orig;
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

void Estante::operator =(const Estante &est){
    clase = est.clase;
    id = est.id;
    capacidad = est.capacidad;
}

void Estante::leer(ifstream &arch){
    char c;
    
    arch>>clase;
    if(arch.eof()) return;
    arch>>c>>id>>c>>capacidad;
    arch.get();
}

void Estante::meter(Libro *libro){
    Llibros.insertar(libro);
}

void Estante::mostrar(ofstream &arch){
    arch<<clase<<setw(15)<<id<<setw(15)<<capacidad<<endl;
    arch<<"Lista contenidos:"<<endl;
    Llibros.mostrar(arch);
    arch<<endl;
}



