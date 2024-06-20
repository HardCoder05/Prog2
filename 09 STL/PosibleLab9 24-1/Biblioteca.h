
/* 
 * File:   Biblioteca.h
 * Author: rio88
 *
 * Created on 20 de junio de 2024, 12:43 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;
#include "Estante.h"
#include "Libro.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void meterLibros(Libro *,int *);
    void baja();
    void muestra();
private:
    vector<Estante> AEstantes;
};

#endif /* BIBLIOTECA_H */

