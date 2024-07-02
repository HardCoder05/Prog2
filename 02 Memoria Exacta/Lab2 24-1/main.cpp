
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 16 de abril de 2024, 05:51 PM
 */

#include "memoriaexacta.h"

int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibros.txt", libros, stock);
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, 
        pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);
    
    reporteDeEntregaDePedidos ("ReporteDeEntregaDePedisos.txt", pedidosClientes, 
        pedidosLibros, pedidosAtendidos);
    
    return 0;
}

