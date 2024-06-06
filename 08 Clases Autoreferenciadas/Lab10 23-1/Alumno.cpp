
/* 
 * File:   Alumno.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:41 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0;
}

Alumno::~Alumno() {
    if(nombre!=nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::GetNombre(char*cad) const {
    if(nombre==nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Alumno::SetNombre(const char* cad) {
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::lee(ifstream&arch) {
    char nomb[60],c;
    arch>>codigo;
    arch.get();
    arch.getline(nomb,60,',');
    SetNombre(nomb);
    arch>>escala>>c>>creditos;
    arch.get();
}

void Alumno::actualizaTotal(double pago) {
    total = pago; // también SetTotal(pago);
}

void Alumno::imprime(ofstream&arch) {
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala
        <<setw(12)<<creditos;

}

