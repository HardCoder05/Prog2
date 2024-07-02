
/* 
 * File:   Flota.cpp
 * Author: 
 * 
 * Created on 16 de junio de 2024, 04:57 PM
 */

#include "Flota.h"
#include "Furgon.h"
#include "Camion.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv", ios::in);
    
    char tipo;
    Vehiculo *vehiculo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        if(tipo == 'F'){
            vehiculo = new Furgon;
        }else if(tipo == 'C'){
            vehiculo = new Camion;
        }
        
        vehiculo->lee(arch);
        vehiculos[vehiculo->getPlaca()] = vehiculo;
    }
    
}

void Flota::muestracarga(){
    ofstream arch("ReporteFinal.txt", ios::out);
    
    string placas[5] = {"A1Q-612", "D9A-711", "O8J-848", "Q5S-871", "Z4L-514"};
    
    for(int i=0 ; i<5 ; i++){
        vehiculos[placas[i]]->imprime(arch);
    }
}

void Flota::cargar_pedidos(){
    ifstream arch("Pedidos4.csv", ios::in);
    
    char placa[10], cod[10], c;
    int cant;
    double peso;
    string clave;
    
    while(true){
        arch.getline(placa, 10, ',');
        if(arch.eof()) break;
        arch.getline(cod, 10, ',');
        arch>>cant>>c>>peso;
        arch.get();
        
        clave = placa;
        vehiculos[clave]->insertar(cod, cant, peso);
    } 
}


