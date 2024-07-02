
/* 
 * File:   Presencial.h
 * Author: 
 *
 * Created on 25 de mayo de 2024, 06:10 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include <fstream>
using namespace std;
#include "Alumno.h"

class Presencial : public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerDatos(ifstream&);
    void actualiza(double);
    void imprime(ofstream&);
};

#endif /* PRESENCIAL_H */

