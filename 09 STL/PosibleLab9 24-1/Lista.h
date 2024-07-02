
/* 
 * File:   Lista.h
 * Author: 
 *
 * Created on 20 de junio de 2024, 12:36 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include <fstream>
#include <iomanip>
using namespace std;
#include "Libro.h"

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void insertar(Libro *);
    void mostrar(ofstream &);
private:
    double peso;
    class Nodo *ini;
    class Nodo *fin;
};

#endif /* LISTA_H */

