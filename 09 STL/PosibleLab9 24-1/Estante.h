
/* 
 * File:   Estante.h
 * Author: rio88
 *
 * Created on 20 de junio de 2024, 12:38 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Lista.h"
#include "Libro.h"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void operator =(const Estante &);
    void leer(ifstream &arch);
    void meter(Libro *);
    void mostrar(ofstream &arch);
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
};

#endif /* ESTANTE_H */

