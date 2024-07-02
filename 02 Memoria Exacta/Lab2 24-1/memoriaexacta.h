
/*
 * File:   memoriaexacta.h
 * Author: 
 *
 * Created on 16 de abril de 2024, 05:53 PM
 */

#ifndef MEMORIAEXACTA_H
#define MEMORIAEXACTA_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#include "AperturaDeArchivos.h"
#define NO_ENCONTRADO -1

void lecturaDeLibros(const char *,char ***&,int **&);
char **leerLib(ifstream &);
char* leerCadena(ifstream &,int ,char );
void pruebaDeLecturaDeLibros(const char *,char ***,int **);

void atencionDePedidos(const char *,char ***,int **&,int **&,char ***&,bool **&);
void asignarMemoriaBuffers(bool **,int **,char ***,int ,int ,int *,int **&,
    char ***&,bool **&);
void recortarCliente(int *&buffClientes);
void recortarPedidos(char **&buffPedLibros, bool *&buffAtendidos,
    int cantSolicitados);
int buscarCli(int ,int **,int );
void agregarDni(int ,int **,int &,int &);
void agregarPedidos(int ,int **,int );
void agregarLibros(char *,char **,int &,bool *,int **&,char ***);
int buscarLibro(char *,char ***);

void reporteDeEntregaDePedidos (const char *,int **, char ***,bool **);
void imprimirLibros(ofstream &,char ***,bool **,int );
void imprimirEncabezado(ofstream &);
void imprimirSubtitulos(ofstream &);
void imprimirLinea(ofstream &,char );

#endif /* MEMORIAEXACTA_H */

