
/* 
 * File:   Camion.h
 * Author: 
 *
 * Created on 16 de junio de 2024, 04:52 PM
 */

#ifndef CAMION_H
#define CAMION_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
#include "Vehiculo.h"
#include "Pedido.h"

class Camion : public Vehiculo {
public:
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void insertar(char *cod,int cant,double peso);
private:
    int ejes;
    int llantas;
    vector<Pedido> depositos;
};

#endif /* CAMION_H */

