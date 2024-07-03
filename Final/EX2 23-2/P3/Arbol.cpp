
/* 
 * File:   Arbol.cpp
 * Author: 
 * 
 * Created on 3 de julio de 2024, 09:38 AM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::insertar(Vehiculo *vehiculo){
    insertarR(raiz, vehiculo);
}

void Arbol::insertarR(Nodo *&raiz,Vehiculo *vehiculo){
    if(!raiz){
        raiz = new Nodo();
        raiz->unidad = vehiculo;
        return;
    }
    
    if(raiz->unidad->getDni() > vehiculo->getDni()){
        insertarR(raiz->izq, vehiculo);
    }else{
        insertarR(raiz->der, vehiculo);
    }
}

void Arbol::eliminarHijos(int num){
    int i = 0;
    eliminarHijosR(raiz, num, i);
}

void Arbol::eliminarHijosR(Nodo *&nodo, int num, int &eliminados){
    if (!nodo or eliminados >= num) {
        return;
    }
    
    // Primero, intentamos eliminar en el subárbol izquierdo
    if (nodo->izq) {
        eliminarHijosR(nodo->izq, num, eliminados);
    }
    
    // Luego, intentamos eliminar en el subárbol derecho
    if (nodo->der) {
        eliminarHijosR(nodo->der, num, eliminados);
    }
    
    // Si es un nodo hoja y aún no hemos eliminado suficientes nodos
    if (!nodo->izq and !nodo->der and eliminados < num) {
        delete nodo;
        nodo = nullptr;
        eliminados++;
    }
}

void Arbol::mostrarEnOrden(ofstream &arch){
    int i = 0;
    mostrarEnOrdenR(raiz, arch, i);
    arch<<"Nodos totales del arbol: "<<i<<endl;
}

void Arbol::mostrarEnOrdenR(Nodo *raiz,ofstream &arch,int &cont){
    if(raiz){
        mostrarEnOrdenR(raiz->izq, arch, cont);
        raiz->unidad->imprime(arch);
        cont++;
        mostrarEnOrdenR(raiz->der, arch, cont);
    }
}


