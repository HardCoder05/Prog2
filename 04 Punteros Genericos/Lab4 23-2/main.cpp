
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 22 de abril de 2024, 05:11 PM
 */

#include "funciones.h"

int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    ordenarClientes(clientes);
    imprimereporte(clientes);
    
    return 0;
}

