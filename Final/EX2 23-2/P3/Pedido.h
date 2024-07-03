
/* 
 * File:   Pedido.h
 * Author: 
 *
 * Created on 2 de julio de 2024, 04:04 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    void operator =(const Pedido& ori);
private:
    string codigo;
    int cantidad;
    double peso;
};

#endif /* PEDIDO_H */

