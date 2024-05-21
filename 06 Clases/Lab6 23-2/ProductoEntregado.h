
/* 
 * File:   ProductoEntregado.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:20 AM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

