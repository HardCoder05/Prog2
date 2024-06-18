
/* 
 * File:   NPedido.cpp
 * Author: rio88
 * 
 * Created on 16 de junio de 2024, 04:48 PM
 */

#include <cstring>
#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
}

NPedido::NPedido(const NPedido& orig){ //tmb es necesario
    codigo = nullptr;
    *this = orig;
}

NPedido::~NPedido() {
    if(codigo) delete []codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char* codigo) {
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void NPedido::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

void NPedido::operator =(const NPedido &nped){
    char cod[10];
    nped.GetCodigo(cod);
    SetCodigo(cod);
    cantidad = nped.cantidad;
    peso = nped.peso;
}


