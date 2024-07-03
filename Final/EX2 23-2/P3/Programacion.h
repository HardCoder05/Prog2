
/* 
 * File:   Programacion.h
 * Author: 
 *
 * Created on 3 de julio de 2024, 09:39 AM
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H

#include "Arbol.h"
#include "Flota.h"

class Programacion {
public:
    Programacion();
    Programacion(const Programacion& orig);
    virtual ~Programacion();
    void cargavehiculos();
    void cargaprogramacion();
    void reducevehiculos(int );
    void muestraprogramacion();
private:
    Arbol ADespachos;
    Flota fVehiculos;
};

#endif /* PROGRAMACION_H */

