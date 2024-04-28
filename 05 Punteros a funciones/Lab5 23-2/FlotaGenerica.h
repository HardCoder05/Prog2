
/* 
 * File:   FlotaGenerica.h
 * Author: rio88
 *
 * Created on 28 de abril de 2024, 03:55 PM
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H
#include<fstream>
#include<iomanip>
using namespace std;

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,
    void* (*lee)(ifstream &),int (*calcular)(int ,int),const char *nom);

void muestracamiones(void *flota,int numcamiones,
    void (*imprime)(void *,ofstream &),const char *nom);



#endif /* FLOTAGENERICA_H */

