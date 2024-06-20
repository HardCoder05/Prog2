
/* 
 * File:   Revista.cpp
 * Author: rio88
 * 
 * Created on 20 de junio de 2024, 12:33 PM
 */

#include "Revista.h"

Revista::Revista() {
    vigencia = 1;
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream &arch){
    Libro::lee(arch);
    
    char c;
    
    arch>>ISSN>>c>>anho>>c>>numero;
    arch.get();
}

void Revista::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<ISSN<<setw(15)<<anho<<setw(15)<<numero<<setw(15)<<vigencia<<endl;
}

