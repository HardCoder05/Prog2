
/* 
 * File:   Nodo.h
 * Author: 
 *
 * Created on 6 de junio de 2024, 12:53 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Boleta.h"
#include "Arbol.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
private:
    Boleta dboleta;
    Nodo *izq;
    Nodo *der;
};

#endif /* NODO_H */

