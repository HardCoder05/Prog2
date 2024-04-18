
#include "memoriaexacta.h"

void lecturaDeLibros(const char *nom,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nom);
    char **buffLib[300], c;
    int buffStock[300], nDat = 0;
    double precio;
    
    while(true){
        buffLib[nDat] = leerLib(arch);
        if(arch.eof()) break;
        arch>>buffStock[nDat]>>c>>precio;
        arch.get();
        nDat++;
    }
    
    libros = new char**[nDat + 1];
    stock = new int*[nDat];
    
    for(int i=0 ; i<nDat ; i++){
        libros[i] = buffLib[i];
        int *aux = stock[i];
        aux = new int[2];
        aux[0] = buffStock[i];
        aux[1] = 0;
        stock[i] = aux;
    }
    
    libros[nDat] = buffLib[nDat];
}

char **leerLib(ifstream &arch){
    char *cod = leerCadena(arch, 8, ',');
    if(arch.eof()) return nullptr;
    char **ptr = new char*[3];
    ptr[0] = cod;
    ptr[1] = leerCadena(arch, 60, ',');
    ptr[2] = leerCadena(arch, 60, ',');
    return ptr;
}

char* leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}

void pruebaDeLecturaDeLibros(const char *nom,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nom);
    
    char **aux;
    int *auxiliar;
    for(int i=0 ; libros[i] != nullptr ; i++){
        aux = libros[i];
        auxiliar = stock[i];
        arch<<left<<setw(10)<<aux[0]<<setw(60)<<aux[1]<<setw(40)<<aux[2]<<right
            <<setw(8)<<auxiliar[0]<<setw(8)<<auxiliar[1]<<endl;
    }
}

void atencionDePedidos(const char *nom,char ***libros,int **&stock,
    int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nom);
    int numPed, dni, *buffPedCli[200], nDat = 0, nDatPed = 0, cantPed[200]={0};
    char c, cod[8], **buffPedLib[200]{};
    bool *buffPedAten[200]{};
    
    while(true){
        arch>>numPed;
        if(arch.eof()) break;
        arch>>c>>dni;
        int posCli = buscarCli(dni, buffPedCli, nDat);
        if(posCli == NO_ENCONTRADO) agregarDni(dni, buffPedCli, nDat, posCli);
        agregarPedidos(numPed, buffPedCli, posCli);
        buffPedLib[numPed - 1] = new char*[200]{};
        buffPedAten[numPed - 1] = new bool[200]{};
        while(true){
            if(arch.get() == '\n') break;
            arch>>cod;
            char *ptr = new char[strlen(cod) + 1];
            strcpy(ptr, cod);
            agregarLibros(ptr, buffPedLib[numPed - 1], cantPed[numPed - 1], 
                buffPedAten[numPed - 1], stock, libros);
        }
        nDatPed++;
    }
    
    asignarMemoriaBuffers(buffPedAten, buffPedCli, buffPedLib, nDat, 
        nDatPed, cantPed, pedidosClientes, pedidosLibros, pedidosAtendidos);
}

void asignarMemoriaBuffers(bool **buffAtendidos,int **buffClientes,
    char ***buffPedLibros,int nDat,int nDatPed,int *cantPed,
    int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    for(int i=0 ; i<nDat ; i++){
        recortarCliente(buffClientes[i]);
    }
    
    for(int i=0 ; i<nDatPed ; i++){
        recortarPedidos(buffPedLibros[i], buffAtendidos[i], cantPed[i]);
    }
    
    pedidosClientes = new int*[nDat + 1]{};
    pedidosLibros = new char **[nDatPed + 1]{};
    pedidosAtendidos = new bool *[nDatPed + 1]{};
    
    for(int i=0 ; i<nDat ; i++){
        pedidosClientes[i] = buffClientes[i];
    }
    
    for(int j=0 ; j<nDatPed ; j++){ //nDatPed = 172
        pedidosLibros[j] = buffPedLibros[j];
        pedidosAtendidos[j] = buffAtendidos[j];
    }
}

void recortarCliente(int *&buffClientes){
    int cant = buffClientes[1] + 2;
    int *aux = new int[cant + 1]{};
    
    for(int i=0 ; i<cant ; i++){
        aux[i] = buffClientes[i];
    }
    
    delete buffClientes;
    buffClientes = aux;
}

