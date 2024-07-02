
/* 
 * File:   PrioridadMedia.cpp
 * Author: 
 * 
 * Created on 28 de mayo de 2024, 09:22 AM
 */

#include<cstring>
#include "PrioridadMedia.h"

PrioridadMedia::PrioridadMedia() {
    descripcion = nullptr;
}

PrioridadMedia::~PrioridadMedia() {
    if(descripcion != nullptr) delete[] descripcion;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(char* desc) {
    if(descripcion != nullptr) delete[] descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}

void PrioridadMedia::GetDescripcion(char *desc) const {
    if(descripcion == nullptr) desc[0] = 0;
    else strcpy(desc, descripcion);
}

void PrioridadMedia::lee(ifstream &arch){
    Pedido::lee(arch);
    int estado;
    arch>>estado;
    if(estado == 1){
        char desc[7] = "Activo";
        this->SetDescripcion(desc);
    }else{
        char desc[9] = "Inactivo";
        this->SetDescripcion(desc);
    }
    arch.get(); //salto por si aca
}

void PrioridadMedia::actualiza(void){
    char desc[9];
    this->GetDescripcion(desc);
    Pedido::SetEstado(desc);
    int fecha = Pedido::GetFecha();
    this->SetNueva_fecha_entrega(fecha + 1);
    Pedido::SetFecha(fecha + 1);
}

void PrioridadMedia::imprime(ofstream &arch){
    arch<<"Pedido de Prioridad Media: "<<endl;
    Pedido::imprime(arch);
    char estado[10];
    Pedido::GetEstado(estado); //estado
    arch<<left<<setw(15)<<estado<<nueva_fecha_entrega<<right<<endl<<endl;
}

