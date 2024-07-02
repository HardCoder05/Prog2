
/* 
 * File:   OrdenVenta.h
 * Author: 
 *
 * Created on 28 de mayo de 2024, 09:28 AM
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H
#include<fstream>
using namespace std;
#include "Pedido.h"

class OrdenVenta {
public:
    void leerOrden(ifstream &,char );
    void actualizarOrden();
    void imprimirOrden(ofstream &);
private:
    Pedido *ptr_orden;
};

#endif /* ORDENVENTA_H */

