
#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    int d, *dato;
    arch >> d;
    if(arch.eof())return nullptr;
    dato = new int;
    *dato = d;
    return dato;
}

int calculanumero(int pesoMax,int dato){
    //return pesoMax - dato;
}

int cmpnumero(const void *a,const void *b){
    int *ai = (int *)a, *bi = (int*)b;
    return *ai - *bi;
}
 
void imprimenumero(void *a,ofstream &arch){
    int *ai = (int*)a;
    arch<<setw(6)<<*ai;
}

