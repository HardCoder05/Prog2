
/* 
 * File:   Pedido.cpp
 * Author: 
 * 
 * Created on 2 de julio de 2024, 04:04 PM
 */

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
    *this = orig;
}

Pedido::~Pedido() {
}

void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::operator =(const Pedido& ori){
    peso = ori.peso;
    codigo = ori.codigo;
    cantidad = ori.cantidad;
}

