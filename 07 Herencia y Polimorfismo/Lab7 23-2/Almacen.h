
/* 
 * File:   Almacen.h
 * Author: 
 *
 * Created on 28 de mayo de 2024, 09:29 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "OrdenVenta.h"

class Almacen {
public:
    Almacen();
    void cargar_pedidos(const char*);
    void actualizar_pedidos(void);
    void imprimir_ordenes_venta(const char*);
private:
    OrdenVenta ordenes[600]{};
    int cantidad_ordenes;
};

#endif /* ALMACEN_H */

