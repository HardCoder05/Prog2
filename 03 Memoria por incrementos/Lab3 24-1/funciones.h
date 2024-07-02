
/* 
 * File:   funciones.h
 * Author: 
 *
 * Created on 21 de abril de 2024, 04:44 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#define INCREMENTO 5
#define NO_ENCONTRADO -1
#include "AperturaDeArchivos.h"

void lecturaDeLibros(const char *,char ***&,int **&);
char* leerCadena(ifstream &,int ,char );
void incrementarMemoriaLibros(char ***&,int **&,int &,int &);
void insertarEnMemoriaLibros(char ***&,int **&,char *,char *,char *,int ,int );
void pruebaDeLecturaDeLibros(const char *,char ***,int **);

void atencionDePedidos(const char *,char ***,int **,int **&,char ***&,bool **&);
void llenarClientes(int **&, int , int , int &,int &,int *&,int *&);
int buscarCliente(int **, int );
void incrementarMemoriaClientes(int **&,int &,int &,int *&,int *&);
void insertarPedidos(int *&, int &, int &, int , int );
void incrementarMemoriaPedidos(int *&, int &, int &);
void llenarPedidos(ifstream &, char ***, int **&, char ***&, bool **&, 
    int , int &, int *capacidades, int *numDatos);
void incrementarMemoriaPedidosLibros(char ***&, bool **&, int , int &,int *, int *);    
void insertarLibros(char ***, int **&, char **&, bool *&,int &, int &, char *);
void incrementarMemoriaLibrosPedidos(char **&, bool *&, int &, int &);
void llenarPedidosAtendidos(bool *&, int , char ***, int **&, char *);
int buscarLibro(char ***, char *);

void ordenarPedidosClientes (int **&);
void qSort(int **datos,int izq,int der);
void cambiar(int *&datosI,int *&datosK);

void reporteDeEntregaDePedidos(const char *,int **,char ***,bool **);
void imprimirLibros(ofstream &arch,char ***,bool **,int );
void imprimirEncabezado(ofstream &);
void imprimirSubtitulos(ofstream &);
void imprimirLinea(ofstream &,char );

#endif /* FUNCIONES_H */

