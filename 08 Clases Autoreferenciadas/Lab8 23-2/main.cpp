
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 9 de junio de 2024, 10:59 AM
 */

#include "Flota.h"

int main(int argc, char** argv) {
    Flota transporte;
    
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();
    
    
    return 0;
}

