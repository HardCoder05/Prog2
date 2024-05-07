
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5

//PARTE PARA LECTURA DE DATOS
void cargaarreglo(void *&arreglo,int (*cmp)(const void*,const void *),void* (lee)(ifstream &),const char *nom);
void incrementarEspacios(void **&ptr, int &cap, int &cantDat);

//PARTE PARA IMPLEMENTACION DE UNA PILA
void cargapila(void *&pila,void *arreglo);
void *crearPila();
void apilar(void *pila, void *elemento);
void *desapilar(void *pila);

//PARTE PARA IMPRIMIR UNA PILA
void imprimepila(void *pila,void (*imprime)(ofstream &,void *),const char *nom);

