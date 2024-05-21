
/* 
 * File:   Pedido.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(codigo != nullptr) delete codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if (codigo != nullptr) delete []codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

char* Pedido::GetCodigo() const {
    return codigo;
}

bool operator >>(ifstream &arch,Pedido &ped){
    char codigo[10];
    int dni;
    
    arch.getline(codigo, 8, ',');
    if(arch.eof()) return false;
    arch>>dni;
    arch.get();
    
    ped.SetCodigo(codigo);
    ped.SetDni_cliente(dni);
    
    return true;
}

