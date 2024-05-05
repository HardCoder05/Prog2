
#include "ColaGenerica.h"

void generacola(void *&cola){
    void **queue = new void*[3];
    queue[0] = nullptr; //cabeza
    queue[1] = nullptr; //cola
    queue[2] = 0; //longitud
    
    cola = queue;
}

void encolar(void *&cola,void *dato){
    void **queue = (void **)cola;
    void **ultimonodo;
    
    //nuevo nodo
    void **nuevoNodo = new void*[2];
    nuevoNodo[0] = dato;
    nuevoNodo[1] = nullptr; //sgte
    
    if(esColaVacia(cola)){
        queue[0] = nuevoNodo;
        (int *)queue[2]++;
    }else{
        ultimonodo = (void **)queue[1];
        ultimonodo[1] = nuevoNodo;
        (int *)queue[2]++;
    }
    
    queue[1] = nuevoNodo;
}

bool esColaVacia(void *cola){
    void **queue = (void **)cola;
    return queue[0] == nullptr;
}

void *desencolar(void *&cola) {
    void **auxCola = (void **)cola;
    
    // Obtener el primer nodo de la cola
    void **primerNodo = (void **)auxCola[0];
    void *elemento = primerNodo[0]; // Extraer el elemento del primer nodo
    
    // Actualizar el puntero al primer nodo para que apunte al siguiente nodo
    auxCola[0] = primerNodo[1];
    
    // Reducir el contador de elementos en la cola
    auxCola[2]--;
    
    if (auxCola[2] == 0) {
        auxCola[1] = nullptr;
    }
    
    delete primerNodo;
    return elemento;
}


