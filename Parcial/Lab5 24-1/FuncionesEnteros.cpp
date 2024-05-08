
#include "FuncionesEnteros.h"

void* leenum(ifstream &arch){
    int *num = new int;
    arch >> *num;
    if(arch.eof()) return nullptr;
    return (void *)num;
}

void imprimenum(ofstream &arch, void *dato){
    int *num = (int *)dato;
    arch << *num << endl;
    
}

int cmpNum(const void *a, const void *b){
    int *num1 = (int *)a;
    int *num2 = (int *)b;
    return *num1 - *num2;
}

