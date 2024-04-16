
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 2 de abril de 2024, 05:55 PM
 */

#include "funcionesAux.h"

int main(int argc, char** argv) {
    struct StCurso arregloCurso[20];
    struct StAlumno arregloAlumno[200];
    
    leerCursos(arregloCurso);
    leerAlumnos(arregloAlumno);
    leerMatricula(arregloCurso,arregloAlumno);
    
    //modificarNombreProf(arregloCurso);
    
    calcularIngresosYCostos(arregloCurso,arregloAlumno);
    
    realizarReporte(arregloCurso,arregloAlumno);
    
    return 0;
}

