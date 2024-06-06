
/* 
 * File:   Escala.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:44 PM
 */

#include "Escala.h"

Escala::Escala() {
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

