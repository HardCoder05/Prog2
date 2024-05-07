
#include "BibliotecaPilaGenerica.h"

//PARTE PARA LECTURA DE DATOS

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

    // void **medicinas = (void **)arreglo;
    // for(int i = 0; medicinas[i] ; i++){ // Cambiar el límite de iteración a cantDat
    //     void **med = (void **)medicinas[i];
    //     int *cod = (int *)med[0];
    //     char *nom = (char *)med[1];
    //     double *peso = (double *)med[2];
    //     cout<<left<<setw(10)<<*cod<<setw(40)<<nom<<right<<setw(10)<<*peso << endl;
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


//PARTE PARA IMPLEMENTACION DE UNA PILA

// void cargapila(void *&pilaini,void *arreglo){
//     void **ptr = (void **)arreglo;
    
//     //constuir la pila
//     pilaini = crearPila();

//     for(int i = 0; ptr[i]; i++){
//         void *dato = ptr[i];
//         apilar(pilaini, dato);
//     }
// }

// void *crearPila(){
//   void **pila = new void *[2];
//   pila[0] = nullptr;
//   pila[1] = 0;

//   return pila;
// }

// void apilar(void *pila, void *dato){
//     void **ptr = (void **)pila;
    
//     //nuevo nodo
//     void **nuevoNodo = new void *[2];
//     nuevoNodo[1] = dato;
//     nuevoNodo[0] = ptr[0];

//     ptr[0] = nuevoNodo;
    
//     int *longitud = (int *)ptr[1];
//     (*longitud)++; void **auxPila = (void **)pila;
// }

// void imprimepila(void *pilafin,void (*imprime)(ofstream &,void *),const char *nom){
//     ofstream arch(nom, ios::out);

//     void **ptr = (void **)pilafin;
//     void **nodo = (void **)ptr[0];
    
//     // while(nodo){
//     //     cout<<"holi"<<endl;
//     //     imprime(arch, nodo[1]);
//     //     nodo = (void **)nodo[0];
//     // }
// }

