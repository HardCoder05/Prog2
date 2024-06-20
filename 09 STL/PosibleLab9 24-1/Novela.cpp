
/* 
 * File:   Novela.cpp
 * Author: rio88
 * 
 * Created on 20 de junio de 2024, 12:30 PM
 */

#include <cstring>
#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
    if(autor) delete []autor;
}

void Novela::SetAutor(char* aut) {
    if(autor) delete []autor;
    autor = new char[strlen(aut) + 1];
    strcpy(autor, aut);
}

void Novela::GetAutor(char *aut) const {
    if(autor == nullptr) aut[0] = 0;
    else strcpy(aut, autor);
}

void Novela::lee(ifstream &arch){
    Libro::lee(arch);
    
    char aut[60];
    
    arch.getline(aut, 60, '\n');
    SetAutor(aut);
}

void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    
    char aut[60];
    GetAutor(aut);
    
    arch<<aut<<endl;
}

