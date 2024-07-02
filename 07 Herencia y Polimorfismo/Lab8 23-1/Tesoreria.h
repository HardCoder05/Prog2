
/* 
 * File:   Tesoreria.h
 * Author: 
 *
 * Created on 25 de mayo de 2024, 06:12 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"
class Tesoreria {
private:
    class Presencial lpresencial[100];
    class Semipresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[10];
public:
    void cargaescalas(const char *);
    void cargaalumnos(const char *);
    void actualiza(double);
    void imprime(const char *);
    void muestraEscala(int);
    void imprimeLinea(ofstream &, char, int);
};


#endif /* TESORERIA_H */

