
/* 
 * File:   NodoLista.h
 * Author: 
 *
 * Created on 9 de junio de 2024, 11:24 AM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include <fstream>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"
#include "LVehiculos.h"

class NodoLista {
public:
    NodoLista(Vehiculo *);
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
private:
    Vehiculo *unidad;
    NodoLista *sig;
    friend class LVehiculos;
};

#endif /* NODOLISTA_H */

