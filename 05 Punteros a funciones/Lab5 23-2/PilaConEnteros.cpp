
#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    double d, *dato;
    arch >> d;
    if(arch.eof())return nullptr;
    dato = new double;
    *dato = d;
    return (void *)dato;
}

double calculanumero(void *dato){
    double *peso = (double *)dato;
    return *peso;
}

int cmpnumero(const void *a,const void *b){
    int *ai = (int *)a, *bi = (int*)b;
    return *bi - *ai;
}
 
void imprimenumero(void *a,ofstream &arch){
    double peso = calculanumero(a);
    arch<<peso<<endl;
}

