
/* 
 * File:   Vehiculo.h
 * Author: rio88
 *
 * Created on 9 de junio de 2024, 11:12 AM
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
    void llenar(char *,int ,double );
    void push(char *,int ,double );
    virtual void imprime(ofstream &);
    void imprimirPedidos(ofstream &);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    class NPedido *ped;
};

#endif /* VEHICULO_H */

