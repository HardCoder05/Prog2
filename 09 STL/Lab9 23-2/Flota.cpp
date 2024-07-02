
/* 
 * File:   Flota.cpp
 * Author: 
 * 
 * Created on 16 de junio de 2024, 04:57 PM
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv", ios::in);
    
    NVehiculo nodo;
    while(true){
        nodo.leer(arch);
        if (arch.eof()) break;
        vflota.push_back(nodo);
    }
    
    sort(vflota.begin(), vflota.end());
}

void Flota::muestracarga(){
    ofstream arch("ReporteFinal.txt", ios::out);
    
//    for(vector<NVehiculo>::iterator it = vflota.begin() ; it != vflota.end() ; it++){
//        (*it).imprimir(arch);
//    }
    
//    for(int i=0 ; i < vflota.size() ; i++){
//        vflota[i].imprimir(arch);
//    }
    
    for(auto aux : vflota) aux.imprimir(arch);
}

void Flota::cargapedidos(){
    ifstream arch("Pedidos3.csv", ios::in);
    
    int cliente, cantidad;
    char codProd[10], c;
    double peso;
    NPedido pedido;
    while(true){
        arch>>cliente;
        if (arch.eof()) break;
        arch.get();
        arch.getline(codProd, 10, ',');
        arch>>cantidad>>c>>peso;
        
        int pos = buscarVehiculo(cliente);
        if(pos != -1){
            pedido.SetCodigo(codProd);
            pedido.SetCantidad(cantidad);
            pedido.SetPeso(peso);
            vflota[pos].carga(pedido);
        }
    }
}

int Flota::buscarVehiculo(int cliente){
    for(int i=0 ; i < vflota.size() ; i++){
        if(vflota[i].comparar(cliente)) return i;
    }

    return -1;
}


