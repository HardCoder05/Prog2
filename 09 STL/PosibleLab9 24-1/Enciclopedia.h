
/* 
 * File:   Enciclopedia.h
 * Author: 
 *
 * Created on 20 de junio de 2024, 12:23 PM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include <fstream>
using namespace std;
#include "Libro.h"

class Enciclopedia : public Libro {
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int sku;
    int anho;
    int vigencia;
};

#endif /* ENCICLOPEDIA_H */

