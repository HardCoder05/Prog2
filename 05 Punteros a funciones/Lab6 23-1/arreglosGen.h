
/* 
 * File:   arreglosGen.h
 * Author: 
 *
 * Created on 2 de mayo de 2024, 11:04 AM
 */

#ifndef ARREGLOSGEN_H
#define ARREGLOSGEN_H
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
#include<cstring>

void llenarArreglo(void *&arregloHeroes,int &cantHeroes,const char *nom);
void *leerHeroes(ifstream &arch);
char *leerCadena(ifstream &arch,int cantCar,char del);
int cmpMulticriterioVoid(const void *a,const void *b);

#endif /* ARREGLOSGEN_H */

