
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

void cargapila(void *&pila,void *arreglo){
    void **ptr = (void **)arreglo;
    
    //constuir la pila
    pila = crearPila();

    for(int i = 0; ptr[i]; i++){
        void *dato = ptr[i];
        apilar(pila, dato);
    }
}

void *crearPila(){
    void **pila = new void *[2];
    pila[0] = nullptr; // Tope de la pila
    int *cant = new int(0);
    pila[1] = cant; // Contador de elementos
    return pila;
}

void *crearNodoPila(void *elemento, void *sig){
    void **nodoPila = new void *[2];
    nodoPila[1] = elemento; // Elemento
    nodoPila[0] = sig; // Siguiente
    return nodoPila;
}

void apilar(void *pila, void *elemento){
    void **auxPila = (void **)pila; // Convertir la pila a un arreglo de punteros
    void **tope = (void **)auxPila[0]; // Obtener el tope de la pila
    void **nuevoNodo = (void **)crearNodoPila(elemento, tope); // Crear un nuevo nodo con el elemento y el tope de la pila
    auxPila[0] = nuevoNodo; // Actualizar el tope de la pila

    int *cant = (int *)auxPila[1]; // Obtener el contador de elementos
    (*cant)++; // Incrementar el contador de elementos
}

void* desapilar(void *pila){
    void **auxPila = (void **)pila; // Convertir la pila a un arreglo de punteros
    void **tope = (void **)auxPila[0]; // Obtener el tope de la pila
    void *elemento = tope[1]; // Obtener el elemento del tope de la pila
    void **sig = (void **)tope[0]; // Obtener el siguiente nodo
    delete tope; // Eliminar el nodo
    auxPila[0] = sig; // Actualizar el tope de la pila

    int *cant = (int *)auxPila[1]; // Obtener el contador de elementos
    (*cant)--; // Decrementar el contador de elementos
    return elemento; // Retornar el elemento
}

void imprimepila(void *pila,void (*imprime)(ofstream &,void *),const char *nom){
    ofstream arch(nom, ios::out);

    void **auxPila = (void **)pila; // Convertir la pila a un arreglo de punteros
    void **tope = (void **)auxPila[0]; // Obtener el tope de la pila
    int *cant = (int*)auxPila[1]; // Obtener el contador de elementos
    //cout<<*cant<<endl; // Imprimir la cantidad de elementos
    
    arch<<"Codigo"<<setw(28)<<"Descripcion del Producto"<<setw(27)<<"Peso Caja"<<endl;
    for(int i = 0; i < 62; i++) arch<<"=";
    arch<<endl;
    for(int i = 0; i < *cant; i++){ // Iterar sobre la pila
        void *dato = tope[1];
        imprime(arch, dato);
        tope = (void **)tope[0]; // Obtener el siguiente nodo
    }

    // while(tope){
    //     cout << "Imprimiendo" << endl;
    //     void *dato = tope[1];
    //     imprime(arch, dato);
    //     tope = (void **)tope[0];
    // }
}


//PARTE PARA MOVER ELEMENTOS DE UNA PILA A OTRA

void muevepila(void *&pilaini,void *&pilafin){
    void *pilaAux;

    pilaAux = crearPila();
    pilafin = crearPila();

    //mover la pila usando Hanoi
    //para necesito el numero de elementos de la pila
    void **ptr = (void **)pilaini;
    int *cant = (int *)ptr[1];
    int n = *cant;
    hanoi(n, pilaini, pilaAux, pilafin);
}
 
void hanoi(int n,void *&pilaini,void *&pilaAux,void *&pilafin){
    if(n == 1){
        void *dato = desapilar(pilaini);
        apilar(pilafin, dato);
    }else{
        hanoi(n-1, pilaini, pilafin, pilaAux);
        void *dato = desapilar(pilaini);
        apilar(pilafin, dato);
        hanoi(n-1, pilaAux, pilaini, pilafin);
    }
}

