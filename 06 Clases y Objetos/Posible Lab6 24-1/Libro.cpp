
/* 
 * File:   Libro.cpp
 * Author: rio88
 * 
 * Created on 23 de mayo de 2024, 10:16 AM
 */

#include <cstring>
#include "Libro.h"

Libro::Libro() {
    codigo = nullptr;
    titulo = nullptr;
    autor = nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if(codigo != nullptr) delete []codigo;
    if(titulo != nullptr) delete []titulo;
    if(autor != nullptr) delete []autor;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(char* aut) {
    if(autor != nullptr) delete []autor;
    autor = new char[strlen(aut) + 1];
    strcpy(autor, aut);
}

void Libro::GetAutor(char *aut) const {
    if(autor == nullptr) aut[0] = 0;
    else strcpy(aut, autor);
}

void Libro::SetTitulo(char* titu) {
    if(titulo != nullptr) delete []titulo;
    titulo = new char[strlen(titu) + 1];
    strcpy(titulo, titu);
}

void Libro::GetTitulo(char *titu) const {
    if(titulo == nullptr) titu[0] = 0;
    else strcpy(titu, titulo);
}

void Libro::SetCodigo(char* cod) {
    if(codigo != nullptr) delete []codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

bool operator >>(ifstream &arch,Libro &libro){
    char cod[8], titulo[80], autor[60], c;
    int stock;
    double precio;
    
    arch.getline(cod, 8, ',');
    if(arch.eof()) return false;
    arch.getline(titulo, 80, ',');
    arch.getline(autor, 60, ',');
    arch>>stock>>c>>precio;
    arch.get();
    
    libro.SetCodigo(cod);
    libro.SetTitulo(titulo);
    libro.SetAutor(autor);
    libro.SetStock(stock);
    libro.SetPrecio(precio);
    
    return true;
}

void operator <<(ofstream &arch,Libro &lib){
    char cod[8], titulo[80], autor[60];
    lib.GetCodigo(cod);
    lib.GetTitulo(titulo);
    lib.GetAutor(autor);
    
    arch<<left<<setw(10)<<cod<<setw(60)<<titulo<<setw(40)<<autor<<right<<
        setw(10)<<lib.GetPrecio()<<setw(10)<<lib.GetStock()<<endl;
}

