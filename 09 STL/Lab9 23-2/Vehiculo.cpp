
/* 
 * File:   Vehiculo.cpp
 * Author: rio88
 * 
 * Created on 16 de junio de 2024, 04:51 PM
 */

#include <cstring>
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
    actcarga = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) { //este no es necesario
    placa = nullptr;
    *this = orig;
}

Vehiculo::~Vehiculo() {
    if(placa) delete[] placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::GetPlaca(char*cad) const {
    if(placa==nullptr) cad[0]=0;
    else strcpy(cad,placa);
}

void Vehiculo::SetPlaca(char* cad) {
    if(placa!=nullptr) delete []placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::operator =(const Vehiculo &veh){
    char placaa[8];
    cliente = veh.cliente;
    maxcarga = veh.maxcarga;
    veh.GetPlaca(placaa);
    SetPlaca(placaa);
}

void Vehiculo::lee(ifstream &arch){
    arch>>cliente;
    arch.get();
    char placaa[8];
    arch.getline(placaa, 8, ',');
    arch>>maxcarga;
    arch.get();
    
    SetPlaca(placaa);
}

void Vehiculo::imprime(ofstream &arch){
    arch<<"Codigo Cliente: "<<cliente<<endl;
    char placaa[8];
    GetPlaca(placaa);
    arch<<"Placa: "<<setw(16)<<placaa<<endl;
    arch<<"Carga Maxima: "<<setw(5)<<maxcarga<<endl;
    arch<<"Carga Actual: "<<setw(5)<<actcarga<<endl;
}


