
/* 
 * File:   sobrecargas.h
 * Author: 
 *
 * Created on 4 de abril de 2024, 11:14 AM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
using namespace std;

bool operator >>(ifstream &,struct Cliente &);
bool operator >>(ifstream &,struct Producto &);
bool operator >>(ifstream &,struct Pedido &);
void operator +=(struct Cliente *c,const struct Pedido &p);
bool operator +=(struct Producto *producto,struct Pedido &pedido);
void operator <<(ostream &out, const struct Cliente c);
void operator <<(ostream &out, const struct Producto p);

#endif /* SOBRECARGAS_H */

