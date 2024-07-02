
/* 
 * File:   PilaConEnteros.h
 * Author: 
 *
 * Created on 28 de abril de 2024, 03:31 PM
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include<fstream>
#include<iomanip>
using namespace std;

void *leenumero(ifstream &arch);
double calculanumero(void *dato);
int cmpnumero(const void *a,const void *b);
void imprimenumero(void *a,ofstream &arch);

#endif /* PILACONENTEROS_H */

