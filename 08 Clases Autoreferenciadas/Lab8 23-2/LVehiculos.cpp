
/* 
 * File:   LVehiculos.cpp
 * Author: rio88
 * 
 * Created on 9 de junio de 2024, 11:27 AM
 */

#include "LVehiculos.h"
#include "Furgon.h"
#include "Camion.h"

LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
}

LVehiculos::~LVehiculos() {
}

void LVehiculos::agregar(Vehiculo* vehiculo) {
    NodoLista* nuevoNodo = new NodoLista(vehiculo);
    
    if (lini == nullptr) { // Si la lista está vacía
        lini = nuevoNodo;
        lfin = nuevoNodo;
    } else { // Si la lista tiene elementos
        lfin->sig = nuevoNodo;
        lfin = nuevoNodo;
    }
}

void LVehiculos::crear(){
    ifstream arch("Vehiculos.csv", ios::in);
    
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        Vehiculo* nuevoVehiculo;
        if (tipo == 'F') {
            nuevoVehiculo = new Furgon;
        } else if (tipo == 'C') {
            nuevoVehiculo = new Camion;
        }
        
        nuevoVehiculo->lee(arch);
        agregar(nuevoVehiculo);
    }
}

void LVehiculos::cargar(){
    ifstream arch("Pedidos3.csv", ios::in);
    
    int dni, cantidad;
    double peso;
    while(true){
        arch>>dni;
        if(arch.eof()) break;
        arch.get();
        int posCliente = buscarCliente(dni);
        if(posCliente > 0){
            char cod[8], c;
            arch.getline(cod, 8, ',');
            arch>>cantidad>>c>>peso;
            ubicarPos(posCliente, cod, cantidad, peso);
        }else{
            while(arch.get() != '\n');
        }
    }
}

int LVehiculos::buscarCliente(int dni){
    int i = 0;
    NodoLista *cabeza = lini;
    while(cabeza){
        if(cabeza->unidad->GetCliente() == dni) return i;
        cabeza = cabeza->sig;
        i++;
    }
    
    return NO_ENCONTRADO;
}

void LVehiculos::ubicarPos(int pos,char *cod,int cant,double peso){
    int i = 0;
    NodoLista *cabeza = lini;
    while(cabeza){
        if(i == pos) cabeza->unidad->llenar(cod, cant, peso);
        cabeza = cabeza->sig;
        i++;
    } 
}

void LVehiculos::muestra(){
    ofstream arch("ReporteFinal.txt", ios::out);
    
    NodoLista *cabeza = lini;
    while(cabeza){
        cabeza->unidad->imprime(arch); //polimorfismo
        cabeza = cabeza->sig;
    }
}


