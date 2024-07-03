
/* 
 * File:   Arista.h
 * Author: 
 *
 * Created on 3 de julio de 2024, 03:58 PM
 */

#ifndef ARISTA_H
#define ARISTA_H

#include "Ciudad.h"

class Arista {
private:
    double longitud;
    class Ciudad destino;
public:
    Arista();
    Arista(double longitud, const class Ciudad &destino);
    void imprimeArista()const;
};

#endif /* ARISTA_H */

