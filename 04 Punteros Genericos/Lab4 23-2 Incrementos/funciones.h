
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>
#define INCREMENTO 5
#define NO_ENCONTRADO -1

void cargaproductos(void *&);
void *leeProd(ifstream &);
char *leerCadena(ifstream &,int ,char );
void incrementarProd(void **&,int &,int &);

void cargaclientes(void *&);
void *leeCli(ifstream &);
void incrementarCli(void **&,int &,int &);

void cargapedidos(void *productos,void *&clientes);
int buscarCli(void *clientes,int dni);
void llenarPedidos(void *productos,char *cod,int cant,void *cliente,int &numProd,int &cap);
double obtenerPrecio(void *productos,char *cod,char &tipo);
void incrementarPedidos(void **&pedidos,int &cap,int &numProd);

void imprimereporte(void *clientes);
void imprimirPedidos(void **pedidos,ofstream &arch);

