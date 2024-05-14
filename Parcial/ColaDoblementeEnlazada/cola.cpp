
#include "cola.h"

void generarCola(void *&cola){
    void **ptr = new void*[3];
    ptr[0] = nullptr; // Frente
    ptr[1] = nullptr; // Final
    int *size = new int;
    *size = 0;
    ptr[2] = size; // Tamaño
    cola = ptr;
}

void encolar(void *&cola,void *dato){
    void **ptr = (void**)cola;

    //nuevo nodo con punteros anterior, sgte y dato
    void **nuevo = new void*[3];
    nuevo[0] = nullptr; // Anterior
    nuevo[1] = dato; // Dato
    nuevo[2] = nullptr; // Siguiente

    if(ptr[0] == nullptr){
        ptr[0] = nuevo;
        ptr[1] = nuevo;
    }else{
        void **final = (void**)ptr[1];
        final[2] = nuevo;
        nuevo[0] = final;
        ptr[1] = nuevo;
    }

    int *size = (int*)ptr[2];
    (*size)++;
}

void insertarinicio(void *&cola, void *dato){
    void **ptr = (void**)cola;

    //nuevo nodo con punteros anterior, sgte y dato
    void **nuevo = new void*[3];
    nuevo[0] = nullptr; // Anterior
    nuevo[1] = dato; // Dato
    nuevo[2] = nullptr; // Siguiente

    if(ptr[0] == nullptr){
        ptr[0] = nuevo;
        ptr[1] = nuevo;
    }else{
        void **inicio = (void**)ptr[0];
        inicio[0] = nuevo;
        nuevo[2] = inicio;
        ptr[0] = nuevo;
    }

    int *size = (int*)ptr[2];
    (*size)++;
}

void insertarPosicion(void *&cola, void *dato){
    void **ptr = (void**)cola;

    //nuevo nodo con punteros anterior, sgte y dato
    void **nuevo = new void*[3];
    nuevo[0] = nullptr; // Anterior
    nuevo[1] = dato; // Dato
    nuevo[2] = nullptr; // Siguiente

    if(ptr[0] == nullptr){
        ptr[0] = nuevo;
        ptr[1] = nuevo;
    }else{
        void **final = (void**)ptr[1];
        final[2] = nuevo;
        nuevo[0] = final;
        ptr[1] = nuevo;
    }

    int *size = (int*)ptr[2];
    (*size)++;
}

void imprimirCola(void *&cola){
    void **auxCola = (void **)cola; 
    void **frente = (void **)auxCola[0]; 
    //int *cant = (int *)auxCola[2]; 

    while(frente){
        void *dato = frente[1];
        int *num = (int *)dato;
        cout<<*num<<endl;
        frente = (void **)frente[2];
    }
}






