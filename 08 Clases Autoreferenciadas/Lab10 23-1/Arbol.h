
/* 
 * File:   Arbol.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:55 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Escala.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
private:
    Nodo *raiz;
    Escala lescala[10]{};
};

#endif /* ARBOL_H */

