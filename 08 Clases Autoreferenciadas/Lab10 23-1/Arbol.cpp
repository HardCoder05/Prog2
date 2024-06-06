
/* 
 * File:   Arbol.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:55 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Arbol.h"
#include "Boleta.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    // eliminaR(raiz);
}

void Arbol::cargaEscalas(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cod;
    double precio;

    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>precio;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(precio);
    }
}

void Arbol::crear(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Boleta boleta;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        boleta.asignaMemoria(tipo);
        boleta.leeDatos(arch);
        insertarR(raiz,boleta);
    }
    boleta.SetNull();
}

void Arbol::insertarR(class Nodo*& arbol, const class Boleta& dato) {
    if(arbol == nullptr){
        arbol= new class Nodo;
        arbol->dboleta = dato;
        return;
    }
    if(arbol->dboleta > dato)
        insertarR(arbol->izq, dato);
    else
        insertarR(arbol->der,dato);
}

void Arbol::mostrarEnOrden(const char*nombArch) {
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<setw(8)<<"Escala"
        <<setw(10)<<"Creditos"<<setw(12)<<"Licencia"<<setw(10)<<"Total"<<endl;

    imprimeLinea(arch,'=',90);
    mostrarEnOrdenR(arch,raiz);
    cout<<endl;
}

void Arbol::mostrarEnOrdenR(ofstream &arch, class Nodo *raiz) {
    if(raiz){
        mostrarEnOrdenR(arch, raiz->izq);
        arch<<raiz->dboleta;
        mostrarEnOrdenR(arch, raiz->der);
    }
}

void Arbol::imprimeLinea(ofstream&arch, char car, int nd) {
    for(int i=0; i<nd; i++)
        arch.put(car);
    arch<<endl;
}

void Arbol::actualizaBoleta() {
    actualizaBoletaR(raiz);
}

void Arbol::actualizaBoletaR(class Nodo *arbol) {
    if(arbol == nullptr) return;
    int esc = arbol->dboleta.GetEscala();
    double precio = lescala[esc-1].GetPrecio();

    arbol->dboleta.actualizaBoleta(precio);
    actualizaBoletaR(arbol->izq);
    actualizaBoletaR(arbol->der);
}

