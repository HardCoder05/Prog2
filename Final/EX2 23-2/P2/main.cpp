
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 2 de julio de 2024, 03:59 PM
 */

#include "Flota.h"

int main(int argc, char** argv) {
    Flota flota;
    
    flota.cargaflota();
    flota.cargar_pedidos();
    flota.muestracarga();
    
    
    return 0;
}

