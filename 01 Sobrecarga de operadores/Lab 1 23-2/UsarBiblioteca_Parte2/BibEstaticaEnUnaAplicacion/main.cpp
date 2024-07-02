
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 4 de abril de 2024, 11:20 AM
 */

#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    struct Cliente arregloClientes[140];
    struct Producto arregloProd[170];
    
    leerClientes(arregloClientes);
    leerProd(arregloProd);
    leerPed(arregloClientes, arregloProd);
    
    realizarReporte(arregloClientes, arregloProd);
    
    return 0;
}

