
/* 
 * File:   Semipresencial.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:47 PM
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

