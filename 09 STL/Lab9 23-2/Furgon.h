
/* 
 * File:   Furgon.h
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 04:54 PM
 */

#ifndef FURGON_H
#define FURGON_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;
#include "Vehiculo.h"
#include "NPedido.h"

class Furgon : public Vehiculo {
public:
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &);
    void cargadeposito(NPedido &);
    void imprime(ofstream &);
private:
    int filas;
    int puertas;
    list<class NPedido> pdeposito;
};

#endif /* FURGON_H */

