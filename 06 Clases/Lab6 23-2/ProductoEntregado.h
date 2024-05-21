
/* 
 * File:   ProductoEntregado.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:20 AM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H
#include<cstring>

class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

