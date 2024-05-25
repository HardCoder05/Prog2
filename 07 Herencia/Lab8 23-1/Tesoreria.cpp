
#include "Tesoreria.h"

void Tesoreria::cargaEscalas(){
    ifstream arch("escalas.csv", ios::in);

    int codigo;
    char c;
    double precio;

    while(true){
        arch >> codigo;
        if(arch.eof()) break;
        arch >> c >> precio;

        lescala[codigo - 1].setCodigo(codigo);
        lescala[codigo - 1].setPrecio(precio);
    }
}

void Tesoreria::cargaalumnos(){
    ifstream arch("Alumnos.csv", ios::in);

    int codigo, cantAlumnosPresencial = 0, cantAlumnosSemi = 0, cantAlumnosVir = 0, escala;
    char c, tipo_de_alumno, nombre[60], licencia[60];
    double recarga, descuento;

    while(true){
        arch >> tipo_de_alumno;
        if(arch.eof()) break;
        arch >> c >> codigo >> c;
        arch.getline(nombre, 60, ',');
        
        if(tipo_de_alumno == 'P'){
            arch >> escala >> c >> recarga;
            lpresencial[cantAlumnosPresencial].llenarDatos(codigo, nombre, escala, recarga);
            cantAlumnosPresencial++;
        }
        else if(tipo_de_alumno == 'S'){
            arch >> escala >> c >> descuento;
            lsemipresencial[cantAlumnosSemi].llenarDatos(codigo, nombre, escala, descuento);
            cantAlumnosSemi++;
        }
        else{ // tipo_de_alumno == 'V'
            arch >> escala >> c;
            arch.getline(licencia, 30, '\n');
            lvirtual[cantAlumnosVir].llenarDatos(codigo, nombre, escala, licencia);
            cantAlumnosVir++;
        }
    }
}



void Tesoreria::imprime(){
    ofstream arch("Reporte.txt", ios::out);

    arch << "Presenciales" << endl;
    arch << "Codigo" << setw(15) << "Nombre" << setw(42) << "Escala" << setw(10) << "Recarga" 
        << setw(8) << "Total" << endl;
    for(int i = 0; i < lpresencial[i].getCodigo() ; i++){
        lpresencial[i].mostrarDatos(arch);        
    }

    arch << endl << "Semipresenciales" << endl;
    arch << "Codigo" << setw(15) << "Nombre" << setw(42) << "Escala" << setw(10) << "Descuento" 
        << setw(8) << "Total" << endl;
    for(int i = 0; i < lsemipresencial[i].getCodigo() ; i++){
        lsemipresencial[i].mostrarDatos(arch);        
    }

    arch << endl << "Virtuales: " << endl;
    arch << "Codigo" << setw(15) << "Nombre" << setw(42) << "Escala" << setw(10) << "Licencia" 
        << setw(8) << "Total" << endl;
    for(int i = 0; lvirtual[i].getEscala() ; i++){
        lvirtual[i].mostrarDatos(arch);       
    }
}

