
/* 
 * File:   Virtual.cpp
 * Author: rio88
 * 
 * Created on 6 de junio de 2024, 12:49 PM
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if(licencia) delete []licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if(licencia!=nullptr) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia,cad);
}

void Virtual::GetLicencia(char*cad) const {
    if(licencia==nullptr) cad[0]=0;
    else strcpy(cad,licencia);
}

