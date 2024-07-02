
/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: 
 *
 * Created on 11 de abril de 2024, 08:21 AM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char *,char ***&, int *&,double *&);
char **leerProd(ifstream &);
char* leerCadena(ifstream &,int ,char );
void cargaarreglos(char ***&,int *&,double *&,char ***,int *,double *,int );
void pruebaDeLecturaDeProductos(const char *,char ***, int *,double *);

void lecturaDePedidos(const char *,int *&,char ***&,int ***&);
void cargaarreglos(int *&,char ***&,int ***&,int *,char ***,int ***,int *,int );
void carganivelinterno(char **&,int **&,char **,int **,int );
void agregarpedido(char **,int **,int &,int ,int ,char *);
void agregarfecha(int *,char ***,int ***,int ,int *, int &,int &);
int  buscafecha(int ,int *,int );
void pruebaDeLecturaDePedidos(const char *, int *,char ***, int ***);

void reporteDeEnvioDePedidos (const char *,char ***,int *&,double *,int *,
    char ***,int ***);
void imprimirPedido(ofstream &, char *,char ***,int ,double *,int *&,double &,double &);
int buscarProd(char ***,char *);
void imprimirEncabezado(ofstream &);
void imprimirFecha(ofstream &,int );
void imprimirResumen(ofstream &,double ,double );
void imprimirTotales(ofstream &,double ,double ,double &,double &);
void imprimirLinea(ofstream &,char );

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

