
/* 
 * File:   PrioridadAlta.h
 * Author: rio88
 *
 * Created on 28 de mayo de 2024, 09:20 AM
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H

#include "Pedido.h"

class PrioridadAlta : public Pedido{
public:
    PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
private:
    double recargo;
    double total;
};

#endif /* PRIORIDADALTA_H */

