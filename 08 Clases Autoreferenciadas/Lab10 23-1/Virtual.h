
/* 
 * File:   Virtual.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:49 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include <fstream>
using namespace std;
#include "Alumno.h"

class Virtual: public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char*);
    void GetLicencia(char*) const;
    void lee(ifstream&);
    void actualizaTotal(double);
    void imprime(ofstream&);
};

#endif /* VIRTUAL_H */

