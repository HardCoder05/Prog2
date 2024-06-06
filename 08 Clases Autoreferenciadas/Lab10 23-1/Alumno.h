
/* 
 * File:   Alumno.h
 * Author: rio88
 *
 * Created on 6 de junio de 2024, 12:41 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala ;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;

    virtual void lee(ifstream &);
    virtual void actualizaTotal(double);
    virtual void imprime(ofstream&);
};

#endif /* ALUMNO_H */

