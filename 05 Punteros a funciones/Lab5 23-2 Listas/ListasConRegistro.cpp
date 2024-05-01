
#include "ListasConRegistros.h"
#include "ListaGenerica.h"

void *leeregistro(ifstream &arch){
    char *cod, c;
    int dni, cant, *cantidad;
    double peso, *pes;
    
    cod = leerCadena(arch, 8, ',');
    if(arch.eof()) return nullptr;
    arch>>dni>>c>>cant>>c>>peso;
    arch.get();
    
    cantidad = new int;
    *cantidad = cant;
    pes = new double;
    *pes = peso;
    
    void **reg = new void*[3];
    reg[0] = cod;
    reg[1] = cantidad;
    reg[2] = pes;
    
    return reg;
}

char *leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}

double calcularegistro(void *dato){
    void **registro = (void **)dato;
    double *peso = (double *)registro[2];
    return *peso;
}

int cmpregistro(const void *a,const void *b){
    void **camion_a = (void **)a;
    void *camA = (void *)camion_a[0];
    void **camion_b = (void **)b;
    void *camB = (void *)camion_b[0];
    
    double peso_a = obtenerPesoDelCamion(camA);
    double peso_b = obtenerPesoDelCamion(camB);
    
    return peso_b - peso_a;
}

void imprimeregistro(void *a, ofstream &arch) {
    void **reg = (void**)a; 
    char *cod = (char*)reg[0];
    int *cant = (int*)reg[1]; 
    double *peso = (double*)reg[2];
    
    arch << setw(15) << cod << setw(10) << *cant << setw(10) << *peso << endl;
}

