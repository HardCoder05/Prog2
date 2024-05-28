
/* 
 * File:   Almacen.h
 * Author: rio88
 *
 * Created on 28 de mayo de 2024, 09:29 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "OrdenVenta.h"

class Almacen {
public:
    Almacen();
private:
    OrdenVenta ordenes[200]{};
    int cantidad_ordenes;
};

#endif /* ALMACEN_H */

