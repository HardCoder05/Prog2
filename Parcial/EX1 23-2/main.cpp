
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 4 de mayo de 2024, 10:07 AM
 */

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "ColaConEnteros.h"

#include "ColaGenerica.h"

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    ordenarPedidos(fechaClienteCantidad, codigoDelProducto);
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,
        "PruebaPedidos.txt");
    
    void *productos;
    
    cargarProductos(productos, "Productos.csv");
    pruebaDeCargaDeProductos(productos, "PruebaProductos.txt");
    
    void *cola;
    
    cargaEnteros(cola, leenumero,"numeros.txt");
    mostrarEnteros(cola, imprimenumero,"reporte.txt");
    
    
    return 0;
}

