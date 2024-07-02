
/* 
 * File:   Libro.h
 * Author: 
 *
 * Created on 23 de mayo de 2024, 10:16 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include<fstream>
#include<iomanip>
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(char* aut);
    void GetAutor(char *aut) const;
    void SetTitulo(char* titu);
    void GetTitulo(char *titu) const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
private:
    char *codigo;
    char *titulo;
    char *autor;
    int stock;
    double precio;
};

bool operator >>(ifstream &,Libro &);
void operator <<(ofstream &,Libro &);

#endif /* LIBRO_H */

