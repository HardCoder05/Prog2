
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5

void cargaarregloo(void *arreglo,int (*cmp)(const void*,const void*), void* (*lee)(ifstream &),const char *nom);
void incrementarEspacios(void **&ptr, int &cap, int &cantDat);
void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int tam, char delim);
int cmpregistro(const void *a, const void *b);



