
/* 
 * File:   ProductoEntregado.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:20 AM
 */

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {

}

ProductoEntregado::~ProductoEntregado() {
    if(codigo != nullptr) delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* cod) {
    if (codigo != nullptr) delete []codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

char* ProductoEntregado::GetCodigo() const {
    return codigo;
}
