
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 28 de mayo de 2024, 09:13 AM
 */

#include "Almacen.h"

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_pedidos("pedidos.csv");
    almacen.imprimir_ordenes_venta("ReportePrueba.txt");
    
    return 0;
}

