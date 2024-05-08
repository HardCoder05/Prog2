
#include "BibliotecaGenerica.h"
#include "FuncionesEnteros.h"

int main(){
    void *ped1, *ped2, *pedFinal;

    crealista(ped1, leenum, "RegistroNum1.txt");
    imprimelista(ped1, imprimenum, "RepNum1.txt");
    crealista(ped2, leenum, "RegistroNum2.txt");
    imprimelista(ped2, imprimenum, "RepNum2.txt");
    combinelista(ped1, ped2, pedFinal, cmpNum);
    imprimelista(pedFinal, imprimenum, "RepNumFinal.txt");

    return 0;
}








