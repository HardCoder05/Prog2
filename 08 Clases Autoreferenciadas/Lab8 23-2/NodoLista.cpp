
/* 
 * File:   NodoLista.cpp
 * Author: 
 * 
 * Created on 9 de junio de 2024, 11:24 AM
 */

#include "NodoLista.h"

NodoLista::NodoLista(Vehiculo *vehiculo) {
    unidad = vehiculo;
    sig = nullptr;
}

NodoLista::NodoLista(const NodoLista& orig) {
}

NodoLista::~NodoLista() {
}



