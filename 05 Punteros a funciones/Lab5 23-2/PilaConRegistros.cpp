
#include "PilaConRegistros.h"

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
    void **regI = (void**)a, **regK = (void**)b; //apuntamos al registro
    double *pesoI = (double *)regI[1], *pesoK = (double *)regK[1];
    return *pesoK - *pesoI;
}

void imprimeregistro(void *a,ofstream &arch){
    void **reg = (void **)a; //apuntamos al registro
    char *cod = (char *)reg[0];
    int *cant = (int *)reg[1];
    double *peso = (double *)reg[2];
    
    arch<<setw(15)<<cod<<setw(10)<<*cant<<setw(10)<<*peso<<endl;
}

