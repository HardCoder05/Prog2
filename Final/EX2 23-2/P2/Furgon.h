
/* 
 * File:   Furgon.h
 * Author: 
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
#include <string>
using namespace std;
#include "Vehiculo.h"
#include "Pedido.h"

class Furgon : public Vehiculo {
public:
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void insertar(char *cod,int cant,double peso);
private:
    int filas;
    int puertas;
    list<Pedido> depositos;
};

#endif /* FURGON_H */

