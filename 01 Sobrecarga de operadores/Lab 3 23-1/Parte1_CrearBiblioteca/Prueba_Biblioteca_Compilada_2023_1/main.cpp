
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 2 de abril de 2024, 05:46 PM
 */

#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "funciones.h"

int main(int argc, char** argv) {
    // archivos de lectura y escritura
    ifstream archCursos, archAlumno, archMatricula;
    ofstream archReporteCurso, archReporteAlumno;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumno, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteCurso, "ReporteCursos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteAlumno, "ReporteAlumnos.txt");
    // variables
    StCurso curso, arregloCurso[50];
    StAlumno alumno, arregloAlumno[100];
    StRegistroDeMatricula matricula;
    strcpy(arregloCurso[0].codigoDelCurso, "XXXXXX");
    arregloAlumno[0].semestre = 0;
    // pruebas sencillas
    for (int i = 0; i < 15; i++) {
        if (!(archCursos >> curso)) {
            break;
        }
        arregloCurso += curso;
    }

    for (int i = 0; i < 99; i++) {
        if (!(archAlumno >> alumno)) {
            break;
        }
        arregloAlumno += alumno;
    }

    archMatricula >> matricula;
    arregloCurso *= matricula;
    arregloAlumno *= matricula;
    archMatricula >> matricula;
    arregloCurso *= matricula;
    arregloAlumno *= matricula;
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") != 0; i++) {
        archReporteCurso << arregloCurso[i];
    }
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        archReporteAlumno << arregloAlumno[i];
    }
    
    return 0;
}

