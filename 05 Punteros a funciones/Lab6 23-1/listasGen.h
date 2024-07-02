
/* 
 * File:   listasGen.h
 * Author: 
 *
 * Created on 2 de mayo de 2024, 11:04 AM
 */

#ifndef LISTASGEN_H
#define LISTASGEN_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>

void crearListaHeroes(void *,void *&,void * (*leerHeroe)(void *));
void construirLista(void *&);
void insertarRegistro(void *, void*&);
bool esListaVacia(void *);
void *leerHeroe(void *);
void imprimirListaHeroes(const char *,void *,
    void (*imprimirRegistro)(void *,ofstream &));
void imprimirRegistro(void *,ofstream &);

void eliminarListaHeroes(void *&, void (*eliminarRegistro)(void **&,void **&));
bool sonRegistrosIguales(void *, void *);
void eliminarRegistro(void **&,void **&);

#endif /* LISTASGEN_H */

