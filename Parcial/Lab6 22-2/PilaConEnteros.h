#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define INCREMENTO 5

void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void *),void* (lee)(ifstream &),const char *nom);
void incrementarEspacios(void **&ptr, int &cap, int &cantDat);
void* leenumero(ifstream &arch);
int cmpnumero(const void *a,const void *b);

