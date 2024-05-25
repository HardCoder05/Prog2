
#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>   
using namespace std;

class Alumno{
    private:
        int codigo;
        char *nombre;
        int escala;
        double total;
    public:
        Alumno();
        virtual ~Alumno();
        void setCodigo(int codigo);
        void setNombre(char *nombre);
        void setEscala(int escala);
        void setTotal(double total);
        int getCodigo();
        void getNombre(char *nombre);
        int getEscala();
        double getTotal();
};


