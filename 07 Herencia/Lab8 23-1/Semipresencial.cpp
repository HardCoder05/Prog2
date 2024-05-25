
#include "Semipresencial.h"

Semipresencial::Semipresencial(){
    total = 0;
}

void Semipresencial::setDescuento(double descuento){
    this->descuento = descuento;
}

void Semipresencial::setTotal(double total){
    this->total = total;
}

double Semipresencial::getDescuento(){
    return descuento;
}

double Semipresencial::getTotal(){
    return total;
}

void Semipresencial::llenarDatos(int cod, char *nomb, int esc, double descuento){
    setCodigo(cod);
    setNombre(nomb);
    setEscala(esc);
    setDescuento(descuento);
}

void Semipresencial::mostrarDatos(ofstream &arch){
    char nomb[60];
    getNombre(nomb);

    arch << left << setw(10) << getCodigo() << setw(40) << nomb << right << 
        setw(10) << getEscala() << setw(10) << getDescuento() << setw(10) << 
        getTotal() << endl;
}


