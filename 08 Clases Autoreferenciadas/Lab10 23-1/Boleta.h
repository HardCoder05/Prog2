
/* 
 * File:   Boleta.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:51 PM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>
#include "Alumno.h"

class Boleta {
private:
    class Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void asignaMemoria(char tipo);

    void leeDatos(ifstream &arch) const;
    void actualizaBoleta(double);
    void imprimeBoleta(ofstream&) const;
    bool operator >(const class Boleta &dato)const;
    int GetCodigo()const;
    int GetEscala()const;
    void SetNull();
};

void operator >>(ifstream &arch, class Boleta &boleta);
void operator <<(ofstream &arch, const class Boleta &boleta);

#endif /* BOLETA_H */

