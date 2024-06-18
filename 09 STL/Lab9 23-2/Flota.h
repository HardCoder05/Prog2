
/* 
 * File:   Flota.h
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 04:57 PM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "NVehiculo.h"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void cargapedidos();
    int buscarVehiculo(int);
private:
    vector<NVehiculo> vflota;
};

#endif /* FLOTA_H */

