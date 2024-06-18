
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 12:25 PM
 */

#include "Flota.h"

int main(int argc, char** argv) {
    Flota unidades;
    
    unidades.cargaflota();
    unidades.cargapedidos();
    unidades.muestracarga();
    
    return 0;
}

