
/* 
 * File:   Flota.h
 * Author: 
 *
 * Created on 9 de junio de 2024, 11:29 AM
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void cargapedidos();
    void muestracarga();
private:
    LVehiculos lista;
};  

#endif /* FLOTA_H */

