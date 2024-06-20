
/* 
 * File:   Revista.h
 * Author: rio88
 *
 * Created on 20 de junio de 2024, 12:33 PM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include <fstream>
using namespace std;
#include "Libro.h"

class Revista : public Libro {
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