void recortarPedidos(char **&buffPedLibros, bool *&buffAtendidos,
    int cantSolicitados){
    char **auxLibros = new char *[cantSolicitados + 1]{};
    bool *auxAtendidos = new bool[cantSolicitados + 1]{};
    
    if(cantSolicitados > 0){
        for(int i=0 ; i<cantSolicitados ; i++){
            auxLibros[i] = buffPedLibros[i];
            auxAtendidos[i] = buffAtendidos[i];
        }
        
        delete buffAtendidos;
        delete buffPedLibros;
        buffAtendidos = auxAtendidos;
        buffPedLibros = auxLibros;
    }
    else{
        delete buffAtendidos;
        delete buffPedLibros;
        buffAtendidos = auxAtendidos;
        buffPedLibros = auxLibros;
    }
}

int buscarCli(int dni,int **buffPedCli,int nDat){
    for(int i=0 ; i<nDat ; i++){
        int *aux = buffPedCli[i]; 
        if(aux[0] == dni) return i;
    }
    
    return NO_ENCONTRADO;
}

void agregarDni(int dni,int **buffPedCli,int &nDat,int &posCli){
    int *aux = new int[200];
    aux[0] = dni;
    aux[1] = 0;
    buffPedCli[nDat] = aux;
    posCli = nDat;
    nDat++;
}

void agregarPedidos(int numPed, int **buffPedCli, int posCli) {
    int *cliente = buffPedCli[posCli]; // Obtener el cliente en la posición posCli
    int numPedidos = cliente[1]; // Obtener el número actual de pedidos del cliente
    
    // Verificar si el cliente tiene algún pedido registrado
    if (numPedidos == 0) {
        // Si no tiene pedidos, actualizar la cantidad de pedidos y 
        //agregar el nuevo pedido en la primera posición
        cliente[1]++;
        cliente[2] = numPed;
    } else {
        // Si ya tiene pedidos, agregar el nuevo pedido al final del 
        //arreglo de pedidos del cliente
        cliente[numPedidos + 2] = numPed;
        cliente[1]++; // Incrementar el contador de pedidos del cliente
    }
}

void agregarLibros(char *cod,char **buffPedLib,int &cantPed,bool *buffPedAten,
    int **&stock,char ***libros){
    buffPedLib[cantPed] = cod;
    
    int posLibro = buscarLibro(cod, libros);
    if(posLibro != NO_ENCONTRADO){
        int *aux = stock[posLibro];
        if(aux[0] > 0){
            buffPedAten[cantPed] = true;
            aux[0]--;
        }else{
            buffPedAten[cantPed] = false;
            aux[1]++;
        }
    }
    
    cantPed++;
}

int buscarLibro(char *cod,char ***libros){
    for(int i=0 ; libros[i] ; i++){
        char **aux = libros[i];
        if(strcmp(aux[0], cod) == 0) return i;
    }
    
    return NO_ENCONTRADO;
}

void reporteDeEntregaDePedidos (const char *nom,int **pedidosClientes, 
    char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nom);
    imprimirEncabezado(arch);
    
    for(int i=0 ; pedidosClientes[i] ; i++){
        int *aux = pedidosClientes[i];
        arch<<"Cliente:  "<<aux[0]<<endl;
        imprimirLinea(arch,'=');
        for(int j=0 ; j<aux[1] ; j++){
            imprimirLibros(arch, pedidosLibros, pedidosAtendidos, aux[j+2]);
        }
        imprimirLinea(arch,'=');
    }
}

void imprimirLibros(ofstream &arch,char ***pedidosLibros,bool **pedidosAtendidos,
    int numPed){
    for(int i=0 ; i<172 ; i++){
        if(i == numPed - 1){
            imprimirSubtitulos(arch);
            for(int j=0 ; pedidosAtendidos[j] ; j++){
                if(j == numPed - 1){
                    char **aux = pedidosLibros[i];
                    bool *auxiliar = pedidosAtendidos[i];
                    for(int k=0 ; aux[k] ; k++){
                        arch<<setw(9)<<numPed<<setw(25);
                        arch<<aux[k]<<setw(22);
                        if(auxiliar[k] == true){
                            arch<<"ATENDIDO"<<endl;
                        }else{
                            arch<<"NO ATENDIDO"<<endl;
                        }
                    } 
                }
            }
            
            imprimirLinea(arch, '-');
        }
    }
}

void imprimirEncabezado(ofstream &arch){
    arch<<setw(50)<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    imprimirLinea(arch,'=');
}

void imprimirSubtitulos(ofstream &arch){
    arch<<setw(15)<<"Pedido No."<<setw(25)<<"Codigo del libro"<<setw(18)
        <<"Observacion"<<endl;
    imprimirLinea(arch,'-');
}

void imprimirLinea(ofstream &arch,char car){
    for(int i=0 ; i<70 ; i++) arch<<car;
    arch<<endl;
}

