
/* 
 * File:   FlotaGenerica.h
 * Author: 
 *
 * Created on 28 de abril de 2024, 03:55 PM
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,
    void* (*lee)(ifstream &),double (*calcular)(void *),const char *nom);
void inicializarPila(void *&pila);
void push(void *pila, void *dato);
double *obtenerPesoDelCamionPtr(void *pila);
double obtenerPesoDelCamion(void *pila);
void actualizarPesoDelCamion(void *pila, double peso_pedido);

void muestracamiones(void *flota,int numcamiones,
    void (*imprime)(void *,ofstream &),const char *nom);

#endif /* FLOTAGENERICA_H */

