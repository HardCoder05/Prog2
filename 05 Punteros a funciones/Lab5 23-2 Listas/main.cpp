
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 1 de mayo de 2024, 04:24 PM
 */

#include "ListasConEnteros.h"
#include "ListasConRegistros.h"
#include "ListaGenerica.h"

int main(int argc, char** argv) {
    int numcamiones = 5;
    double pesomaximo = 10;
    void *flota;
    
    cargacamiones(flota, numcamiones, pesomaximo, leenumero, 
        calculanumero, "numeros.txt");
    qsort(flota, numcamiones, sizeof(void*), cmpnumero);
    muestracamiones(flota, numcamiones, imprimenumero, "reportenum.txt");
    
    numcamiones = 100; pesomaximo = 400;
    cargacamiones(flota, numcamiones, pesomaximo, leeregistro, calcularegistro,
        "pedidos3.csv");
    qsort(flota, numcamiones, sizeof(void*), cmpregistro);
//    muestracamiones(flota, numcamiones, imprimeregistro, "reporteregistro.txt");
    
    return 0;
}

