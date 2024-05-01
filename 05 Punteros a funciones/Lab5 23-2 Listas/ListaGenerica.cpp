
#include "ListaGenerica.h"

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,
    void* (*lee)(ifstream &),double (*calcular)(void *),const char *nom){
    ifstream arch(nom, ios::in);
    
    void **flota_arr = new void *[numcamiones];
    for (int i = 0; i < numcamiones; i++) inicializarLista(flota_arr[i]);

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
        
        insertaEnLista(flota_arr[n_camion], dato);
        actualizarPesoDelCamion(flota_arr[n_camion], peso_pedido);
    }

    flota = (void *)flota_arr;
}

void inicializarLista(void *&lista){
    double *peso_camion = new double;
    *peso_camion = 0.0;
    
    // Crear un nodo para representar la cabeza de la lista
    void **cabeza = new void *[2];
    cabeza[0] = nullptr;  // Apuntador al siguiente nodo, inicialmente vacío
    cabeza[1] = peso_camion;  // Datos del nodo
    
    // Asignar la cabeza de la lista a la variable de lista
    lista = (void *)cabeza;
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

void insertaEnLista(void *&lista,void * dato){
    void **nuevo_nodo = new void *[2]; // Nuevo nodo a insertar
    nuevo_nodo[0] = nullptr; // Siguiente nodo inicialmente vacío
    nuevo_nodo[1] = dato; // Almacenar el dato en el nodo
    
    void **nodo_actual = (void **)lista; // Nodo actual apunta a la cabeza de la lista
    
    // Buscar el último nodo en la lista
    while (nodo_actual[0] != nullptr) {
        nodo_actual = (void **)nodo_actual[0];
    }
    
    // Una vez que encontramos el último nodo, lo enlazamos con el nuevo nodo
    nodo_actual[0] = nuevo_nodo;
}

void muestracamiones(void *flota,int numcamiones,
    void (*imprime)(void *,ofstream &),const char *nom){
    ofstream arch(nom, ios::out);
    arch.precision(2);
    arch<<fixed;
    
    void **flota_arr = (void **)flota;
    for (int i = 0; i < numcamiones; i++){
        void *lista = flota_arr[i];
        arch << left << "Camion " << ((i < 9) ? "0" : "") << i + 1
            << setw(5) << ":" << setw(10) << left << "Peso: "
            << setw(10) << right << obtenerPesoDelCamion(lista) << endl;
        
        void **listaCampos = (void **)lista;
        while(listaCampos){
            imprime(listaCampos[1], arch); 
            listaCampos = (void **)(listaCampos[0]); 
        }
        arch<<endl;
    }
}

