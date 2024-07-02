
/* 
 * File:   Presencial.cpp
 * Author: 
 * 
 * Created on 6 de junio de 2024, 12:45 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total = 0.0;
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

void Presencial::lee(ifstream&arch) {
    Alumno::lee(arch);
    arch>>recargo;
    arch.get(); // Saco el cambio de línea porque la línea empieza en
                // un caracter
}

void Presencial::actualizaTotal(double precioEscala) {
    total = precioEscala*GetCreditos()*(1+GetRecargo()/100.0);
    Alumno::SetTotal(total);
}

void Presencial::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch<<setw(22)<<total<<endl;
}

