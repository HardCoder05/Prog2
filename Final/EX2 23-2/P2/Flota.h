
/* 
 * File:   Flota.h
 * Author: 
 *
 * Created on 16 de junio de 2024, 04:57 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
#include "Vehiculo.h"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void cargar_pedidos();
private:
    map<string,Vehiculo*> vehiculos;
};

#endif /* FLOTA_H */

