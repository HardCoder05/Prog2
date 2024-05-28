
#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100;
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

void Virtual::leerDatos(ifstream&arch) {
    char lic[30];
    Alumno::leerDatos(arch);
    arch.getline(lic,30);
    SetLicencia(lic);
}

void Virtual::actualiza(double monto) {
    Alumno::SetTotal(monto+total);
}

void Virtual::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<licencia<<setw(10)<<Alumno::GetTotal()<<endl;
}


