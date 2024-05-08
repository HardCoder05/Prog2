
#include "BibliotecaGenerica.h"
#include "FuncionesEnteros.h"
#include "FuncionesRegistro.h"

int main(){
    void *ped1, *ped2, *pedFinal;

    crealista(ped1, leenum, "RegistroNum1.txt");
    imprimelista(ped1, imprimenum, "RepNum1.txt");
    crealista(ped2, leenum, "RegistroNum2.txt");
    imprimelista(ped2, imprimenum, "RepNum2.txt");
    combinelista(ped1, ped2, pedFinal, cmpNum);
    imprimelista(pedFinal, imprimenum, "RepNumFinal.txt");

    crealista(ped1, leeregistro, "Pedidos31.csv");
    imprimelista(ped1, imprimeregistro, "RepPedidos31.txt");
    crealista(ped2, leeregistro, "Pedidos32.csv");
    imprimelista(ped2, imprimeregistro, "RepPedidos32.txt");
    combinelista(ped1, ped2, pedFinal, cmpReg);
    imprimelista(pedFinal, imprimeregistro, "RepPedidosFinal.txt");

    return 0;
}








