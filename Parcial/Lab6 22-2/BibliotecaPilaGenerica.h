
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5

void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void *),void* (lee)(ifstream &),const char *nom);
void incrementarEspacios(void **&ptr, int &cap, int &cantDat);

void cargapila(void *&pilaini,void *arreglo);
void *crearPila();
void apilar(void *pila, void *dato);
void imprimepila(void *pilafin,void (*imprime)(ofstream &,void *),const char *nom);






