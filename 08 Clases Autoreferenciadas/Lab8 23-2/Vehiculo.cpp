
/* 
 * File:   Vehiculo.cpp
 * Author: 
 * 
 * Created on 9 de junio de 2024, 11:12 AM
 */

#include <cstring>
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
    actcarga = 0;
    ped = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
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

void Vehiculo::lee(ifstream &arch){
    arch>>cliente;
    arch.get();
    char placaa[8];
    arch.getline(placaa, 8, ',');
    arch>>maxcarga;
    arch.get();
    
    SetPlaca(placaa);
}

void Vehiculo::llenar(char *cod,int cant,double peso){
    if (actcarga + peso <= maxcarga) {
        actcarga += peso;
        push(cod, cant, peso);
    }
}

void Vehiculo::push(char *cod,int cant,double peso){
    // Crear un nuevo nodo de pedido
    NPedido *nuevoPedido = new NPedido();
    nuevoPedido->SetCodigo(cod);
    nuevoPedido->SetCantidad(cant);
    nuevoPedido->SetPeso(peso);
    
    // Insertar el nuevo pedido al inicio de la pila
    nuevoPedido->sig = ped;
    ped = nuevoPedido;
}

void Vehiculo::imprime(ofstream &arch){
    arch<<"Codigo Cliente: "<<cliente<<endl;
    char placaa[8];
    GetPlaca(placaa);
    arch<<"Placa: "<<setw(16)<<placaa<<endl;
    arch<<"Carga Maxima: "<<setw(5)<<maxcarga<<endl;
    arch<<"Carga Actual: "<<setw(5)<<actcarga<<endl;
}

void Vehiculo::imprimirPedidos(ofstream &arch){
    NPedido *cabeza = ped;
    while(cabeza){
        arch<<setw(12)<<cabeza->codigo<<setw(8)<<cabeza->cantidad<<setw(8)
            <<cabeza->peso<<endl;
        cabeza = cabeza->sig;
    }
}

