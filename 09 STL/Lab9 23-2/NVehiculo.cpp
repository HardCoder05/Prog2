
/* 
 * File:   NVehiculo.cpp
 * Author: 
 * 
 * Created on 16 de junio de 2024, 04:55 PM
 */

#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig){ //este si es necesario
    unidad = nullptr;
    *this = orig;
}

NVehiculo::~NVehiculo() {
}

void NVehiculo::operator =(const NVehiculo &nveh){
    unidad = nveh.unidad;
}

void NVehiculo::leer(ifstream& arch) {
    char tipo;
    
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    
    if (tipo == 'F') {
        unidad = new class Furgon;
    } else if (tipo == 'C') {
        unidad = new class Camion;
    }
    
    unidad->lee(arch);
}

bool NVehiculo::operator <(const NVehiculo &c){
    return unidad->GetCliente() < c.unidad->GetCliente();
}

bool NVehiculo::comparar(int cliente){
    return unidad->GetCliente() == cliente;
}

void NVehiculo::carga(NPedido &pedido){
    unidad->cargadeposito(pedido);
}

void NVehiculo::imprimir(ofstream &arch){
    unidad->imprime(arch);
}

