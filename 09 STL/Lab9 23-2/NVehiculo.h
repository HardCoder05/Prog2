
/* 
 * File:   NVehiculo.h
 * Author: 
 *
 * Created on 16 de junio de 2024, 04:55 PM
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include <iostream>
#include <fstream>
using namespace std;
#include "Vehiculo.h"

class NVehiculo {
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    void operator =(const NVehiculo &);
    void leer(ifstream &arch);
    bool operator <(const NVehiculo &);
    bool comparar(int);
    void carga(NPedido &);
    void imprimir(ofstream &);
private:
    Vehiculo *unidad;
};

#endif /* NVEHICULO_H */

