
/* 
 * File:   PrioridadAlta.cpp
 * Author: 
 * 
 * Created on 28 de mayo de 2024, 09:20 AM
 */

#include "PrioridadAlta.h"

PrioridadAlta::PrioridadAlta() {
    total = 0;
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}

void PrioridadAlta::lee(ifstream &arch){
    Pedido::lee(arch);
    arch>>this->recargo;
    arch.get(); //por si acaso salto de linea
}

void PrioridadAlta::actualiza(void){
    double subtotal = Pedido::GetSubtotal();
    total = subtotal * recargo / 100;
    Pedido::SetTotal(subtotal + total);
}

void PrioridadAlta::imprime(ofstream &arch){
    arch<<"Pedido de Prioridad Alta: "<<endl;
    Pedido::imprime(arch);
    arch<<recargo<<setw(10)<<Pedido::GetTotal()<<endl<<endl;
}

