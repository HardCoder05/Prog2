
/* 
 * File:   Producto.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:25 AM
 */

#include "Producto.h"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if(codigo != nullptr){
        delete codigo;
        delete descripcion;
    }
}

