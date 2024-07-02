
/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: 
 *
 * Created on 5 de mayo de 2024, 10:46 AM
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5

void cargarProductos(void *&productos,const char *nom);
void *leerProducto(ifstream &arch);
void incrementarProd(void ***&prod,int &cap,int &nDat);
int cmpProd(const void *a,const void *b);
void pruebaDeCargaDeProductos(void *productos,const char *nom);

#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

