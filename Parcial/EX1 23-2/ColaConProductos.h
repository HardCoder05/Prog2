
/* 
 * File:   ColaConProductos.h
 * Author: rio88
 *
 * Created on 5 de mayo de 2024, 12:49 PM
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include <cstring>
#define NO_ENCONTRADO -1

void procesarPedidos(int **fechaClienteCantidad,char **&codigoDelProducto, 
    void *&productos);
int buscarProd(void *productos,char *cod);
void llenarProd(int *auxFecha,void **pro);

void reporteDePedidos(void *productos,const char *nom);
void imprimirDetallesPed(void *cola,ofstream &arch);

#endif /* COLACONPRODUCTOS_H */

