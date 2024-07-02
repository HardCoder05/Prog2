
/* 
 * File:   Nodo.h
 * Author: 
 *
 * Created on 20 de junio de 2024, 12:35 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"

class Nodo {
public:
    Nodo(Libro *);
    Nodo(const Nodo& orig);
    virtual ~Nodo();
private:
    Libro *plibro;
    class Nodo *sig;
    class Nodo *ant;
    friend class Lista;
};

#endif /* NODO_H */

