
/* 
 * File:   Lista.cpp
 * Author: 
 * 
 * Created on 20 de junio de 2024, 12:36 PM
 */

#include "Lista.h"
#include "Nodo.h"

Lista::Lista() {
    peso = 0;
    ini = nullptr;
    fin = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::insertar(Libro *libro){
    Nodo *nuevonodo = new Nodo(libro);
    
    if(ini == nullptr){
        ini = nuevonodo;
        fin = nuevonodo;
    }else{
//        Nodo *ultimonodo = ini;
//        while(ultimonodo->sig){
//            ultimonodo = ultimonodo->sig;
//        }
//        ultimonodo->sig = nuevonodo;
        fin->sig = nuevonodo;
        nuevonodo->ant = fin;
        fin = nuevonodo;
    }
    
    /* insertar al inicio
    if (ini == nullptr) {
        ini = nuevonodo;
        fin = nuevonodo;
    } else {
        nuevonodo->sig = ini;
        ini->ant = nuevonodo;
        ini = nuevonodo;
    }*/
    
    peso += libro->GetPeso();
}

//void Lista::pop() {
//    if (ini == nullptr) {
//        // La lista está vacía, no hay nada que eliminar.
//        return;
//    }
//
//    Nodo* nodoAEliminar = ini;
//    ini = ini->sig;
//
//    if (ini != nullptr) {
//        ini->ant = nullptr;
//    } else {
//        // Si la lista estaba formada por un solo nodo
//        fin = nullptr;
//    }
//
//    peso -= nodoAEliminar->libro->GetPeso();
//    delete nodoAEliminar->libro; // Si `Libro` fue alocado dinámicamente.
//    delete nodoAEliminar;
//}

void Lista::mostrar(ofstream &arch){
    Nodo *cabeza = ini;
    Nodo *final = fin;
    
    if(final){
        while(final){
//            cabeza->plibro->imprime(arch);
//            cabeza = cabeza->sig;
            final->plibro->imprime(arch);
            final = final->ant;
        }
    }else{
        arch<<"No hay libros"<<endl;
    }
}


