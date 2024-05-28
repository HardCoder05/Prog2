
/* 
 * File:   Semipresencial.h
 * Author: rio88
 *
 * Created on 25 de mayo de 2024, 06:11 PM
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
    void leerDatos(ifstream&);
    void actualiza(double);
    void imprime(ofstream&);
};


#endif /* SEMIPRESENCIAL_H */

