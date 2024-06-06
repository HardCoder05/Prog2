
/* 
 * File:   Presencial.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:45 PM
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
    void lee(ifstream &);
    void actualizaTotal(double);
    void imprime(ofstream&);
};

#endif /* PRESENCIAL_H */

