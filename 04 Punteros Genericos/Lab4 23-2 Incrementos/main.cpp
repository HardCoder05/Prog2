
#include "funciones.h"

int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
    
    return 0;
}