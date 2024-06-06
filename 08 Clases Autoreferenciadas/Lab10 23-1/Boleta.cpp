
/* 
 * File:   Boleta.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:51 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Boleta.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if(pboleta!=nullptr) delete pboleta;
}

void Boleta::asignaMemoria(char tipo) {
    switch(tipo){
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
}

void Boleta::leeDatos(ifstream& arch) const {
    pboleta->lee(arch); // Aquí aplicamos Polimorfismo
}

void Boleta::actualizaBoleta(double precioEscala) {
    pboleta->actualizaTotal(precioEscala);
}

void Boleta::imprimeBoleta(ofstream&arch) const {
    pboleta->imprime(arch);
}

bool Boleta::operator >(const class Boleta &dato)const { // <===== OJO
    return pboleta->GetCodigo()>dato.GetCodigo();
}

int Boleta::GetCodigo() const{
    return pboleta->GetCodigo();
}

int Boleta::GetEscala() const {
    return pboleta->GetEscala();
}


void Boleta::SetNull() {
    pboleta = nullptr;
}

void operator >>(ifstream &arch, class Boleta &boleta){
    boleta.leeDatos(arch);
}

void operator <<(ofstream &arch, const class Boleta &boleta) {
    boleta.imprimeBoleta(arch);
}

