
/* 
 * File:   LibroSolicitado.h
 * Author: rio88
 *
 * Created on 23 de mayo de 2024, 09:55 AM
 */

#ifndef LIBROSOLICITADO_H
#define LIBROSOLICITADO_H
#include "Libro.h"

class LibroSolicitado {
public:
    LibroSolicitado();
    LibroSolicitado(const LibroSolicitado& orig);
    virtual ~LibroSolicitado();
    void SetAtendido(bool atendido);
    bool IsAtendido() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigoDelLibro(char* codigoDelLibro);
    void GetCodigoDelLibro(char *cod) const;
    void SetNumeroDePedido(int numeroDePedido);
    int GetNumeroDePedido() const;
    bool operator >>(Libro& lib);
private:
    int numeroDePedido;
    char *codigoDelLibro;
    double precio;
    bool atendido; // true ==> Pedido atendido, false ==> Pedido no atendido
};

#endif /* LIBROSOLICITADO_H */

