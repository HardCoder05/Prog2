
#include "PilaConRegistros.h"

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

