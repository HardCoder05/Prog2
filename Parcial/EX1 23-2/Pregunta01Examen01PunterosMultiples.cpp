
#include "Pregunta01Examen01PunterosMultiples.h"

void cargarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,
    const char *nom){
    ifstream arch(nom, ios::in);
    
    char *cod, c;
    int dni, cant, dd, mm, aa, fecha, nDat = 0, cap = 0;
    fechaClienteCantidad = nullptr;
    while(true){
        cod = leerCadena(arch, 10, ',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        arch.get();
        fecha = aa*10000 + mm*100 + dd;
        if(cap == nDat) incrementarEspacios(fechaClienteCantidad, 
            codigoDelProducto, cap, nDat);
        llenarPedidos(fechaClienteCantidad, codigoDelProducto, cod, dni, cant, 
            fecha, nDat);
        nDat++;
    }
}

char *leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}

void llenarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,
    char *cod,int dni,int cant,int fecha,int &nDat){
    int *auxFecha;
    auxFecha = new int[3];
    auxFecha[0] = fecha;
    auxFecha[1] = dni;
    auxFecha[2] = cant;
    fechaClienteCantidad[nDat - 1] = auxFecha;
    
    codigoDelProducto[nDat - 1] = cod;
}

void incrementarEspacios(int **&fechaClienteCantidad,char **&codigoDelProducto,
    int &cap,int &nDat){
    cap += INCREMENTO;
    
    if(fechaClienteCantidad == nullptr){
        fechaClienteCantidad = new int*[cap]{};
        codigoDelProducto = new char*[cap]{};
        nDat = 1;
    }else{
        int **auxFecha = new int*[cap]{}; 
        char **auxCod = new char*[cap]{}; 
        
        for(int i=0 ; i<nDat ; i++){
            auxFecha[i] = fechaClienteCantidad[i];
            auxCod[i] = codigoDelProducto[i];
        }
        
        delete fechaClienteCantidad;
        delete codigoDelProducto;
        fechaClienteCantidad = auxFecha;
        codigoDelProducto = auxCod;
    }
}

void pruebaDeCargaDePedidos(int **fechaClienteCantidad,
    char **codigoDelProducto,const char*nom){
    ofstream arch(nom, ios::out);
    
    for(int i=0 ; fechaClienteCantidad[i] ; i++){
        int *auxFecha = fechaClienteCantidad[i];
        char *auxCod = codigoDelProducto[i];
        
        arch<<auxCod<<setw(10)<<auxFecha[0]<<setw(10)<<auxFecha[1]<<setw(7)
            <<auxFecha[2]<<endl;
    }
}

void ordenarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto){
    int numDat = 0;
    while(fechaClienteCantidad[numDat]) numDat++;
    qSort(fechaClienteCantidad, codigoDelProducto, 0, numDat - 1);
}

void qSort(int **datos,char **codigos,int izq,int der){
    int limite, pos;
    if(izq>=der) return;
    pos = (izq+der)/2;
    cambiar(datos[izq],datos[pos]);
    cambiar(codigos[izq],codigos[pos]);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
        int *auxI = datos[i], *auxIzq = datos[izq];
        if( auxI[0] < auxIzq[0]){
            limite++;
            cambiar(datos[limite],datos[i]);
            cambiar(codigos[limite],codigos[i]);
        }
    }
    cambiar(datos[limite],datos[izq]);
    cambiar(codigos[limite],codigos[izq]);
    qSort(datos, codigos, izq, limite-1);
    qSort(datos, codigos, limite+1, der);
}

void cambiar(int *&datosI,int *&datosK){
    int *auxCod;
    auxCod = datosI;
    datosI = datosK;
    datosK = auxCod;
}

void cambiar(char *&datosI,char *&datosK){
    char *auxCod;
    auxCod = datosI;
    datosI = datosK;
    datosK = auxCod;
}

