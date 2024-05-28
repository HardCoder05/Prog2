
/* 
 * File:   PrioridadBaja.cpp
 * Author: rio88
 * 
 * Created on 28 de mayo de 2024, 09:26 AM
 */

#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja() {
    nueva_fecha_entrega = 0;
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}

void PrioridadBaja::lee(ifstream &arch){
    Pedido::lee(arch);
    arch>>this->dias_espera;
    arch.get(); //salto de linea por si aca
}

void PrioridadBaja::actualiza(void){
    int fecha = Pedido::GetFecha();
    nueva_fecha_entrega = fecha + dias_espera;
    Pedido::SetFecha(fecha + dias_espera);
}

void PrioridadBaja::imprime(ofstream &arch){
    arch<<"Pedido de Prioridad Baja: "<<endl;
    Pedido::imprime(arch);
    arch<<dias_espera<<setw(10)<<nueva_fecha_entrega<<endl<<endl;
}

