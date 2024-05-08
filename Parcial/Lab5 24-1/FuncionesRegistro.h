
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include<cstring>

void* leeregistro(ifstream &arch);
char *leeCadena(ifstream &arch,int cantCar,char del);
void imprimeregistro(ofstream &arch, void *dato);
int cmpReg(const void *dato1, const void *dato2);

