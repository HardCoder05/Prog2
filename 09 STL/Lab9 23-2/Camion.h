
/* 
 * File:   Camion.h
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 04:52 PM
 */

#ifndef CAMION_H
#define CAMION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <iterator>
using namespace std;
#include "Vehiculo.h"
#include "NPedido.h"

class Camion : public Vehiculo {
public:
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &);
    void cargadeposito(NPedido &);
    void imprime(ofstream &);
private:
    int ejes;
    int llantas;
    map<int, NPedido> mdeposito;
};

#endif /* CAMION_H */

