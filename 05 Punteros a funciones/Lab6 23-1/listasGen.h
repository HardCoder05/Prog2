
/* 
 * File:   listasGen.h
 * Author: rio88
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

void crearListaHeroes(void *arregloHeroes,void *&listaHeroes,void * 
    (*leerHeroe)(void *));
void construirLista(void *&lista_heroes);
void insertarRegistro(void *dato, void*&lista);
bool esListaVacia(void *lista);
void *leerHeroe(void *heroe);
void imprimirListaHeroes(const char *nom,void *listaHeroes,
    void (*imprimirRegistro)(void *,ofstream &));
void imprimirRegistro(void *registro,ofstream &arch);



#endif /* LISTASGEN_H */

