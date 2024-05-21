
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:20 AM
 */

#include "Almacen.h"

int main(int argc, char** argv) {
    Almacen almacen;
    
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    
    return 0;
}

