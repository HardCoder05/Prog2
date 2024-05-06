
#include "PilaConRegistros.h"

void cargaarregloo(void *arreglo,int (*cmp)(const void*,const void*), void* (*lee)(ifstream &),const char *nom){
    ifstream arch(nom, ios::in);

    void *dato, **ptr = nullptr;
    int cantDat = 0, cap = 0;
    while(true){
        dato = lee(arch);
        if(dato == nullptr) break;
        if(cantDat == cap) incrementarEspacios(ptr, cap, cantDat);
        ptr[cantDat - 1] = dato; // Incrementar el contador antes de asignar el dato
        cantDat++;
    }

    arreglo = ptr;

    qsort(arreglo, cantDat-1, sizeof(void *), cmp);

    void **aux = (void **)arreglo;  
    for(int i = 0; aux[i]; i++){
        void **registro = (void **)aux[i];
        int *cod = (int *)registro[0];
        char *nom = (char *)registro[1];
        double *peso = (double *)registro[2];
        cout<<setw(5)<<*cod<<setw(60)<<nom<<setw(10)<<*peso<<endl;
    }

}

void incrementarEspacios(void **&ptr, int &cap, int &cantDat){
    cap += INCREMENTO;

    if(ptr == nullptr){
        ptr = new void*[cap]{};
        cantDat = 1;
    }else{
        void **aux = new void *[cap]{};
        for(int i = 0; i < cantDat; i++){
            aux[i] = ptr[i];
        }
        delete ptr;
        ptr = aux;
    }
}

void *leeregistro(ifstream &arch){
    int cod;
    char *nom, c;
    double peso;

    arch>>cod;
    if(arch.eof()) return nullptr;
    arch>>c; // Leer la coma
    nom = leerCadena(arch, 60, ',');
    arch>>peso;

    int *codigo = new int(cod);
    double *pes = new double(peso);

    void **registro = new void*[3];
    registro[0] = codigo;
    registro[1] = nom;
    registro[2] = pes;

    return registro;
}

char *leerCadena(ifstream &arch, int tam, char delim){
    char cadena[tam], *ptr;
    arch.getline(cadena, tam, delim);
    if(arch.eof()) return nullptr; 
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}

int cmpregistro(const void *a, const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    void **medI = (void **)ai[0], **medF = (void **)bi[0];
    double *pesoi = (double *)medI[2], *pesof = (double *)medF[2];

    if (*pesoi < *pesof) return -1;
    if (*pesoi > *pesof) return 1;
    return 0;
}












