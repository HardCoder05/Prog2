
#include "PilaConEnteros.h"

void *leenumero(ifstream &arch){
    int num;
    arch>>num;
    if(arch.eof()) return nullptr;
    int *numero = new int(num);
    return (void *)numero;
}

int cmpnumero(const void *a,const void *b){
    int *num1, *num2; 
    void **aux1 = (void **)a; 
    void **aux2 = (void **)b; 
    
    num1 = (int *)*aux1;
    num2 = (int *)*aux2;
    
    return *num1 - *num2; 
}

void imprimenumero(ofstream &arch,void *dato){
    // void **aux1 = (void **)dato;  
    // int *num = (int *)*aux1;

    int *num = (int *)dato;
    arch<<*num<<endl;
}
