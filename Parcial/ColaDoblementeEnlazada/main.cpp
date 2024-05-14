
#include <iostream>
#include <fstream>
using namespace std;
#include "cola.h"

void leerArchivo(void *&cola){
    ifstream archivo("numeros.txt", ios::in);
    int numero;
    while(true){
        archivo>>numero;
        if(archivo.eof()) break;
        int *num = new int;
        *num = numero;
        if(numero == 1){
            void *dato = num;
            encolar(cola, dato);
        }else if(numero == 3){
            void *dato = num;
            insertarinicio(cola, dato);
        }else{
            void *dato = num;
            //insertarPosicion(cola, dato);
        }
    }
}

int main(){
    void *cola;

    generarCola(cola);
    leerArchivo(cola);
    imprimirCola(cola);

}

