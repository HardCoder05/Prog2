
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#define INCREMENTO 5
#define NO_ENCONTRO -1
using namespace std;
#include "AperturaDeArchivos.h"
#include "funciones.h"

void lecturaDeLibros(const char *nombreArchivo, char *** &libros, int ** &stock){
    /*Apertura del archivo*/
    ifstream archivoLectura;
    AperturaDeUnArchivoDeTextosParaLeer(archivoLectura,nombreArchivo);
    /*Declaracion de las variables*/
    char *codigo, **datosLibros, coma;
    int capacidad=0, numDatos=0, stockLibros;
    double precio;
    while(true){
        codigo=leerCadena(archivoLectura);
        if(archivoLectura.eof())
            break;
        datosLibros=leerDatosLibros(archivoLectura, codigo);
        archivoLectura>>stockLibros>>coma>>precio;
        archivoLectura.get();
        if(capacidad==numDatos)
            incrementarLibros(capacidad, libros,stock, numDatos);
        libros[numDatos-1]=datosLibros;
        stock[numDatos-1]=new int [2];
        int *punteroStock=stock[numDatos-1];
        punteroStock[0]=stockLibros;
        punteroStock[1]=0;
        numDatos++;
    }
}

void incrementarLibros(int &capacidad, char *** &libros,int ** &stock, 
        int &numDatos){
    capacidad+=INCREMENTO;
    char ***auxLibros;
    int **auxStock;
    if(numDatos==0){
        libros=new char **[capacidad]{};
        stock=new int *[capacidad]{};
        numDatos=1;
    }
    else{
        auxLibros=new char **[capacidad]{};
        auxStock=new int *[capacidad]{};
        for(int i=0; i<numDatos; i++){
            auxLibros[i]=libros[i];
            auxStock[i]=stock[i];
        }
        delete libros;
        delete stock;
        libros=auxLibros;
        stock=auxStock;
    }
}

char **leerDatosLibros(ifstream &archivoLectura, char *codigo){
    char **datosLibros=new char *[3];
    datosLibros[0]=codigo;
    datosLibros[1]=leerCadena(archivoLectura);
    datosLibros[2]=leerCadena(archivoLectura);
    return datosLibros;
}

