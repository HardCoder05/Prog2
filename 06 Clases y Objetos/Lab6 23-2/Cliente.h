
/* 
 * File:   Cliente.h
 * Author: 
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
#include "Pedido.h"

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
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void operator +=(const Pedido& ped);
    void imprimirProductos(ofstream &arch);
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[50]{};
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator >>(ifstream &arch, Cliente &cli);
void operator <<(ofstream &arch, Cliente &cli);

#endif /* CLIENTE_H */

