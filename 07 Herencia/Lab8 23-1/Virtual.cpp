
#include<cstring>
#include "Virtual.h"

Virtual::Virtual(){
    licencia = nullptr;
    total = 0;
}

Virtual::~Virtual(){
    if(licencia != nullptr) delete[] licencia;
}

void Virtual::setLicencia(char *licencia){
    if(this->licencia != nullptr) delete[] this->licencia;
    this->licencia = new char[strlen(licencia) + 1];
    strcpy(this->licencia, licencia);
}

void Virtual::setTotal(double total){
    this->total = total;
}

double Virtual::getTotal(){
    return total;
}

void Virtual::getLicencia(char *licencia){
    if (this->licencia == nullptr) licencia[0] = 0;
    else strcpy(licencia, this->licencia);
}

void Virtual::llenarDatos(int cod, char *nomb, int esc, char *licencia){
    setCodigo(cod);
    setNombre(nomb);
    setEscala(esc);
    setLicencia(licencia);
}

void Virtual::mostrarDatos(ofstream &arch){
    char nomb[60], lic[30];
    getNombre(nomb);
    getLicencia(lic);

    arch << left << setw(10) << getCodigo() << setw(40) << nomb << right << 
        setw(10) << getEscala() << setw(13) << lic << setw(7) << getTotal() << endl;
}


