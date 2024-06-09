
/* 
 * File:   Flota.cpp
 * Author: rio88
 * 
 * Created on 9 de junio de 2024, 11:29 AM
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    lista.crear();
}

void Flota::cargapedidos(){
    lista.cargar();
}

void Flota::muestracarga(){
    lista.muestra();
}

