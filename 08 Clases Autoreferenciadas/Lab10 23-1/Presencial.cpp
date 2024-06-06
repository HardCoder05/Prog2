
/* 
 * File:   Presencial.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:45 PM
 */

#include "Presencial.h"

Presencial::Presencial() {
    total = 0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

