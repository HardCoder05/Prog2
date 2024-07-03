
/* 
 * File:   GrafoDirigido.cpp
 * Author: 
 * 
 * Created on 3 de julio de 2024, 04:00 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "GrafoDirigido.h"

void GrafoDirigido::agregarArista(const class Ciudad &origen,const class 
    Arista &destino) {
    adyacencias[origen].push_back(destino);
}

void GrafoDirigido::imprimeGrafo() {
    for(auto c: adyacencias){
        class Ciudad ciudad = c.first;
        cout<<"Ciudad: ";
        ciudad.imprime();
        cout<<"Conectada con: "<<endl;
        for(auto v: c.second)
            v.imprimeArista();
    }
}

