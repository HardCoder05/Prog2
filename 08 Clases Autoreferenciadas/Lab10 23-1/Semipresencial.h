
/* 
 * File:   Semipresencial.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:47 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial : public Alumno {
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

