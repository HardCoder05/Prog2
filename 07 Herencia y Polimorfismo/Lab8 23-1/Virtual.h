
/* 
 * File:   Virtual.h
 * Author: rio88
 *
 * Created on 25 de mayo de 2024, 06:11 PM
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
    void leerDatos(ifstream&);
    void actualiza(double);
    void imprime(ofstream&);
};

#endif /* VIRTUAL_H */

