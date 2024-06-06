
/* 
 * File:   Tesoreria.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 01:00 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
private:
    class Arbol aboleta;
public:
    void cargaEscalas(const char *);
    void cargaAlumnos(const char *);
    void actualizaBoleta(const char *);
    void imprimeBoleta(const char *);
    void imprimeLinea(ofstream &, char, int);
};

#endif /* TESORERIA_H */

