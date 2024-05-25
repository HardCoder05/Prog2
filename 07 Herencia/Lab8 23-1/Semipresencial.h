
#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>   
using namespace std;
#include "Alumno.h"

class Semipresencial : public Alumno{
    private:
        double descuento;
        double total;
    public:
        Semipresencial();
        void setDescuento(double descuento);
        void setTotal(double total);
        double getDescuento();
        double getTotal();
        void llenarDatos(int , char *, int , double );
        void mostrarDatos(ofstream &);
};


