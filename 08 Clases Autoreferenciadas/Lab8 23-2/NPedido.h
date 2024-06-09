
/* 
 * File:   NPedido.h
 * Author: rio88
 *
 * Created on 9 de junio de 2024, 11:02 AM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
private:
    char *codigo;
    int cantidad;
    double peso;
    NPedido *sig;
    friend class Vehiculo;
};

#endif /* NPEDIDO_H */

