
/* 
 * File:   Almacen.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:32 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#include "Cliente.h"
#include "Producto.h"

class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void cargar_clientes(void);
    void cargar_productos(void);
    void cargar_pedidos(void);
    void mostrar_datos(void);
private:
    Cliente arreglo_clientes[200]{};
    int cantidad_clientes;
    Producto arreglo_productos[200]{};
    int cantidad_productos;
};

#endif /* ALMACEN_H */

