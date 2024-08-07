
/* 
 * File:   NPedido.cpp
 * Author: 
 * 
 * Created on 9 de junio de 2024, 11:02 AM
 */

#include <cstring>
#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
    sig = nullptr;
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
    if(codigo) delete[] codigo;
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

void NPedido::GetCodigo(char*cad) const {
    if(codigo==nullptr) cad[0]=0;
    else strcpy(cad,codigo);
}

void NPedido::SetCodigo(char* cad) {
    if(codigo!=nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

