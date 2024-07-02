
/* 
 * File:   funciones.h
 * Author: 
 *
 * Created on 22 de abril de 2024, 05:27 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1

void cargaproductos(void *&);
void *leeProd(ifstream &);
char *leerCadena(ifstream &,int ,char );

void cargaclientes(void *&);
void *leeCli(ifstream &);

void cargapedidos(void *,void *&);
void asignarEspaciosExactos(void *&pedidos,int cantDat);
int buscarCli(void *,int );
void llenarPedidos(void *,char *,int ,void *&,int &);
double obtenerPrecio(void *,char *);

void ordenarClientes(void *clientes);
void ordenarPed(void *cliente);
void qsort(void **clientes,int izq,int der);
bool estanEnDesorden(void *cliI,void *cliIzq);
void qsort2(void **pedidos,int izq,int der);
bool estanEnDesorden2(void *pedI,void *pedIzq);
void cambiar(void *&cl1,void *&cl2);

void imprimereporte(void *clientes);
void imprimirPedidos(ofstream &arch,void **aux);

#endif /* FUNCIONES_H */

