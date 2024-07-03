
/* 
 * File:   Arbol.h
 * Author: 
 *
 * Created on 3 de julio de 2024, 09:38 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void insertar(Vehiculo *);
    void eliminarHijos(int );
    void mostrarEnOrden(ofstream &);
private:
    class Nodo *raiz;
    void insertarR(Nodo *&,Vehiculo *);
    void eliminarHijosR(Nodo *&,int ,int &);
    void mostrarEnOrdenR(Nodo *,ofstream &,int &);
};

#endif /* ARBOL_H */

