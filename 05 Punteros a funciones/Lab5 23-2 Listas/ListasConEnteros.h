
/* 
 * File:   ListasConEnteros.h
 * Author: 
 *
 * Created on 1 de mayo de 2024, 04:26 PM
 */

#ifndef LISTASCONENTEROS_H
#define LISTASCONENTEROS_H
#include<fstream>
#include<iomanip>
using namespace std;

void *leenumero(ifstream &arch);
double calculanumero(void *dato);
int cmpnumero(const void *a,const void *b);
void imprimenumero(void *a,ofstream &arch);

#endif /* LISTASCONENTEROS_H */

