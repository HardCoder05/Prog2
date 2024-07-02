
/* 
 * File:   Libro.cpp
 * Author: 
 * 
 * Created on 20 de junio de 2024, 12:22 PM
 */

#include <cstring>
#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
    nombre = nullptr;
    *this = orig;
}

Libro::~Libro() {
    if(nombre) delete []nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(char* nomb) {
    if(nombre) delete []nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Libro::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Libro::operator =(const Libro &lib){
    char nomb[60];
    lib.GetNombre(nomb);
    SetNombre(nomb);
    paginas =  lib.paginas;
    peso =  lib.peso;
}

void Libro::lee(ifstream &arch){
    char titulo[60], c;
    
    arch.getline(titulo, 60, ',');
    arch>>paginas>>c>>peso>>c;
    SetNombre(titulo);
}

void Libro::imprime(ofstream &arch){
    char titulo[60];
    GetNombre(titulo);
    
    arch<<left<<setw(60)<<titulo<<paginas<<right<<setw(15)<<peso<<endl;
}


