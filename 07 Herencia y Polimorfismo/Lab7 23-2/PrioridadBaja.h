
/* 
 * File:   PrioridadBaja.h
 * Author: rio88
 *
 * Created on 28 de mayo de 2024, 09:26 AM
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H
#include<fstream>
using namespace std;
#include "Pedido.h"

class PrioridadBaja:public Pedido{
public:
    PrioridadBaja();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDias_espera(int dias_espera);
    int GetDias_espera() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int dias_espera;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADBAJA_H */

