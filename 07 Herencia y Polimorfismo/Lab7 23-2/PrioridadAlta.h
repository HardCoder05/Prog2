
/* 
 * File:   PrioridadAlta.h
 * Author: 
 *
 * Created on 28 de mayo de 2024, 09:20 AM
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H
#include<fstream>
using namespace std;
#include "Pedido.h"

class PrioridadAlta:public Pedido{
public:
    PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &);
    void actualiza(void);
    void imprime(ofstream &);
private:
    double recargo;
    double total;
};

#endif /* PRIORIDADALTA_H */

