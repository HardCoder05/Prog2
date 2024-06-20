
/* 
 * File:   Enciclopedia.cpp
 * Author: rio88
 * 
 * Created on 20 de junio de 2024, 12:23 PM
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    vigencia = 1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream &arch){
    Libro::lee(arch);
    
    char c;
    
    arch>>sku>>c>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<sku<<setw(15)<<anho<<setw(15)<<vigencia<<endl;
}



