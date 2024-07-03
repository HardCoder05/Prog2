
/* 
 * File:   Nodo.h
 * Author: 
 *
 * Created on 2 de julio de 2024, 07:24 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Vehiculo.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
private:
    Vehiculo *unidad;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

