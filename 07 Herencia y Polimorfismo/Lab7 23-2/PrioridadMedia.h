
/* 
 * File:   PrioridadMedia.h
 * Author: 
 *
 * Created on 28 de mayo de 2024, 09:22 AM
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H
#include<fstream>
using namespace std;
#include "Pedido.h"

class PrioridadMedia:public Pedido{
public:
    PrioridadMedia();
    virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(char* desc);
    void GetDescripcion(char *desc) const;
    void lee(ifstream &);
    void actualiza(void);
    void imprime(ofstream &);
private:
    char *descripcion;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADMEDIA_H */

