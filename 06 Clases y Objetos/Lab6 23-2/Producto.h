
/* 
 * File:   Producto.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:25 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#include "Pedido.h"

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    void GetDescripcion(char *desc) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *cod) const;
    bool operator +=(Pedido& ped);
    void imprimirClientesServidos(ofstream &arch);
    void imprimirClientesNoServidos(ofstream &arch);
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

bool operator >>(ifstream &,Producto &);
void operator <<(ofstream &arch,Producto &prod);

#endif /* PRODUCTO_H */

