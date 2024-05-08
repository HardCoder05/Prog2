
#include "BibliotecaGenerica.h"

void crealista(void *&ped,void* (*lee)(ifstream &),const char *nom){
    ifstream arch(nom, ios::in);

    //Vamos a guardar los datos en una lista simplemente enlazada
    construirlista(ped);

    void *dato;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        insertarlista(ped, dato);
    }
}

void construirlista(void *&ped){
    void **ptr = new void*[2];
    ptr[0] = nullptr; //cabeza
    ptr[1] = nullptr; //cola
    
    ped = (void *)ptr;
}

void insertarlista(void *&ped, void *dato){
    void **ptr = (void **)ped;
    void **nuevo = new void*[2];
    nuevo[0] = dato; //dato
    nuevo[1] = nullptr; //siguiente
    
    if(eslistavacia(ped)){ //lista vacia
        ptr[0] = nuevo; //cabeza
        ptr[1] = nuevo; //cola
    }else{
        void **cola = (void **)ptr[1]; //obtenemos el ultimo nodo
        cola[1] = nuevo; //actualizamos el siguiente del ultimo nodo
        ptr[1] = nuevo; //actualizamos la cola
    }
}

bool eslistavacia(void *ped){
    void **ptr = (void **)ped;
    return ptr[0] == nullptr;
}

void imprimelista(void *ped,void (*imprime)(ofstream &,void *),const char *nom){
    ofstream arch(nom, ios::out);

    void **ptr = (void **)ped;
    void **nodo = (void **)ptr[0]; //obtenemos la cabeza

    while(nodo != nullptr){
        imprime(arch, nodo[0]);
        nodo = (void **)nodo[1];
    }
}

void combinelista(void *&ped1,void *&ped2,void *&pedFinal,int (*cmp)(const void *,const void *)){
    void **ptr1 = (void **)ped1;
    void **ptr2 = (void **)ped2;

    void **nodo1 = (void **)ptr1[0]; //obtenemos la cabeza de la primera lista
    void **nodo2 = (void **)ptr2[0]; //obtenemos la cabeza de la segunda lista

    //Creamos la lista final
    construirlista(pedFinal);

    //Primero agregamos los elementos de la primera lista
    while(!eslistavacia(ped1)){
        void *dato = quitalista(ped1);
        insertarlista(pedFinal, dato);
    }

    //Luego agregamos los elementos de la segunda lista
    //Para ello usaremos una nueva funcion para insertar los elementos en orden
    while(!eslistavacia(ped2)){
        void *dato = quitalista(ped2);
        insertaordenado(pedFinal, dato, cmp);
    }
}

void* quitalista(void *&ped){
    void **ptr = (void **)ped;
    void **nodo = (void **)ptr[0]; //obtenemos la cabeza

    if(nodo == nullptr) return nullptr;

    void *dato = nodo[0]; //obtenemos el dato
    ptr[0] = nodo[1]; //actualizamos la cabeza

    delete nodo;
    return dato;
}

void insertaordenado(void *&ped, void *dato, int (*cmp)(const void *,const void *)){
    void **ptr = (void **)ped, **ant = nullptr, **nuevo;

    nuevo = new void*[2];
    nuevo[0] = dato;
    void **nodo = (void **)ptr[0];
    while(nodo){
        if(cmp(nodo[0], dato) > 0) break;
        ant = nodo;
        nodo = (void **)nodo[1];
    }
    nuevo[1] = nodo;
    if(ant == nullptr) nodo = nuevo;
    else ant[1] = nuevo;
}

