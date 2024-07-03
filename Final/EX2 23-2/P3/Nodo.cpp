
/* 
 * File:   Nodo.cpp
 * Author: 
 * 
 * Created on 2 de julio de 2024, 07:24 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
    unidad = nullptr;
    izq = nullptr;
    der = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    if(unidad) delete unidad;
}


