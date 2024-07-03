
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 2 de julio de 2024, 07:21 PM
 */

#include "Programacion.h"

int main(int argc, char** argv) {
    Programacion pro;
    
    pro.cargavehiculos();
    pro.cargaprogramacion();
    pro.reducevehiculos(10);
    pro.muestraprogramacion();
    
    
    return 0;
}

