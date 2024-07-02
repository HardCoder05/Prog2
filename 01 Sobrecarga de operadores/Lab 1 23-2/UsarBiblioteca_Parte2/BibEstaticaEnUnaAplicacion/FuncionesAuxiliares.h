
/* 
 * File:   FuncionesAuxiliares.h
 * Author: 
 *
 * Created on 4 de abril de 2024, 11:24 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecargas.h"
using namespace std;

void leerClientes(struct Cliente *arregloClientes);
void leerProd(struct Producto *arregloProd);
void leerPed(struct Cliente *arregloClientes,struct Producto *arregloProd);
void realizarReporte(struct Cliente *arregloClientes, struct Producto *arregloProd);

#endif /* FUNCIONESAUXILIARES_H */

