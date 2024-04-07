
#include "funcionesAux.h"
#define NO_ENCONTRADO -1
#define MAX_ESCALAS 10

void leerCursos(struct StCurso *arregloCurso){
    struct StCurso curso;
    ifstream archCurso;
    AperturaDeUnArchivoDeTextosParaLeer(archCurso, "Cursos.txt");
    strcpy(arregloCurso[0].codigoDelCurso, "XXXXXX");
    while (true) {
        if (!(archCurso >> curso)) {
            break;
        }
        arregloCurso += curso;
    }
}

void leerAlumnos(struct StAlumno *arregloAlumno) {
    struct StAlumno alumno;
    ifstream archAlumno;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumno, "Alumnos.txt");
    arregloAlumno[0].semestre = 0;
    while (true) {
        if (!(archAlumno >> alumno)) {
            break;
        }
        arregloAlumno += alumno;
    }
}

void leerMatricula(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno) {
    struct StRegistroDeMatricula matricula;
    ifstream archMatricula;
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    while (true) {
        if (!(archMatricula >> matricula)) {
            break;
        }
        arregloAlumno *= matricula;
        arregloCurso *= matricula;
    }
}

void modificarNombreProf(struct StCurso *arregloCurso){
    for(int i=0 ; strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") != 0 ; i++){
        for(int j=0 ; arregloCurso[i].nombreDelProfesor[j] ; j++){
            if(arregloCurso[i].nombreDelProfesor[j] == '_'){
                arregloCurso[i].nombreDelProfesor[j] = ' ';
            }
        }
    }
}

void calcularIngresosYCostos(struct StCurso *arregloCurso,struct StAlumno *
    arregloAlumno){
    int escala[MAX_ESCALAS], n, esca;
    double monto[MAX_ESCALAS];
    llenarEscalas(escala, monto, n);
    
    llenarIngresos(arregloCurso, arregloAlumno, escala, monto, n);
    llenarCostoTotal(arregloAlumno, arregloCurso, escala, monto, n);
}

void llenarEscalas(int *escala,double *monto,int &n){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Escalas.txt");
    
    n = 0;
    char c;
    while(true){
        arch>>c;
        if(arch.eof()) break;
        arch>>escala[n];
        arch>>monto[n];
        n++;
    }
}

//202213456
int buscarEscala(int codigo,struct StAlumno *arregloAlumno){
    int semestre = codigo/10000;
    int cod = codigo%10000;
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        if( arregloAlumno[i].semestre == semestre and arregloAlumno[i].codigo == cod){
            return arregloAlumno[i].escala;
        }
    }
    return NO_ENCONTRADO;
}

void llenarIngresos(struct StCurso *arregloCurso,struct StAlumno *arregloAlumno,
    int *escala,double *monto,int n){
    for(int i=0 ; strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") != 0 ; i++){
        for(int j=0 ; j < arregloCurso[i].numeroDeAlumnos ; j++){
            int esca = buscarEscala(arregloCurso[i].alumnos[j], arregloAlumno);
            if(esca != NO_ENCONTRADO){
                for(int k=0 ; k<n ; k++){
                    if(escala[k] == esca){
                        arregloCurso[i].ingresos += monto[k] * arregloCurso[i].creditos;
                    }
                }
            }
        }
    }
}

void llenarCostoTotal(struct StAlumno *arregloAlumno,struct StCurso *arregloCurso,
    int *escala,double *monto,int n){
    for(int i=0 ; arregloAlumno[i].semestre != 0 ; i++){
        for(int j=0 ; j<arregloAlumno[i].numeroDeCursos ; j++){
            double cred = buscarCreditos(arregloCurso, arregloAlumno[i].cursos[j]);
            for(int k=0 ; k<n ; k++){
                if(escala[k] == arregloAlumno[i].escala){
                    arregloAlumno[i].costoTotal += cred * monto[k];
                }
            }
        }
    }
}

double buscarCreditos(struct StCurso *arregloCurso,char *cod){
    for(int i=0 ; strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") != 0 ; i++){
        if(strcmp(arregloCurso[i].codigoDelCurso, cod) == 0) 
            return arregloCurso[i].creditos;
    }
    return NO_ENCONTRADO;
}

void realizarReporte(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    archReporte<<"REPORTE DE CURSOS"<<endl<<endl;
    
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso,"XXXXXX") != 0; i++) {
        archReporte << arregloCurso[i];
    }
    
    archReporte<<endl<< "REPORTE DE ALUMNOS"<<endl;
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        archReporte << arregloAlumno[i];
    }
}

