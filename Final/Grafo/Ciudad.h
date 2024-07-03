
/* 
 * File:   Ciudad.h
 * Author: 
 *
 * Created on 3 de julio de 2024, 03:57 PM
 */

#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
using namespace std;

class Ciudad {
private:
    string nombre;
public:
    Ciudad();
    Ciudad(string nombre);
    bool operator == (const class Ciudad &orig)const;
    bool operator < (const class Ciudad &orig)const;
    void imprime()const;
};

#endif /* CIUDAD_H */