char *leerCadena(ifstream &archivoLectura){
    char buffer[600], *cadena;
    archivoLectura.getline(buffer,600,',');
    if(archivoLectura.eof())
        return nullptr;
    cadena=new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void pruebaDeLecturaDeLibros(const char *nombreArchivo, char *** libros, 
        int ** stock){
    ofstream archivoImprimir;
    AperturaDeUnArchivoDeTextosParaEscribir(archivoImprimir,nombreArchivo);
    for(int i=0; libros[i]; i++){
        char **punteroLibro=libros[i];
        int *punteroStock=stock[i];
        archivoImprimir<<left<<setw(10)<<punteroLibro[0]<<setw(60)<<
            punteroLibro[1]<<setw(40)<<punteroLibro[2]<<right<<setw(5)<<
            punteroStock[0]<<setw(5)<<punteroStock[1]<<endl;
    }
}

void atencionDePedidos(const char *nombreArchivo,char *** libros, int ** stock, 
        int ** &pedidosClientes, char *** &pedidosLibros, 
        bool ** &pedidoAtendidos){
    ifstream archivoLectura;
    AperturaDeUnArchivoDeTextosParaLeer(archivoLectura,nombreArchivo);
    int numPedidos=0, capPedidos=0, codPedido, dniCliente, *capacidades, 
            *numDatos, capClientes=0,numClientes=0;
    char coma, **codigoPedidos;
    pedidosClientes=nullptr;
    pedidosLibros = nullptr;
    bool *pedidos;
    while(true){
        archivoLectura>>codPedido;
        if(archivoLectura.eof())
            break;
        archivoLectura>>coma>>dniCliente;
        leerLibroPedido(archivoLectura,codigoPedidos,pedidos, libros, stock);
        if(numPedidos==capPedidos)
            incrementarPedidos(pedidosLibros,pedidoAtendidos,numPedidos,capPedidos);
        pedidosLibros[numPedidos-1]=codigoPedidos;
        pedidoAtendidos[numPedidos-1]=pedidos;
        agregarInformacionCliente(pedidosClientes,dniCliente,codPedido, 
                capClientes,numClientes,capacidades, numDatos);
        numPedidos++;
    }
    delete capacidades;
    delete numDatos;
}

void agregarInformacionCliente(int ** &pedidosClientes,int dniCliente,
    int codPedido, int &capClientes, int &numClientes,
    int * &capacidades, int * &numDatos){
    int posicion;
    posicion=buscarDni(pedidosClientes,dniCliente);
    if(posicion==NO_ENCONTRO){
        if(numClientes==capClientes)
            incrementarClientes(pedidosClientes, capClientes,numClientes, 
                    capacidades, numDatos);
        capacidades[numClientes-1]=0;
        numDatos[numClientes-1]=0;
        posicion=numClientes-1;
        numClientes++;
    }
    agregarInformacionPedidos(pedidosClientes[posicion],capacidades[posicion], 
            numDatos[posicion], dniCliente,codPedido);
}

void agregarInformacionPedidos(int * &pedidosClientes,int &capacidad, 
            int &numDatos, int dniCliente,int codPedido){
    if(numDatos==capacidad)
        incrementarCodigoPedidos(pedidosClientes,capacidad,numDatos);
    pedidosClientes[0]=dniCliente;
    pedidosClientes[pedidosClientes[1]+2]=codPedido;
    pedidosClientes[1]++;
    numDatos++;
}

void incrementarCodigoPedidos(int *&pedidosClientes, int &capacidad, 
        int &numDatos){
    capacidad+=INCREMENTO;
    int *auxPedidosClientes;
    if(numDatos==0){
        pedidosClientes= new int [capacidad]{};
        numDatos=3;
    }
    else{
        auxPedidosClientes= new int[capacidad]{};
        for(int i=0; i<numDatos; i++){
            auxPedidosClientes[i]=pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes=auxPedidosClientes;
    }
}

void incrementarClientes(int ** &pedidosClientes, int &capClientes,
        int &numClientes, int * &capacidades, int * &numDatos){
    capClientes+=INCREMENTO;
    int **auxPedidos;
    int *auxCapacidades;
    int *auxDatos;
    if(pedidosClientes==nullptr){
        pedidosClientes=new int *[capClientes]{};
        capacidades= new int [capClientes]{};
        numDatos= new int [capClientes]{};
        numClientes=1;
    }
    else{
        auxPedidos=new int *[capClientes]{};
        auxCapacidades=new int [capClientes]{};
        auxDatos=new int [capClientes]{};
        for(int i=0; i<numClientes; i++){
            auxPedidos[i]=pedidosClientes[i];
            auxCapacidades[i]=capacidades[i];
            auxDatos[i]=numDatos[i];
        }
        delete pedidosClientes;
        delete capacidades;
        delete numDatos;
        pedidosClientes=auxPedidos;
        capacidades=auxCapacidades;
        numDatos=auxDatos;
    }
}

int buscarDni(int **pedidosClientes,int dniCliente){
    if(pedidosClientes==nullptr)
        return NO_ENCONTRO;
    for(int i=0; pedidosClientes[i]; i++){
        int *punteroCliente=pedidosClientes[i];
        if(punteroCliente[0]==dniCliente)
            return i;
    }
    return NO_ENCONTRO;
}

void incrementarPedidos(char *** &pedidosLibros,bool ** &pedidoAtendidos,
        int &numPedidos,int &capPedidos){
    capPedidos+=INCREMENTO;
    char *** auxPedidos;
    bool **auxPedidosAtendidos;
    if(pedidosLibros == nullptr){
        pedidosLibros= new char **[capPedidos]{};
        pedidoAtendidos= new bool *[capPedidos]{};
        numPedidos=1;
    }
    else{
        auxPedidos= new char **[capPedidos]{};
        auxPedidosAtendidos= new bool *[capPedidos]{};
        for(int i=0; i<numPedidos; i++){
            auxPedidos[i]=pedidosLibros[i];
            auxPedidosAtendidos[i]=pedidoAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidoAtendidos;
        pedidosLibros=auxPedidos;
        pedidoAtendidos=auxPedidosAtendidos;
    }
}

void leerLibroPedido(ifstream &archivoLectura,char ** &codigoPedidos,
        bool * &pedidos, char ***libros, int ** stock){
    int cantDatos=0, capacidad=0, posicion, *punteroStock;
    char *codigo, coma;
    while(true){
        codigo=leerCadenaLibros(archivoLectura);
        if(cantDatos==capacidad)
            incrementarLibrosPedidos(codigoPedidos, pedidos, cantDatos, 
                    capacidad);
        posicion=buscarLibro(libros,codigo);
        punteroStock=stock[posicion];
        codigoPedidos[cantDatos-1]=codigo;
        if(strcmp(codigo,"IIM5175")==0)
            coma=',';
        if(punteroStock[0]>0){
            pedidos[cantDatos-1]=true;
            punteroStock[0]--;
        }
        else{
            pedidos[cantDatos-1]=false;
            punteroStock[1]++;
        }
        cantDatos++;
        if(archivoLectura.get()=='\n')
            break;
    }
}

int buscarLibro(char ***libros, char *codigoLibro){
    for(int i=0; libros[i]; i++){
        char **punteroLibro=libros[i];
        if(strcmp(punteroLibro[0],codigoLibro)==0)
            return i;
    }
    return NO_ENCONTRO;
}

void incrementarLibrosPedidos(char ** &codigoPedidos, bool * &pedidos, 
        int &cantDatos, int &capacidad){
    capacidad+=INCREMENTO;
    char ** auxCodigo;
    bool *auxPedidos;
    if(cantDatos==0){
        codigoPedidos= new char *[capacidad]{};
        pedidos= new bool [capacidad]{};
        cantDatos=1;
    }
    else{
        auxCodigo=new char *[capacidad]{};
        auxPedidos=new bool [capacidad]{};
        for(int i=0; i<cantDatos; i++){
            auxCodigo[i]=codigoPedidos[i];
            auxPedidos[i]=pedidos[i];
        }
        delete codigoPedidos;
        delete pedidos;
        codigoPedidos=auxCodigo;
        pedidos=auxPedidos;
    }
}

char *leerCadenaLibros(ifstream &archivoLectura){
    char *cadena, buffer[100];
    archivoLectura>>buffer;
    if(archivoLectura.eof())
        return nullptr;
    cadena=new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void reporteDeEntregaDePedidos(const char *nombreArchivo,int **pedidosClientes,
            char ***pedidosLibros,bool **pedidoAtendidos){
    ofstream archivoImprimir;
    AperturaDeUnArchivoDeTextosParaEscribir(archivoImprimir,nombreArchivo);
    archivoImprimir<<right<<setw(90)<<"REPORTE DE ATENCION DE LECTURA"<<endl;
    imprimirCaracter(archivoImprimir,130,'=');
    for(int i=0; pedidosClientes[i]; i++){
        int *punteroCliente=pedidosClientes[i];
        archivoImprimir<<"CLIENTE: "<<punteroCliente[0]<<endl;
        imprimirCaracter(archivoImprimir,130,'=');
        for(int j=2; punteroCliente[j]; j++){
            archivoImprimir<<right<<setw(30)<<"Pedido No."<<setw(50)<<
                "Codigo del libro"<<setw(40)<<"Observacion"<<endl;
            imprimirCaracter(archivoImprimir,130,'-');
            archivoImprimir<<right<<setw(25)<<punteroCliente[j]<<endl;
            imprimirCaracter(archivoImprimir,130,'-');
        }
        
        imprimirCaracter(archivoImprimir,130,'=');
    }
}

void imprimirCaracter(ofstream &archivoImprimir,int n, char caracter){
    for(int i=0; i<n; i++)
        archivoImprimir<<caracter;
    archivoImprimir<<endl;
}