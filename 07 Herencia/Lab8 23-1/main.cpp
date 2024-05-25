
/* 
 * File:   main.cpp
 * Author: rio88
 *
 * Created on 25 de mayo de 2024, 06:06 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Tesoreria.h"
int main(int argc, char** argv) {
    class Tesoreria caja; // {}
    caja.cargaescalas("escalas.csv");
    caja.cargaalumnos("Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("reporteDePagos.txt");
    return 0;
}

