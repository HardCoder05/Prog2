
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:40 PM
 */

#include "Tesoreria.h"

int main(int argc, char** argv) {
    class Tesoreria caja;

    caja.cargaAlumnos("Alumnos.csv");
    caja.actualizaBoleta("escalas.csv");
    caja.imprimeBoleta("reporteDePagos.txt");

    return 0;
}
