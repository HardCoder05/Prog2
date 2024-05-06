
#include "PilaConEnteros.h"

void cargaarreglo(void *&arreglo, int (*cmp)(const void *, const void *), void *(*lee)(ifstream &), const char *nom){
    ifstream arch(nom, ios::in);
    
    void *dato, **ptr = nullptr;
    int cantDat = 0, cap = 0;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        if(cantDat == cap) incrementarEspacios(ptr, cap, cantDat);
        ptr[cantDat - 1] = dato; // Incrementar el contador antes de asignar el dato
        cantDat++;
    }
    
    arreglo = ptr;

    qsort(arreglo, cantDat-1, sizeof(void *), cmp); // Cambiar cantDat-1 a cantDat
    
    // void **numeros = (void **)arreglo;
    // for(int i = 0; numeros[i] ; i++){ // Cambiar el límite de iteración a cantDat
    //     int *num = (int *)numeros[i];
    //     cout << *num << endl;
    // }
}

void incrementarEspacios(void **&ptr, int &cap, int &cantDat){
    cap += INCREMENTO;

    if(ptr == nullptr){
        ptr = new void*[cap]{};
        cantDat = 1;
    }else{
        void **aux = new void *[cap]{};
        for(int i = 0; i < cantDat; i++){
            aux[i] = ptr[i];
        }
        delete ptr;
        ptr = aux;
    }
}

void *leenumero(ifstream &arch){
    int num;
    arch>>num;
    if(arch.eof()) return nullptr;
    int *numero = new int(num);
    return (void *)numero;
}

int cmpnumero(const void *a,const void *b){
    int *num1, *num2; 
    void **aux1 = (void **)a; 
    void **aux2 = (void **)b; 
    
    num1 = (int *)*aux1;
    num2 = (int *)*aux2;
    
    return *num1 - *num2; 
}

