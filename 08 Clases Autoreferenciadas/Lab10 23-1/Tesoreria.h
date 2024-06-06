
/* 
 * File:   Tesoreria.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 01:00 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
private:
    Arbol aboleta;
};

#endif /* TESORERIA_H */

