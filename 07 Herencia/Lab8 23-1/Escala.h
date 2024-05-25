
/* 
 * File:   Escala.h
 * Author: rio88
 *
 * Created on 25 de mayo de 2024, 06:07 PM
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};


#endif /* ESCALA_H */

