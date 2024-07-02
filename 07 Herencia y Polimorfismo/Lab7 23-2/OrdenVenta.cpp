
/* 
 * File:   OrdenVenta.cpp
 * Author: 
 * 
 * Created on 28 de mayo de 2024, 09:28 AM
 */

#include "OrdenVenta.h"
#include "PrioridadAlta.h"
#include "PrioridadMedia.h"
#include "PrioridadBaja.h"

void OrdenVenta::leerOrden(ifstream &arch,char tipo){
    if(tipo == 'A'){
        ptr_orden = new PrioridadAlta;
    }else if(tipo == 'M'){
        ptr_orden = new PrioridadMedia;
    }else{
        ptr_orden = new PrioridadBaja;
    }
    ptr_orden->lee(arch);
}

void OrdenVenta::actualizarOrden(){
    ptr_orden->actualiza();
}

void OrdenVenta::imprimirOrden(ofstream &arch){
    ptr_orden->imprime(arch);
}

