
#include<cstring>
#include "Alumno.h"

Alumno::Alumno(){
    nombre = nullptr;
    total = 0;
}

Alumno::~Alumno(){
    if(nombre != nullptr) delete[] nombre;
}

void Alumno::setCodigo(int codigo){
    this->codigo = codigo;
}

void Alumno::setNombre(char *nombre){
    if(this->nombre != nullptr) delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Alumno::setEscala(int escala){
    this->escala = escala;
}

void Alumno::setTotal(double total){
    this->total = total;
}

int Alumno::getCodigo(){
    return codigo;
}

void Alumno::getNombre(char *nombre){
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

int Alumno::getEscala(){
    return escala;
}

double Alumno::getTotal(){
    return total;
}

