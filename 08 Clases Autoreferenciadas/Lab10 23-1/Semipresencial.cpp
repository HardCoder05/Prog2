
/* 
 * File:   Semipresencial.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:47 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0.0;
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

void Semipresencial::lee(ifstream&arch) {
    Alumno::lee(arch);
    arch>>descuento;
    arch.get(); // Saco el cambio de línea porque la línea empieza en
                // un caracter
}

void Semipresencial::actualizaTotal(double precioEscala) {
    total = precioEscala*GetCreditos()*(1-descuento/100.0);
    Alumno::SetTotal(total);
}

void Semipresencial::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch<<setw(22)<<total<<endl;
}

