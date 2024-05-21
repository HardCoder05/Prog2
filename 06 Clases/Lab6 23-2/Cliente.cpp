
/* 
 * File:   Cliente.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:23 AM
 */

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete nombre;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

void Cliente::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete []nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetTelefono() const {
    return telefono;
}

char* Cliente::GetNombre() const {
    return nombre;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator >>(ifstream &arch,Cliente &cli){
    int dni, telefono;
    char nombre[60], c;
    
    arch>>dni;
    if(arch.eof()) return false;
    arch>>c; //coma
    arch.getline(nombre, 60, ',');
    arch>>telefono;
    
    cli.SetDni(dni);
    cli.SetNombre(nombre);
    cli.SetTelefono(telefono);
    
    return true;
}

