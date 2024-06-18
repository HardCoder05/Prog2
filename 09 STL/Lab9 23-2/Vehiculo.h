
/* 
 * File:   Vehiculo.h
 * Author: rio88
 *
 * Created on 16 de junio de 2024, 04:51 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <fstream>
#include <iomanip>
using namespace std;
#include "NPedido.h"

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* placa);
    void GetPlaca(char *placa) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee(ifstream &);
    virtual void cargadeposito(NPedido &) = 0;
    virtual void imprime(ofstream &);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
};

#endif /* VEHICULO_H */

