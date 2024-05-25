
#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>   
using namespace std;
#include "Alumno.h"

class Virtual: public Alumno{
    private:
        char *licencia;
        double total;
    public:
        Virtual();
        virtual ~Virtual();
        void setLicencia(char *licencia);
        void setTotal(double total);
        double getTotal();
        void getLicencia(char *licencia);
        void llenarDatos(int , char *, int , char *);
        void mostrarDatos(ofstream &);
};


