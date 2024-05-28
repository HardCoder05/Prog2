
/* 
 * File:   Almacen.cpp
 * Author: rio88
 * 
 * Created on 28 de mayo de 2024, 09:29 AM
 */

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include "Almacen.h"
#include "Pedido.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
#include "PrioridadBaja.h"


Almacen::Almacen() {
    cantidad_ordenes = 0;
}

void Almacen::cargar_pedidos(const char *nom){
    ifstream arch(nom, ios::in);
    
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get(); //coma
        ordenes[cantidad_ordenes].leerOrden(arch, tipo);
        cantidad_ordenes++;
    }
}

void Almacen::imprimir_ordenes_venta(const char *nom){
    ofstream arch(nom, ios::out);
    
    for(int i=0 ; i < cantidad_ordenes ; i++){
        ordenes[i].imprimirOrden(arch);
    }
}

