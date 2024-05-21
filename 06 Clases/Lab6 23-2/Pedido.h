
/* 
 * File:   Pedido.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
private:
    char *codigo;
    int dni_cliente; 
    double precio_producto; 
};

#endif /* PEDIDO_H */

