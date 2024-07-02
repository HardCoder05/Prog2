
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 23 de marzo de 2024, 04:13 PM
 */

#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "Sobrecarga.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    //archivos de lectura y escritua
    ifstream archCliente, archProd, archPed;
    ofstream archReporteCliente, archReporteProducto;
    AperturaDeUnArchivoDeTextosParaLeer(archCliente,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProd,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteCliente, "ReporteClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteProducto, "ReporteProductos.txt");
    
    //estructuras
    struct Cliente cli, cliente[150];
    struct Producto prod,producto[180];
    struct Pedido pedido;
    cliente[0].dni =  0;
    strcpy(producto[0].codigo, "XXXXXXX");
    
    //pruebas sencillas
    while(true){
        if(!(archCliente>>cli)) break;
    }
    
    while(true){
        if(!(archProd>>prod)) break;
    }
    
    archPed>>pedido;
    cliente += pedido;
    bool haystock = producto += pedido;
    archPed>>pedido;
    cliente += pedido;
    producto += pedido;
    bool haystock2 = producto += pedido;
    
    //reportes sencillos
    for (int i = 0; cliente[i].dni != 0; i++) {
        archReporteCliente<<cli;
    }
    for (int i = 0; strcmp(producto[i].codigo, "XXXXXXX") != 0 ; i++) {
        archReporteProducto<<prod;
    }
    
    return 0;
}

