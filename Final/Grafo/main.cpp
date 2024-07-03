
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 3 de julio de 2024, 03:56 PM
 */

#include "Ciudad.h"
#include "Arista.h"
#include "GrafoDirigido.h"

int main(int argc, char** argv) {
    class Ciudad ciudadA("Ciudad A");
    class Ciudad ciudadB("Ciudad B");
    class Ciudad ciudadC("Ciudad C");
    class Ciudad ciudadD("Ciudad D");
    class Ciudad ciudadE("Ciudad E");
    class Ciudad ciudadF("Ciudad F");

    class Arista aristaAB(100,ciudadB);
    class Arista aristaAC(200,ciudadC);
    class Arista aristaBC(175,ciudadC);
    class Arista aristaCD(83,ciudadD);
    class Arista aristaFC(155,ciudadC);
    class Arista aristaFD(130,ciudadD);
    class Arista aristaFE(125,ciudadE);
    class Arista aristaEF(90,ciudadF);
    class Arista aristaEA(110,ciudadA);

    class GrafoDirigido grafo;

    grafo.agregarArista(ciudadA,aristaAB);
    grafo.agregarArista(ciudadA,aristaAC);
    grafo.agregarArista(ciudadB,aristaBC);
    grafo.agregarArista(ciudadC,aristaCD);
    grafo.agregarArista(ciudadE,aristaEA);
    grafo.agregarArista(ciudadE,aristaEF);
    grafo.agregarArista(ciudadF,aristaFC);
    grafo.agregarArista(ciudadF,aristaFD);
    grafo.agregarArista(ciudadF,aristaFE);

    grafo.imprimeGrafo();

    return 0;
}

