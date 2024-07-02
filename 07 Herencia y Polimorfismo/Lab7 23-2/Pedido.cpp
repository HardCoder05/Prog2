
/* 
 * File:   Pedido.cpp
 * Author: 
 * 
 * Created on 28 de mayo de 2024, 09:14 AM
 */

#include <cstring>
#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    estado = nullptr;
    subtotal = 0;
    total = 0;
}

Pedido::~Pedido() {
    if(codigo != nullptr) delete[] codigo;
    if(estado != nullptr) delete[] estado;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(char* est) {
    if(estado != nullptr) delete[] estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

void Pedido::GetEstado(char *est) const{
    if(estado == nullptr) est[0] = 0;
    else strcpy(est, estado);
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if(codigo != nullptr) delete[] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

void Pedido::lee(ifstream &arch){
    char codPed[8], c;
    int dni, dd, mm, aa;
    double subtot;
    
    arch.getline(codPed, 8 , ',');
    arch>>dni;
    arch.get(); //coma
    arch>>subtot;
    arch>>c>>aa>>c>>mm>>c>>dd>>c;
    
    this->SetCodigo(codPed);
    this->dni_cliente = dni;
    this->subtotal = subtot;
    this->fecha = aa*10000+mm*100+dd;
}

void Pedido::imprime(ofstream &arch){
    char cod[8];
    this->GetCodigo(cod);
    
    arch<<cod<<setw(10)<<this->dni_cliente<<setw(10)<<this->subtotal<<setw(10)
        <<this->fecha<<endl;
}

