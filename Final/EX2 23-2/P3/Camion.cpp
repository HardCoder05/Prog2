
/* 
 * File:   Camion.cpp
 * Author: 
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
    
    if(depositos.size() == 0){
        arch<<"No hay pedidos"<<endl;
    }else{
        vector<Pedido>::iterator it;
        
        for(it = depositos.begin() ; it != depositos.end() ; it++){
            arch<<(*it).GetCodigo()<<setw(10)<<(*it).GetCantidad()<<
                setw(8)<<(*it).GetPeso()<<endl;
        }
    }
    arch<<endl;
}

void Camion::insertar(char *cod,int cant,double peso){
    if(peso + getCarga_actual() <= getCarga_maxima() and depositos.size() < 5){
        Pedido pedido;
        string codigo;
        codigo = cod;
        pedido.SetCodigo(codigo);
        pedido.SetCantidad(cant);
        pedido.SetPeso(peso);
        depositos.push_back(pedido);
        setCarga_actual(peso + getCarga_actual());
    }
}


