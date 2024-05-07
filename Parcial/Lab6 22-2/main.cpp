
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

int main(){
   void *arreglo, *pilaini, *pilafin;

    cargaarreglo(arreglo, cmpnumero, leenumero, "numeros.txt");
    cargapila(pilaini,arreglo);
    // muevepila(pilaini,pilafin);
    imprimepila(pilaini,imprimenumero,"repnumeros.txt");
    
    cargaarreglo(arreglo, cmpregistro, leeregistro, "Medicinas.csv");
    cargapila(pilaini,arreglo);
    //muevepila(pilaini,pilafin);
    imprimepila(pilaini,imprimeregistro,"repmedicinas.txt");

    return 0;
}






