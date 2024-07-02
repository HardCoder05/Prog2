
/* 
 * File:   Escala.cpp
 * Author: 
 * 
 * Created on 6 de junio de 2024, 12:44 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Escala.h"

Escala::Escala() {
    codigo = 0;
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

