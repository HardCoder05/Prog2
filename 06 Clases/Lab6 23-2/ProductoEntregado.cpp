
/* 
 * File:   ProductoEntregado.cpp
 * Author: rio88
 * 
 * Created on 21 de mayo de 2024, 09:20 AM
 */

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {

}

ProductoEntregado::~ProductoEntregado() {
    if(codigo != nullptr) delete codigo;
}
