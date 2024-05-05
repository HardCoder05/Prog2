
#include "ColaConEnteros.h"
#include "ColaGenerica.h"

void cargaEnteros(void *&cola,void* (*lee)(ifstream &),const char *nom){
    ifstream arch(nom, ios::in);
    
    generacola(cola);
    
    void *dato;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        encolar(cola, dato);
    }
}

void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void *),
    const char *nom){
    ofstream arch(nom, ios::out);
    
    while(!esColaVacia(cola)){
        void *dato = desencolar(cola);
        imprime(arch, dato);
    }
}

void *leenumero(ifstream &arch){
    int num;
    arch>>num;
    if(arch.eof()) return nullptr;
    int *numero = new int(num);
    return (void *)numero;
}

void imprimenumero(ofstream &arch,void *dato){
    int *num = (int *)dato;
    arch<<*num<<endl;
}

