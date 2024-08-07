
/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on 2 de mayo de 2024, 10:44 AM
 */

#include <cstdlib>
#include "arreglosGen.h"
#include "listasGen.h"

int main(int argc, char** argv) {
    void *arregloHeroes, *listaHeroes;
    int cantHeroes;
    
    llenarArreglo(arregloHeroes, cantHeroes, "heroes_changelog_1223.csv");
    qsort(arregloHeroes, cantHeroes, sizeof(void *), cmpMulticriterioVoid);
    
    crearListaHeroes(arregloHeroes, listaHeroes, leerHeroe);
    imprimirListaHeroes("ListaHeroesRepetidos.txt", listaHeroes, imprimirRegistro);
    
    eliminarListaHeroes(listaHeroes, eliminarRegistro);
    imprimirListaHeroes("ListaHeroesFinal.txt", listaHeroes, imprimirRegistro);
    
    return 0;
}

