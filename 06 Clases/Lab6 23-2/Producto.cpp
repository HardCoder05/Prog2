
/* 
 * File:   Producto.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:25 AM
 */

#include "Producto.h"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if(codigo != nullptr){
        delete codigo;
        delete descripcion;
    }
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(char* desc) {
    if (descripcion != nullptr) delete []descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}

char* Producto::GetDescripcion() const {
    return descripcion;
}

void Producto::SetCodigo(char* cod) {
    if (codigo != nullptr) delete []codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

char* Producto::GetCodigo() const {
    return codigo;
}

bool operator >>(ifstream &arch,Producto &prod){
    char codigo[10], descripcion[60], c;
    int stock;
    double precio;
    
    arch.getline(codigo, 8, ',');
    if(arch.eof()) return false;
    arch.getline(descripcion, 60, ',');
    arch>>precio>>c>>stock;
    arch.get(); //salto de linea
    
    prod.SetCodigo(codigo);
    prod.SetDescripcion(descripcion);
    prod.SetPrecio(precio);
    prod.SetStock(stock);
    
    return true;
}

bool Producto::operator +=(Pedido& ped){
    char *codPed = ped.GetCodigo();
    if(strcmp(codigo, codPed) == 0){
        if(stock > 0){
            clientes_servidos[cantidad_clientes_servidos] = ped.GetDni_cliente();
            cantidad_clientes_servidos++;
            stock--;
            ped.SetPrecio_producto(precio);
            return true;
        }else{
            clientes_no_servidos[cantidad_clientes_no_servidos] = 
                ped.GetDni_cliente();
            cantidad_clientes_no_servidos++;
            ped.SetPrecio_producto(precio);
            return false;
        }
    }
}

void operator <<(ofstream &arch,Producto &prod){
    arch<<left<<setw(10)<<prod.GetCodigo()<<setw(60)<<prod.GetDescripcion()<<
        right<<setw(10)<<prod.GetPrecio()<<setw(10)<<prod.GetStock();
    if(prod.GetCantidad_clientes_servidos() == 0 and 
        prod.GetCantidad_clientes_no_servidos() == 0){
        arch<<"  NO SE ATENDIERON PEDIDOS"<<endl;
    }else{
        arch<<endl<<"Clientes atendidos: ";
        prod.imprimirClientesServidos(arch);
        if(prod.GetCantidad_clientes_no_servidos() == 0){
            arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;
        }else{
            arch<<"Clientes no atendidos: ";
            prod.imprimirClientesNoServidos(arch);
        }
    }
    arch<<endl;
}

void Producto::imprimirClientesServidos(ofstream &arch){
    for(int i=0 ; i<cantidad_clientes_servidos ; i++){
        arch<<clientes_servidos[i]<<" ";
    }
    arch<<endl;
}

void Producto::imprimirClientesNoServidos(ofstream &arch){
    for(int i=0 ; i<cantidad_clientes_no_servidos ; i++){
        arch<<clientes_no_servidos[i]<<" ";
    }
    arch<<endl;
}

