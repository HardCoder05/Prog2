
/* 
 * File:   Presencial.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:45 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno {
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

