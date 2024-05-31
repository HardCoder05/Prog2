
/* 
 * File:   LibroSolicitado.cpp
 * Author: rio88
 * 
 * Created on 23 de mayo de 2024, 09:55 AM
 */

#include <cstring>
#include "LibroSolicitado.h"

LibroSolicitado::LibroSolicitado() {
    codigoDelLibro = nullptr;
}

LibroSolicitado::LibroSolicitado(const LibroSolicitado& orig) {
}

LibroSolicitado::~LibroSolicitado() {
    if(codigoDelLibro != nullptr) delete []codigoDelLibro;
}

void LibroSolicitado::SetAtendido(bool atendido) {
    this->atendido = atendido;
}

bool LibroSolicitado::IsAtendido() const {
    return atendido;
}

void LibroSolicitado::SetPrecio(double precio) {
    this->precio = precio;
}

double LibroSolicitado::GetPrecio() const {
    return precio;
}

void LibroSolicitado::SetCodigoDelLibro(char* cod) {
    if (codigoDelLibro != nullptr) delete []codigoDelLibro;
    codigoDelLibro = new char[strlen(cod) + 1];
    strcpy(codigoDelLibro, cod);
}

void LibroSolicitado::GetCodigoDelLibro(char *cod) const {
    if(codigoDelLibro == nullptr) cod[0] = 0;
    else strcpy(cod, codigoDelLibro);
}

void LibroSolicitado::SetNumeroDePedido(int numeroDePedido) {
    this->numeroDePedido = numeroDePedido;
}

int LibroSolicitado::GetNumeroDePedido() const {
    return numeroDePedido;
}

bool LibroSolicitado::operator >>(Libro& lib){
    char cod[8];
    lib.GetCodigo(cod);
    
    if(strcmp(cod, codigoDelLibro) == 0){
        int stock = lib.GetStock();
        
        if(stock > 0){
            precio = lib.GetPrecio();
            atendido = true;    
            stock--;
            lib.SetStock(stock);
            return true;
        }else{
            atendido = false;
            return false;
        }
    }
}

