
/* 
 * File:   GrafoDirigido.h
 * Author: 
 *
 * Created on 3 de julio de 2024, 04:00 PM
 */

#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H

#include <map>
#include <vector>
using namespace std;
#include "Ciudad.h"
#include "Arista.h"

class GrafoDirigido {
private:
    map<Ciudad,vector<Arista>> adyacencias;
public:
    void agregarArista(const class Ciudad &origen,const class Arista &destino);
    void imprimeGrafo();
};

#endif /* GRAFODIRIGIDO_H */

