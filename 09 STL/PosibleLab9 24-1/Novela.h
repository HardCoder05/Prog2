
/* 
 * File:   Novela.h
 * Author: 
 *
 * Created on 20 de junio de 2024, 12:30 PM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include <fstream>
using namespace std;
#include "Libro.h"

class Novela : public Libro {
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(char *);
    void GetAutor(char *) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    char *autor;
};

#endif /* NOVELA_H */

