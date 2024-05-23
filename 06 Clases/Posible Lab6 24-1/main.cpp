
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 23 de mayo de 2024, 09:54 AM
 */

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include "Cliente.h"
#include "Libro.h"
#include "LibroSolicitado.h"

int main(int argc, char** argv) {
    Cliente cli[200]{};
    
    ifstream arch("Clientes.csv", ios::in);
    int cantCli = 0;
    while(true){
        if(arch>>cli[cantCli] == false) break;
        cantCli++;
    }
    
//    for(int j=0 ; j<i ; j++){
//        char nombre[60];
//        int dni = cli[j].GetDni();
//        cli[j].GetNombre(nombre);
//        cout<<left<<setw(10)<<dni<<setw(40)<<nombre<<right<<endl;
//    }
    
    
    Libro lib[300]{};
    ifstream archLib("Libros.csv", ios::in);
    int cantLib = 0;
    while(true){
        if(archLib>>lib[cantLib] == false) break;
        cantLib++;
    }
    
//    for(int j=0 ; j<cantLib ; j++){
//        char cod[8], titulo[80], autor[60];
//        lib[j].GetCodigo(cod);
//        lib[j].GetTitulo(titulo);
//        lib[j].GetAutor(autor);
//        
//        cout<<left<<setw(10)<<cod<<setw(60)<<titulo<<setw(40)<<autor<<right<<
//            setw(10)<<lib[j].GetPrecio()<<setw(10)<<lib[j].GetStock()<<endl;
//    }
    
    ifstream archPed("Pedidos.txt", ios::in);
    int numPed, dni;
    char c, codLib[8];
    while(true){
        archPed>>numPed;
        if(archPed.eof()) break;
        archPed>>c>>dni>>c;
        LibroSolicitado libSoli;
        libSoli.SetNumeroDePedido(numPed);
        while(true){
            archPed>>codLib;
            libSoli.SetCodigoDelLibro(codLib);
            
            for(int i=0 ; i<cantLib ; i++){
                bool aten = libSoli>>lib[i];
            }
            
            for(int i=0 ; i<cantCli ; i++){
                if(cli[i].GetDni() == dni){
                    bool atendid = cli[i]<<libSoli;
                }
            }
            
            if(archPed.get() == '\n') break;
        }
    }
    
//    for(int j=0 ; j<cantLib ; j++){
//        char cod[8], titulo[80], autor[60];
//        lib[j].GetCodigo(cod);
//        lib[j].GetTitulo(titulo);
//        lib[j].GetAutor(autor);
//        
//        cout<<left<<setw(10)<<cod<<setw(60)<<titulo<<setw(40)<<autor<<right<<
//            setw(10)<<lib[j].GetPrecio()<<setw(10)<<lib[j].GetStock()<<endl;
//    }
    
//    for(int j=0 ; j<cantCli ; j++){
//        ++cli[j];
//    }
    
    for(int j=0 ; j<cantCli ; j++){
        cli[j]++;
    }
    
    ofstream archRepLib("ReporteLibros.txt", ios::out);
    for(int i=0 ; i<cantLib ; i++){
        archRepLib<<lib[i];
    }
    
    ofstream archRepCli("ReporteClientes.txt", ios::out);
    for(int i=0 ; i<cantCli ; i++){
        archRepCli<<cli[i];
    }
    
    return 0;
}

