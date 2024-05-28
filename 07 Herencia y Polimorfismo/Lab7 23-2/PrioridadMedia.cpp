
/* 
 * File:   PrioridadMedia.cpp
 * Author: rio88
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

