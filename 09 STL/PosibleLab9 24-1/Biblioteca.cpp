
/* 
 * File:   Biblioteca.cpp
 * Author: 
 * 
 * Created on 20 de junio de 2024, 12:43 PM
 */

#include "Biblioteca.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga(){
    ifstream arch("Estantes2.csv", ios::in);
    
    Estante estante;
    while(true){
        estante.leer(arch);
        if(arch.eof()) break;
        AEstantes.push_back(estante);
    }
}

void Biblioteca::llena(){
    ifstream arch("Libros3.csv", ios::in);
    
    int capacidades[10] = {}, i = 0;
    vector<Estante>::iterator it;
    for(it = AEstantes.begin() ; it != AEstantes.end(); it++){
        capacidades[i] = (*it).GetCapacidad();
        i++;
    }
    
    char tipo;
    Libro *libro;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        if(tipo == 'N'){
            libro = new Novela;
        }else if(tipo == 'E'){
            libro = new Enciclopedia;
        }else if(tipo == 'R'){
            libro = new Revista;
        }
        
        libro->lee(arch);
        //cout<<"Libro leido   ";
        meterLibros(libro, capacidades);
    }
}

void Biblioteca::meterLibros(Libro *libro,int *capacidades){
    int i = 0;
    vector<Estante>::iterator it;
    for(it = AEstantes.begin() ; it != AEstantes.end(); it++){
        if(libro->GetPeso() <= capacidades[i] ){
            (*it).meter(libro);
            capacidades[i] -= libro->GetPeso();
            //cout<<"Libro insertado"<<endl;
            break;
        }
        
        i++;
    }
}

void Biblioteca::baja(){
    
}

void Biblioteca::muestra(){
    ofstream arch("ReporteInvertido.txt", ios::out);
    
    vector<Estante>::iterator it;
    for(it = AEstantes.begin() ; it != AEstantes.end(); it++){
        (*it).mostrar(arch);
    }
}


