
/* 
 * File:   Furgon.cpp
 * Author: 
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

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"Filas: "<<setw(12)<<filas<<endl;
    arch<<"Puertas: "<<setw(10)<<puertas<<endl;
    arch<<"Pedidos:"<<endl;
    
    if(depositos.empty()){
        arch<<"No hay pedidos"<<endl;
    }else{
        list<Pedido>::iterator it;
        
        for(it = depositos.begin() ; it != depositos.end() ; it++){
            arch<<setw(12)<<(*it).GetCodigo()<<setw(8)<<(*it).GetCantidad()
                <<setw(8)<<(*it).GetPeso()<<endl;
        }
    }
    
    arch<<endl;
}

void Furgon::insertar(char *cod,int cant,double peso){
    if(peso + getCarga_actual() <= getCarga_maxima()){
        Pedido pedido;
        string codigo;
        codigo = cod;
        pedido.SetCodigo(codigo);
        pedido.SetCantidad(cant);
        pedido.SetPeso(peso);
        
        // Encontrar la posición de inserción adecuada
        list<Pedido>::iterator it = depositos.begin();
        while (it != depositos.end() and it->GetPeso() < pedido.GetPeso()) {
            ++it;
        }
        
        depositos.insert(it, pedido);
        setCarga_actual(peso + getCarga_actual());
    }
}


