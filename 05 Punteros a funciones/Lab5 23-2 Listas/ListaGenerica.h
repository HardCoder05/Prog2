
/* 
 * File:   ListaGenerica.h
 * Author: rio88
 *
 * Created on 1 de mayo de 2024, 04:29 PM
 */

#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,
    void* (*lee)(ifstream &),double (*calcular)(void *),const char *nom);
void inicializarLista(void *&lista);
double *obtenerPesoDelCamionPtr(void *pila);
double obtenerPesoDelCamion(void *pila);
void actualizarPesoDelCamion(void *pila, double peso_pedido);
void crearLista(ifstream &arch,void *&lista,void* (*lee)(ifstream &), 
    int (*comp)(const void*, const void*));
void insertaEnLista(void *&lista,void * dato);
void muestracamiones(void *flota,int numcamiones,
    void (*imprime)(void *,ofstream &),const char *nom);

#endif /* LISTAGENERICA_H */

