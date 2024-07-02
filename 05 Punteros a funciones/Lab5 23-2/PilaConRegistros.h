
/* 
 * File:   PilaConRegistros.h
 * Author: 
 *
 * Created on 28 de abril de 2024, 03:40 PM
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch,int cantCar,char del);
double calcularegistro(void *dato);
int cmpregistro(const void *a,const void *b);
void imprimeregistro(void *a,ofstream &arch);

#endif /* PILACONREGISTROS_H */

