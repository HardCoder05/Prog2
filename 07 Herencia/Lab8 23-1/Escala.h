
#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>   
using namespace std;

class Escala{
    private:
        int codigo;
        double precio;
    public:
        void setCodigo(int codigo);
        void setPrecio(double precio);
        int getCodigo();
        double getPrecio();
};


