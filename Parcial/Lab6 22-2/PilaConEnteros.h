
#pragma
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define INCREMENTO 5

void* leenumero(ifstream &arch);
int cmpnumero(const void *a,const void *b);
void imprimenumero(ofstream &arch,void *dato);
