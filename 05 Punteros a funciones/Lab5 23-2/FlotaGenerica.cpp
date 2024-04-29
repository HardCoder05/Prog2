
#include "FlotaGenerica.h"

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,
    void* (*lee)(ifstream &),double (*calcular)(void *),const char *nom){
    ifstream arch(nom, ios::in);
    
    void **flota_arr = new void *[numcamiones];
    for (int i = 0; i < numcamiones; i++) inicializarPila(flota_arr[i]);

    int n_camion = 0;
    while (true){
        void *dato = lee(arch);
        if (dato == nullptr) break;

        double peso_camion = obtenerPesoDelCamion(flota_arr[n_camion]);
        double peso_pedido = calcular(dato);

        if ((peso_camion + peso_pedido) > pesomaximo){
            n_camion++;
            if (n_camion >= numcamiones) break;
        }
        
        push(flota_arr[n_camion], dato);
        actualizarPesoDelCamion(flota_arr[n_camion], peso_pedido);
    }

    flota = (void *)flota_arr;
}

void inicializarPila(void *&pila){
    double *peso_camion = new double;
    *peso_camion = 0.0;

    void **cabeza = new void *[2];
    cabeza[0] = nullptr;
    cabeza[1] = (void *)peso_camion;

    pila = (void *)cabeza;
}

void push(void *pila, void *dato){
    void **nuevo_nodo = new void *[2]; //nueva cabeza
    nuevo_nodo[0] = nullptr;
    nuevo_nodo[1] = dato;

    void **cabeza = (void **)pila;
    nuevo_nodo[0] = cabeza[0];
    cabeza[0] = nuevo_nodo;
}

double *obtenerPesoDelCamionPtr(void *pila){
    void **cabeza = (void **)pila;
    double *peso_camion_ptr = (double *)cabeza[1];
    return peso_camion_ptr;
}

double obtenerPesoDelCamion(void *pila){
    return *obtenerPesoDelCamionPtr(pila);
}

void actualizarPesoDelCamion(void *pila, double peso_pedido){
    double *peso_camion = obtenerPesoDelCamionPtr(pila);
    *peso_camion += peso_pedido;
}

void muestracamiones(void *flota,int numcamiones,
    void (*imprime)(void *,ofstream &),const char *nom){
    ofstream arch(nom, ios::out);
    arch.precision(2);
    arch<<fixed;

    void **flota_arr = (void **)flota;
    for (int i = 0; i < numcamiones; i++){
        void *pila = flota_arr[i];
        arch << left << "Camion " << ((i <= 9) ? "0" : "") << i + 1
            << setw(5) << ":" << setw(10) << left << "Peso: "
            << setw(10) << right << obtenerPesoDelCamion(pila) << endl;

        void **ultimo_nodo = (void **)((void **)pila)[0];
        while (true){
            imprime(ultimo_nodo[1], arch);
            if (ultimo_nodo[0] == nullptr) break;
            ultimo_nodo = (void **)ultimo_nodo[0];
        }
        arch << endl;
    }
}

