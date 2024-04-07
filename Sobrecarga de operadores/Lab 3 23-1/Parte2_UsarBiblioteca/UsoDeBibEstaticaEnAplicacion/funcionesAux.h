
/* 
 * File:   funcionesAux.h
 * Author: rio88
 *
 * Created on 2 de abril de 2024, 06:07 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"
using namespace std;

void leerCursos(struct StCurso *);
void leerAlumnos(struct StAlumno * );
void leerMatricula(struct StCurso *,struct StAlumno *);
void modificarNombreProf(struct StCurso *arregloCurso);
void calcularIngresosYCostos(struct StCurso *arregloCurso,struct StAlumno *arregloAlumno);
void llenarEscalas(int *escala,double *monto,int &n);
int buscarEscala(int codigo,struct StAlumno *arregloAlumno);
void llenarIngresos(struct StCurso *arregloCurso,struct StAlumno *arregloAlumno,
    int *escala,double *monto,int n);
void llenarCostoTotal(struct StAlumno *arregloAlumno,struct StCurso *arregloCurso,
    int *escala,double *monto,int n);
double buscarCreditos(struct StCurso *arregloCurso,char *cod);
void realizarReporte(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno);

#endif /* FUNCIONESAUX_H */

