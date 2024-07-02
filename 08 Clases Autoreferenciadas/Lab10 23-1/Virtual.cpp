
/* 
 * File:   Virtual.cpp
 * Author: 
 * 
 * Created on 6 de junio de 2024, 12:49 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::~Virtual() {
    if(licencia!=nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if(licencia!=nullptr) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia,cad);
}

void Virtual::GetLicencia(char*cad) const {
    if(licencia==nullptr) cad[0]=0;
    else strcpy(cad,licencia);
}

void Virtual::lee(ifstream&arch) {
    char lic[10];
    Alumno::lee(arch);
    arch>>lic;
    arch.get();
    SetLicencia(lic);
}

void Virtual::actualizaTotal(double precioEscala) {
    total = precioEscala*GetCreditos() + 100.0;
    Alumno::SetTotal(total);
}

void Virtual::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch<<setw(12)<<licencia<<setw(10)<<total<<endl;
}

