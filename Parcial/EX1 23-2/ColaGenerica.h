
/* 
 * File:   ColaGenerica.h
 * Author: rio88
 *
 * Created on 5 de mayo de 2024, 11:48 AM
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

void generacola(void *&cola);
void encolar(void *&cola,void *dato);
bool esColaVacia(void *cola);
void *desencolar(void *&cola);

#endif /* COLAGENERICA_H */

