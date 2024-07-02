
/* 
 * File:   Cliente.cpp
 * Author: 
 * 
 * Created on 23 de mayo de 2024, 10:10 AM
 */

#include <cstring>
#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    cantDeLibros = 0;
    pagoTotal = 0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete []nombre;
}

void Cliente::SetPagoTotal(double pagoTotal) {
    this->pagoTotal = pagoTotal;
}

double Cliente::GetPagoTotal() const {
    return pagoTotal;
}

void Cliente::SetCantDeLibros(int cantDeLibros) {
    this->cantDeLibros = cantDeLibros;
}

int Cliente::GetCantDeLibros() const {
    return cantDeLibros;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete []nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator >>(ifstream &arch,Cliente &cli){
    int dni;
    char nombre[60], c;
    
    arch>>dni;
    if(arch.eof()) return false;
    arch>>c; //coma
    arch.getline(nombre, 60, '\n');
    
    cli.SetDni(dni);
    cli.SetNombre(nombre);
    
    return true;
}

bool Cliente::operator <<(LibroSolicitado& libSoli){
    if(cantDeLibros <= 30){
        librosSolicitados[cantDeLibros].SetNumeroDePedido(
                libSoli.GetNumeroDePedido());
        char cod[8];
        libSoli.GetCodigoDelLibro(cod);
        librosSolicitados[cantDeLibros].SetCodigoDelLibro(cod);
        bool booleano = libSoli.IsAtendido();
        if(booleano == true){ //lleno el precio
            librosSolicitados[cantDeLibros].SetPrecio(libSoli.GetPrecio());
            bool atendi = true;
            librosSolicitados[cantDeLibros].SetAtendido(atendi);
        }else{ //no se llena el precio
            librosSolicitados[cantDeLibros].SetAtendido(booleano);
        }
        
        cantDeLibros++;
        
        return true;
    }
    
    return false;
}

void Cliente::operator ++(void){
    for(int i=0 ; i<cantDeLibros ; i++){
        if(librosSolicitados[i].IsAtendido() == true){
            pagoTotal += librosSolicitados[i].GetPrecio();
        }
    }
}

void Cliente::operator ++(int){
    for(int i=0 ; i<cantDeLibros ; i++){
        if(librosSolicitados[i].IsAtendido() == true){
            pagoTotal += librosSolicitados[i].GetPrecio();
        }
    }
}

void operator <<(ofstream &arch,Cliente &cli){
    char nombre[60];
    cli.GetNombre(nombre);
    
    arch<<cli.GetDni()<<"  "<<nombre<<endl;
    cli.imprimirLibros(arch);
    
    arch<<endl;
}

void Cliente::imprimirLibros(ofstream &arch){
    arch<<"Libros entregados: "<<endl;
    arch<<setw(15)<<"Pedido No"<<setw(15)<<"Codigo"<<setw(15)<<"Precio"<<endl;
    for(int i=0 ; i<cantDeLibros ; i++){
        if(librosSolicitados[i].IsAtendido() == true){
            char cod[8];
            librosSolicitados[i].GetCodigoDelLibro(cod);
            
            arch<<setw(15)<<librosSolicitados[i].GetNumeroDePedido()<<setw(15)<<
                cod<<setw(15)<<librosSolicitados[i].GetPrecio()<<endl;
        }
    }
    arch<<"Total a pagar: "<<pagoTotal<<endl;
    
    arch<<"Libros no entregados por falta de stock: "<<endl;
    arch<<setw(15)<<"Pedido No"<<setw(15)<<"Codigo"<<endl;
    for(int i=0 ; i<cantDeLibros ; i++){
        if(librosSolicitados[i].IsAtendido() == false){
            char cod[8];
            librosSolicitados[i].GetCodigoDelLibro(cod);
            
            arch<<setw(15)<<librosSolicitados[i].GetNumeroDePedido()<<setw(15)<<
                cod<<endl;
        }
    }
}

