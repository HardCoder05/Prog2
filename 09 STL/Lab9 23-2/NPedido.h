
/* 
 * File:   NPedido.h
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 04:48 PM
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
    void SetCodigo(char* codigo);
    void GetCodigo(char *) const;
    void operator =(const NPedido &);
private:
    char *codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_H */

