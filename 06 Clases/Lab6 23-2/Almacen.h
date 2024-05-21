
/* 
 * File:   Almacen.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:32 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "Cliente.h"
#include "Producto.h"

class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
private:
    Cliente arreglo_clientes[50]{};
    int cantidad_clientes;
    Producto arreglo_productos[50]{};
    int cantidad_productos;
};

#endif /* ALMACEN_H */

