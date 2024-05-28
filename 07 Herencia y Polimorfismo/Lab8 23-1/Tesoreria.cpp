
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Tesoreria.h"

void Tesoreria::cargaescalas(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cod;
    double precio;

    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>precio;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(precio);
    }
}

void Tesoreria::cargaalumnos(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    //S,202121791,GONZALES/VELASQUEZ/WALTER,25,1
    //P,202115802,MINAYA/AMEZQUITA/RHONY-JAIME,20,5
    //V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,323R33-2,3
    char tipo;
    int nP=0, nS=0, nV=0;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        switch (tipo){
        case 'P':
            lpresencial[nP].leerDatos(arch);
            nP++;
            break;
        case 'S':
            lsemipresencial[nS].leerDatos(arch);
            nS++;
            break;
        case 'V':
            lvirtual[nV].leerDatos(arch);
            nV++;
            break;
        }
    }
    // lpresencial[nP].SetCodigo(0);
    // lsemipresencial[nS].SetCodigo(0);
    // lvirtual[nV].SetCodigo(0);
}

void Tesoreria::actualiza(double cred) {
    int esc;
    double precioEsc;
    for(int i=0; lpresencial[i].GetCodigo(); i++){
        esc = lpresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lpresencial[i].actualiza(cred*precioEsc);
    }
    for(int i=0; lsemipresencial[i].GetCodigo(); i++){
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lsemipresencial[i].actualiza(cred*precioEsc);
    }
    for(int i=0; lvirtual[i].GetCodigo(); i++){
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lvirtual[i].actualiza(cred*precioEsc);
    }
}

void Tesoreria::imprime(const char*nombArch) {
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<right
       <<setw(3)<<"Escala"<<right<<setw(12)<<"Licencia"
       <<setw(8)<<"Total"<<endl;
    imprimeLinea(arch,'=',80);
    for(int i=0; lpresencial[i].GetCodigo(); i++)
        lpresencial[i].imprime(arch);

    for(int i=0; lsemipresencial[i].GetCodigo(); i++)
        lsemipresencial[i].imprime(arch);

    for(int i=0; lvirtual[i].GetCodigo(); i++)
        lvirtual[i].imprime(arch);
}

void Tesoreria::imprimeLinea(ofstream&arch, char car, int nd) {
    for(int i=0; i<nd; i++)
        arch.put(car);
    arch<<endl;
}

void Tesoreria::muestraEscala(int pos) {
    cout<<lescala[pos].GetCodigo()<<','<<lescala[pos].GetPrecio()<<endl;
}


