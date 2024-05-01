
/* 
 * File:   ListasConRegistros.h
 * Author: rio88
 *
 * Created on 1 de mayo de 2024, 04:26 PM
 */

#ifndef LISTASCONREGISTROS_H
#define LISTASCONREGISTROS_H
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch,int cantCar,char del);
double calcularegistro(void *dato);
int cmpregistro(const void *a,const void *b);
void imprimeregistro(void *a,ofstream &arch);

#endif /* LISTASCONREGISTROS_H */

