
/* 
 * File:   Pedido.h
 * Author: 
 *
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include<fstream>
using namespace std;
#include<cstring>

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    int dni_cliente; 
    double precio_producto; 
};

bool operator >>(ifstream &,Pedido &);

#endif /* PEDIDO_H */

