
/* 
 * File:   Tesoreria.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 01:00 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaAlumnos(const char*nombArch) {
    aboleta.crear(nombArch);
}

void Tesoreria::actualizaBoleta(const char*nombArch) {
    aboleta.cargaEscalas(nombArch);
    aboleta.actualizaBoleta();
}

void Tesoreria::imprimeBoleta(const char*nombArch) {
    aboleta.mostrarEnOrden(nombArch);
}

void Tesoreria::imprimeLinea(ofstream &arch, char car, int nd) {
    for(int i=0; i<nd; i++)
        arch.put(car);
    arch<<endl;
}

