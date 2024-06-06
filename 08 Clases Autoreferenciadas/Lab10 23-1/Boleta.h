
/* 
 * File:   Boleta.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:51 PM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"

class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
private:
    Alumno *pboleta;
};

#endif /* BOLETA_H */

