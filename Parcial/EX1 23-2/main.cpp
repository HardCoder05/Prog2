
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 4 de mayo de 2024, 10:07 AM
 */

#include "Pregunta01Examen01PunterosMultiples.h"



int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    ordenarPedidos(fechaClienteCantidad, codigoDelProducto);
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,
        "PruebaPedidos.txt");
    
    
    
    
    
    return 0;
}

