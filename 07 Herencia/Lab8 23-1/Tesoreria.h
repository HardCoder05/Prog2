
#pragma once 
#include<iostream>
#include<fstream>
#include<iomanip>   
using namespace std;
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria{
    private:
        Presencial lpresencial[50]{};
        Semipresencial lsemipresencial[50]{};
        Virtual lvirtual[50]{};
        Escala lescala[10]{};
    public:
        void cargaEscalas();
        void cargaalumnos();

        void imprime();
};

