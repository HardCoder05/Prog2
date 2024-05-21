
/* 
 * File:   Almacen.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:32 AM
 */

#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::cargar_clientes(void){
    ifstream arch("Clientes.csv", ios::in);
    
    while(true){
        if(arch>>arreglo_clientes[cantidad_clientes] == false) break;
        cantidad_clientes++;
    }
}

void Almacen::cargar_productos(void){
    ifstream arch("Productos.csv", ios::in);
    
    while(true){
        if(arch>>arreglo_productos[cantidad_productos] == false) break;
        cantidad_productos++;
    }
}

void Almacen::cargar_pedidos(void){
    ifstream arch("Pedidos.csv", ios::in);
    Pedido ped;
    
    while(true){
        if(arch>>ped == false) break;
        
        for(int i=0 ; i<cantidad_productos ; i++){
            arreglo_productos[i] += ped;
        }
        for(int i=0 ; i<cantidad_clientes ; i++){
            arreglo_clientes[i] += ped;
        }
    }
}

void Almacen::mostrar_datos(void){
    ofstream archCli("ReporteClientes.txt", ios::out);
    ofstream archProd("ReporteProductos.txt", ios::out);
    
    for(int i=0 ; i<cantidad_clientes ; i++){
        archCli<<arreglo_clientes[i];
    }
    
    for(int i=0 ; i<cantidad_productos ; i++){
        archProd<<arreglo_productos[i];
    }
}

