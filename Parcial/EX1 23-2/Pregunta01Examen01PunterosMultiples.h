
/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: rio88
 *
 * Created on 4 de mayo de 2024, 10:32 AM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5

void cargarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,
    const char *nom);
char *leerCadena(ifstream &arch,int cantCar,char del);
void llenarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,
    char *cod,int dni,int cant,int fecha,int &nDat);
void incrementarEspacios(int **&fechaClienteCantidad,char **&codigoDelProducto,
    int &cap,int &nDat);
void pruebaDeCargaDePedidos(int **fechaClienteCantidad,
    char **codigoDelProducto,const char*nom);

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

