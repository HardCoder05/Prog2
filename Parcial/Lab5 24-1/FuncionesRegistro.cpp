
#include "FuncionesRegistro.h"

void* leeregistro(ifstream &arch){
    int numPed, dni;
    char *cod, c;

    arch >> numPed;
    if(arch.eof()) return nullptr;
    arch>>c; //leer la coma
    arch >> dni >> c; 
    cod = leeCadena(arch, 8 , '\n');

    int *num = new int(numPed);
    int *dnii = new int(dni);

    void **registro = new void*[3];
    registro[0] = num;
    registro[1] = dnii;
    registro[2] = cod;

    return (void *)registro;
}

char *leeCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;

    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);

    return ptr;
}

void imprimeregistro(ofstream &arch, void *dato){
    void **registro = (void **)dato;
    int *num = (int *)registro[0];
    int *dni = (int *)registro[1];
    char *cod = (char *)registro[2];

    arch << *num << setw(10) << *dni << setw(15) << cod << endl;
}

int cmpReg(const void *dato1, const void *dato2){
    void **registro1 = (void **)dato1;
    void **registro2 = (void **)dato2;
    int *num1 = (int *)registro1[0];
    int *num2 = (int *)registro2[0];

    return *num1 - *num2;
}




















