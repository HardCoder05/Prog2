
/* 
 * File:   Pedido.h
 * Author: rio88
 *
 * Created on 28 de mayo de 2024, 09:14 AM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Pedido {
public:
    Pedido();
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(char* est);
    void GetEstado(char *est) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
    virtual void lee(ifstream & );
    virtual void imprime(ofstream&);
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;
};

#endif /* PEDIDO_H */

