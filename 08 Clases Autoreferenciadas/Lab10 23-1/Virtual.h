
/* 
 * File:   Virtual.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:49 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno {
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char*);
    void GetLicencia(char*) const;
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

