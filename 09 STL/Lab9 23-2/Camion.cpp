
/* 
 * File:   Camion.cpp
 * Author: rio88
 * 
 * Created on 16 de junio de 2024, 04:52 PM
 */

#include "Camion.h"

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"Ejes:"<<setw(14)<<ejes<<endl;
    arch<<"Llantas:"<<setw(11)<<llantas<<endl;
    arch<<"Pedidos:"<<endl;
    
    if(mdeposito.empty()){
        arch<<"No hay pedidos"<<endl;
    }else{
        map<int, NPedido>::iterator it;
        char cod[10];
        
        for(it = mdeposito.begin() ; it != mdeposito.end() ; it++){
            it->second.GetCodigo(cod);
            arch<<setw(12)<<cod<<setw(8)<<it->second.GetCantidad()<<setw(8)
                <<it->second.GetPeso()<<endl;
        }
    }
    arch<<endl;
}

void Camion::cargadeposito(NPedido &pedido){
    if(GetActcarga() + pedido.GetPeso() <= GetMaxcarga() 
            and mdeposito.size() < 5){
        SetActcarga(GetActcarga() + pedido.GetPeso());
        mdeposito[mdeposito.size()] = pedido;
    }
}



