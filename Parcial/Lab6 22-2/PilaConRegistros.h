
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch, int tam, char delim);
int cmpregistro(const void *a, const void *b);
void imprimeregistro(ofstream &arch, void *registro);

