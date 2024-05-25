
#include "Presencial.h"

Presencial::Presencial(){
    total = 0;
}

void Presencial::setRecargo(double recargo){
    this->recargo = recargo;
}

void Presencial::setTotal(double total){
    this->total = total;
}

double Presencial::getRecargo(){
    return recargo;
}

double Presencial::getTotal(){
    return total;
}

void Presencial::llenarDatos(int cod, char *nomb, int esc, double recar){
    setCodigo(cod);
    setNombre(nomb);
    setEscala(esc);
    setRecargo(recar);
}

void Presencial::mostrarDatos(ofstream &arch){
    char nomb[60];
    getNombre(nomb);
    arch << left << setw(10) << getCodigo() << setw(40) << nomb << right << 
        setw(10) << getEscala() << setw(10) << getRecargo() << setw(10) << 
        getTotal() << endl;
}


















