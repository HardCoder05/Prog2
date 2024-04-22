
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 21 de abril de 2024, 04:44 PM
 */

#include "funciones.h"

int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros ("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosInicial.txt" , libros, stock);
    
    atencionDePedidos ("Pedidos.txt", libros, stock, pedidosClientes, 
        pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros ("ReporteDeLibrosFinal.txt", libros, stock);
    
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedisos.txt", 
        pedidosClientes, pedidosLibros, pedidosAtendidos);
    
    return 0;
}

