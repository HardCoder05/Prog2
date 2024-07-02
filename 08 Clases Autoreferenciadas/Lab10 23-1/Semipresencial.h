
/* 
 * File:   Semipresencial.h
 * Author: 
 *
 * Created on 6 de junio de 2024, 12:47 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include <fstream>
using namespace std;
#include "Alumno.h"

class Semipresencial: public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream&);
    void actualizaTotal(double);
    void imprime(ofstream&);
};

#endif /* SEMIPRESENCIAL_H */

