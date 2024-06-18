
/* 
 * File:   Furgon.cpp
 * Author: rio88
 * 
 * Created on 16 de junio de 2024, 04:54 PM
 */

#include "Furgon.h"

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>filas;
    arch.get();
    arch>>puertas;
    arch.get();
}

void Furgon::cargadeposito(NPedido &pedido){
    if(GetActcarga() + pedido.GetPeso() <= GetMaxcarga()){
        SetActcarga(GetActcarga() + pedido.GetPeso());
        //la lista se manejara como una pila
        pdeposito.push_front(pedido);
    }
}

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"Filas: "<<setw(12)<<filas<<endl;
    arch<<"Puertas: "<<setw(10)<<puertas<<endl;
    arch<<"Pedidos:"<<endl;
    
    if(pdeposito.empty()){
        arch<<"No hay pedidos"<<endl;
    }else{
        list<NPedido>::iterator it;
        char cod[10];
        
        for(it = pdeposito.begin() ; it != pdeposito.end() ; it++){
            (*it).GetCodigo(cod);
            arch<<setw(12)<<cod<<setw(8)<<(*it).GetCantidad()<<setw(8)
                <<(*it).GetPeso()<<endl;
        }
        
//        for(NPedido aux:pdeposito)
//            aux.imprimePedido(arch);
    }
    
    arch<<endl;
}


