
/* 
 * File:   Arbol.h
 * Author: 
 *
 * Created on 6 de junio de 2024, 12:55 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>
#include "Nodo.h"
#include "Escala.h"

class Arbol {
private:
    class Nodo *raiz;
    class Escala lescala[10];

    void insertarR(class Nodo *&arbol, const class Boleta &boleta);
    void mostrarEnOrdenR(ofstream &arch, class Nodo *arbol);
    void actualizaBoletaR(class Nodo *arbol);
public:
    Arbol();
    virtual ~Arbol();
    void cargaEscalas(const char *);
    void crear(const char*);
    void actualizaBoleta();
    void mostrarEnOrden(const char*);
    void imprimeLinea(ofstream&, char , int );
};

#endif /* ARBOL_H */

