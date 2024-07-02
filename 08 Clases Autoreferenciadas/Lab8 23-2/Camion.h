
/* 
 * File:   Camion.h
 * Author: 
 *
 * Created on 9 de junio de 2024, 11:21 AM
 */

#ifndef CAMION_H
#define CAMION_H

#include <fstream>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"

class Camion : public Vehiculo {
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int ejes;
    int llantas;
};

#endif /* CAMION_H */

