
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

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
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

void Cliente::operator +=(const Pedido& ped){
    int dniPed = ped.GetDni_cliente();
    if(dni == dniPed ){
        productos_entregados[cantidad_productos_entregados].SetCodigo(ped.GetCodigo());
        productos_entregados[cantidad_productos_entregados].SetPrecio(ped.GetPrecio_producto());
        cantidad_productos_entregados++;
        monto_total += ped.GetPrecio_producto();
    }
}

void operator <<(ofstream &arch, Cliente &cli){
    arch<<left<<setw(10)<<cli.GetDni()<<setw(40)<<cli.GetNombre()<<right<<
        setw(10)<<cli.GetTelefono()<<setw(10)<<cli.GetMonto_total();
    if(cli.GetCantidad_productos_entregados() > 0){
        arch<<"  Productos entregados: ";
        cli.imprimirProductos(arch);
    }else{
        arch<<"  NO SE LE ENTREGARON PRODUCTOS"<<endl;
    } 
}

void Cliente::imprimirProductos(ofstream &arch){
    for(int i=0 ; i<cantidad_productos_entregados ; i++){
        arch<<productos_entregados[i].GetCodigo()<<" ";
    }
    arch<<endl;
}

