
/* 
 * File:   ColaConEnteros.h
 * Author: 
 *
 * Created on 5 de mayo de 2024, 11:47 AM
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H
#include<fstream>
using namespace std;

void cargaEnteros(void *&cola,void* (*leenumero)(ifstream &),const char *nom);
void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void *),
    const char *nom);

void *leenumero(ifstream &arch);
void imprimenumero(ofstream &arch,void *dato);

#endif /* COLACONENTEROS_H */

