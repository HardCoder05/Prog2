
/* 
 * File:   Libro.h
 * Author: 
 *
 * Created on 20 de junio de 2024, 12:22 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(char*);
    void GetNombre(char *) const;
    void operator =(const Libro &);
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

