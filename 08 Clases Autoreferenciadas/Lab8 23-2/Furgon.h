
/* 
 * File:   Furgon.h
 * Author: 
 *
 * Created on 9 de junio de 2024, 11:22 AM
 */

#ifndef FURGON_H
#define FURGON_H

#include <fstream>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"

class Furgon : public Vehiculo {
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_H */

