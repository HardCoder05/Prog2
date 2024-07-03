
/* 
 * File:   Arista.cpp
 * Author: 
 * 
 * Created on 3 de julio de 2024, 03:58 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Arista.h"
#include "Ciudad.h"

Arista::Arista() {
    longitud = 0;
}

Arista::Arista(double longitud, const class Ciudad &destino) {
    this->longitud = longitud;
    this->destino = destino;
}

void Arista::imprimeArista() const{
    cout.precision(2);
    cout<<fixed;
    cout<<"Longitud: "<<setw(10)<<longitud<<" Destino: ";
    destino.imprime();
}

