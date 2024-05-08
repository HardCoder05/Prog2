
#pragma
#include<iostream>
#include<fstream>
using namespace std;

void crealista(void *&ped,void* (*lee)(ifstream &),const char *nom);    
void construirlista(void *&ped);
void insertarlista(void *&ped, void *dato);
bool eslistavacia(void *ped);
void imprimelista(void *ped,void (*imprime)(ofstream &,void *),const char *nom);
void combinelista(void *&ped1,void *&ped2,void *&pedFinal,int (*cmp)(const void *,const void *));
void* quitalista(void *&ped);
void insertaordenado(void *&ped, void *dato, int (*cmp)(const void *,const void *));

