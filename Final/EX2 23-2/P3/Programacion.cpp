
/* 
 * File:   Programacion.cpp
 * Author: 
 * 
 * Created on 3 de julio de 2024, 09:39 AM
 */

#include "Programacion.h"

Programacion::Programacion() {
}

Programacion::Programacion(const Programacion& orig) {
}

Programacion::~Programacion() {
}

void Programacion::cargavehiculos(){
    fVehiculos.cargaflota();
    fVehiculos.cargar_pedidos();
}

void Programacion::cargaprogramacion(){
    map<string, Vehiculo *>::iterator it;
    
    for(it = fVehiculos.vehiculos.begin() ; it != fVehiculos.vehiculos.end() ; it++ ){
        Vehiculo *vehiculo = fVehiculos.vehiculos[(*it).first];
        ADespachos.insertar(vehiculo);
    }
}

void Programacion::reducevehiculos(int num){
    ADespachos.eliminarHijos(num);
}

void Programacion::muestraprogramacion(){
    ofstream arch("ReporteFinal.txt", ios::out);
    ADespachos.mostrarEnOrden(arch);
}

