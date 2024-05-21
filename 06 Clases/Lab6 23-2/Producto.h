
/* 
 * File:   Producto.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:25 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[50]{};
    int clientes_no_servidos[50]{};
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};

#endif /* PRODUCTO_H */

