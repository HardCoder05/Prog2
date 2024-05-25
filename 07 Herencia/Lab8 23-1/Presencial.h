
#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>   
using namespace std;
#include "Alumno.h"

class Presencial : public Alumno{
    private:
        double recargo;
        double total;
    public:
        Presencial();
        void setRecargo(double recargo);
        void setTotal(double total);
        double getRecargo();
        double getTotal();
        void llenarDatos(int , char *, int , double );

        void mostrarDatos(ofstream &);
};



