
/* 
 * File:   funciones.h
 * Author: Joshua Haro
 *
 * Created on April 16, 2024, 9:00 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void lecturaDeLibros(const char *, char *** &, int ** &);
void incrementarLibros(int &, char *** &,int ** &, int &);
char **leerDatosLibros(ifstream &, char *);
char *leerCadena(ifstream &);
void pruebaDeLecturaDeLibros(const char *, char *** , int ** );
void atencionDePedidos(const char *,char *** , int ** , int ** &, char *** &, 
        bool ** &);
void agregarInformacionCliente(int ** &,int ,int , int &, int &,int * &, int * &);
void agregarInformacionPedidos(int * &,int &, int &, int ,int );
void incrementarCodigoPedidos(int *&, int &, int &);
void incrementarClientes(int ** &, int &,int &, int * &, int * &);
int buscarDni(int **,int );
void incrementarPedidos(char *** &,bool ** &,int &,int &);
void leerLibroPedido(ifstream &,char ** &,bool * &, char ***, int ** );
int buscarLibro(char ***libros, char *);
void incrementarLibrosPedidos(char ** &, bool * &, int &, int &);
char *leerCadenaLibros(ifstream &);
void reporteDeEntregaDePedidos(const char *,int **,char ***,bool **);
void imprimirCaracter(ofstream &,int , char );

#endif /* FUNCIONES_H */

