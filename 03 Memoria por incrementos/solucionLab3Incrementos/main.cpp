
/* 
 * File:   main.cpp
 * Author: Joshua Haro
 *
 * Created on April 16, 2024, 8:57 PM
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#include "AperturaDeArchivos.h"
#include "funciones.h"

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidoAtendidos;
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros,stock);
    
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, 
            pedidosLibros, pedidoAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros,stock);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,
            pedidosLibros,pedidoAtendidos);
    return 0;
}

