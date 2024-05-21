
/* 
 * File:   Pedido.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:30 AM
 */

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if(codigo != nullptr) delete codigo;
}

