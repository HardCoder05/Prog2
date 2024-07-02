
/* 
 * File:   Nodo.cpp
 * Author: 
 * 
 * Created on 20 de junio de 2024, 12:35 PM
 */

#include "Nodo.h"

Nodo::Nodo(Libro *libro) {
    plibro = libro;
    sig = nullptr;
    ant = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

