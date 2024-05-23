
/* 
 * File:   Cliente.h
 * Author: rio88
 *
 * Created on 23 de mayo de 2024, 10:10 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include "LibroSolicitado.h"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetPagoTotal(double pagoTotal);
    double GetPagoTotal() const;
    void SetCantDeLibros(int cantDeLibros);
    int GetCantDeLibros() const;
    void SetNombre(char* nombre);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    bool operator <<(LibroSolicitado& libSoli);
    void operator ++(void);
    void imprimirLibros(ofstream &arch);
private:
    int dni;
    char *nombre;
    LibroSolicitado librosSolicitados[30]{};
    int cantDeLibros;
    double pagoTotal;
};

bool operator >>(ifstream &,Cliente &);
void operator <<(ofstream &,Cliente &);

#endif /* CLIENTE_H */

