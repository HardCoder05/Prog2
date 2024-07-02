
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 28 de mayo de 2024, 09:13 AM
 */

#include "Almacen.h"

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_pedidos("pedidos.csv");
    almacen.actualizar_pedidos();
    almacen.imprimir_ordenes_venta("ReporteFinal.txt");
    
    return 0;
}

