
#include <iostream>
#include <iomanip>
using namespace std;

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0;
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

void Semipresencial::leerDatos(ifstream&arch) {
    Alumno::leerDatos(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::actualiza(double monto) {
    total = monto*GetDescuento()/100;
    Alumno::SetTotal(monto-total);
}

void Semipresencial::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<"-"<<setw(10)<<Alumno::GetTotal()<<endl;
}

