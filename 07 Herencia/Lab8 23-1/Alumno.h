
/* 
 * File:   Alumno.h
 * Author: rio88
 *
 * Created on 25 de mayo de 2024, 06:08 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala ;
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
    void leerDatos(ifstream &);
    void imprime(ofstream&);
};


#endif /* ALUMNO_H */

