
/* 
 * File:   Ciudad.cpp
 * Author: 
 * 
 * Created on 3 de julio de 2024, 03:57 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Ciudad.h"

Ciudad::Ciudad() {
    nombre.clear();
}

Ciudad::Ciudad(string nombre) {
    this->nombre=nombre;
}

bool Ciudad::operator <(const class Ciudad &orig) const{
    return nombre.compare(orig.nombre) < 0;
}

bool Ciudad::operator ==(const class Ciudad &orig)const {
    return nombre.compare(orig.nombre) == 0;
}

void Ciudad::imprime()const {
    cout<<nombre<<endl;
}

