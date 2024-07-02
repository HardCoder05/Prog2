
/* 
 * File:   LVehiculos.h
 * Author: 
 *
 * Created on 9 de junio de 2024, 11:27 AM
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "NodoLista.h"
#define NO_ENCONTRADO -1

class LVehiculos {
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
    void agregar(Vehiculo *);
    void crear();
    void cargar();
    int buscarCliente(int );
    void ubicarPos(int ,char *,int ,double );
    void muestra();
private:
    class NodoLista *lini;
    class NodoLista *lfin;
};

#endif /* LVEHICULOS_H */

