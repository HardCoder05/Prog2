
/* 
 * File:   Vehiculo.h
 * Author: 
 *
 * Created on 16 de junio de 2024, 04:51 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void setCarga_actual(double carga_actual);
    double getCarga_actual() const;
    void setCarga_maxima(double carga_maxima);
    double getCarga_maxima() const;
    void setPlaca(string placa);
    string getPlaca() const;
    void setDni(int dni);
    int getDni() const;
    void operator =(const Vehiculo& ori);
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
    virtual void insertar(char *cod,int cant,double peso) = 0;
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
};

#endif /* VEHICULO_H */

