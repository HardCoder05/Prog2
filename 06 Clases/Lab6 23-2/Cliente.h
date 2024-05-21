
/* 
 * File:   Cliente.h
 * Author: rio88
 *
 * Created on 21 de mayo de 2024, 09:23 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include<fstream>
#include<iomanip>
using namespace std;
#include <cstring>
#include "ProductoEntregado.h"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTelefono(int telefono);
    void SetNombre(const char* nomb);
    void SetDni(int dni);
    int GetTelefono() const;
    char* GetNombre() const;
    int GetDni() const;
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[50]{};
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator >>(ifstream &arch, Cliente &cli);

#endif /* CLIENTE_H */

