
#include "funciones.h"

void lecturaDeLibros(const char *nom,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nom);
    
    char *cod, *des, *autor, c;
    int cant, nDat = 0, cap = 0;
    double precio;
        
    libros = nullptr;
    stock = nullptr;
    while(true){
        cod = leerCadena(arch, 8, ',');
        if(arch.eof()) break;
        des = leerCadena(arch, 60, ',');
        autor = leerCadena(arch, 60, ',');
        arch>>cant>>c>>precio;
        arch.get();
        if(nDat == cap) incrementarMemoriaLibros(libros, stock, nDat, cap);
        insertarEnMemoriaLibros(libros, stock, cod, des, autor, cant, nDat);
        nDat++;
    }
}
  
char* leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}
  
void incrementarMemoriaLibros(char ***&libros,int **&stock,int &nDat,int &cap){
    cap += INCREMENTO;
    
    if(libros == nullptr){
        libros = new char**[cap]{};
        stock = new int*[cap]{};
        nDat = 1;
    }else{
        char*** auxLib = new char**[cap]{};
        int **auxStock = new int*[cap]{};
        
        for(int i=0 ; i<nDat ; i++){
            auxLib[i] = libros[i];
            auxStock[i] = stock[i];
        }
        
        delete libros;
        delete stock;
        libros = auxLib;
        stock = auxStock;
    }
}
  
void insertarEnMemoriaLibros(char ***&libros,int **&stock,char *cod,char *des,
    char *autor,int cant,int nDat){
    char **auxLib = libros[nDat - 1];
    auxLib = new char*[3];
    auxLib[0] = cod;
    auxLib[1] = des;
    auxLib[2] = autor;
    libros[nDat - 1] = auxLib;
    
    int *auxStock = stock[nDat - 1];
    auxStock = new int[2];
    auxStock[0] = cant;
    auxStock[1] = 0;
    stock[nDat - 1] = auxStock;
}
  
void pruebaDeLecturaDeLibros(const char *nom,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nom);
        
    char **aux;
    int *auxiliar;
    for(int i=0 ; libros[i] ; i++){
        aux = libros[i];
        auxiliar = stock[i];
        arch<<left<<setw(10)<<aux[0]<<setw(60)<<aux[1]<<setw(40)<<aux[2]<<right
            <<setw(8)<<auxiliar[0]<<setw(8)<<auxiliar[1]<<endl;
    } 
}

void atencionDePedidos(const char *nom,char ***libros,int **stock,
    int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nom);
    
    char c;
    int numPed, dni, nClientes = 0, capClientes = 0, *capacidadesPedCli = {}, 
        *numPedCli = {}, capPed = 0, capacidadesPedLib[200] = {}, numPedLib[200] = {};
    
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    while(true){
        arch>>numPed;
        if(arch.eof()) break;
        arch>>c>>dni;
        llenarPedidos(arch, libros, stock, pedidosLibros, pedidosAtendidos, 
            numPed, capPed, capacidadesPedLib, numPedLib);
        llenarClientes(pedidosClientes, dni, numPed, nClientes, capClientes, 
            capacidadesPedCli, numPedCli);
    }
    
//    for(int i=0 ; i<172 ; i++){
//        if(pedidosLibros[i] != nullptr){
//            cout<<i<<")";
//            char **auxi = pedidosLibros[i];
//            for(int j=0 ; auxi[j] ; j++){
//                cout<<auxi[j]<<" ";
//            }
//            cout<<endl;
//        }
//    }
//    
//    for(int i=0 ; i<173 ; i++){
//        if(pedidosAtendidos[i] != nullptr){
//            bool *aux = pedidosAtendidos[i];
//            cout << i << " )";
//            for(int j=0 ; j<numPedLib[i] ; j++){
//                cout<<aux[j]<<" ";
//            }
//            cout<<endl;
//        }
//    }
//    
//    for(int i=0 ; i<172 ; i++){
//        cout<<numPedLib[i]<<endl;
//    }
}

void llenarClientes(int **&pedidosClientes, int dni, int numPed, int &nClientes,
    int &capClientes,int *&capacidades,int *&numDatos){
    int pos = buscarCliente(pedidosClientes, dni);
    if(pos == NO_ENCONTRADO){ 
        if(nClientes == capClientes) incrementarMemoriaClientes(pedidosClientes,
            nClientes, capClientes, capacidades, numDatos);
        capacidades[nClientes - 1] = 0;
        numDatos[nClientes - 1] = 0; 
        pos = nClientes - 1;
        nClientes++;
    }
    insertarPedidos(pedidosClientes[pos], capacidades[pos], numDatos[pos], 
        dni, numPed);
}


int buscarCliente(int **pedidosClientes, int dni){
    if (pedidosClientes == nullptr) return NO_ENCONTRADO;
    
    for(int i=0 ; pedidosClientes[i] ; i++){
        if(pedidosClientes[i][0] == dni) return i;
    }
    return NO_ENCONTRADO;
}

void incrementarMemoriaClientes(int **&pedidosClientes,int &nClientes,
    int &capClientes,int *&capacidades,int *&numDatos){
    capClientes += INCREMENTO;
    
    if(pedidosClientes == nullptr){
        pedidosClientes = new int*[capClientes]{};
        capacidades = new int[capClientes]{};
        numDatos = new int[capClientes]{};
        nClientes = 1;
    }else{
        int **aux = new int*[capClientes]{};
        int *auxCap = new int[capClientes]{};
        int *auxNum = new int[capClientes]{};
        
        for(int i=0 ; i<nClientes ; i++){
            aux[i] = pedidosClientes[i];
            auxCap[i] = capacidades[i];
            auxNum[i] = numDatos[i];
        }
        
        delete pedidosClientes;
        delete capacidades;
        delete numDatos;
        pedidosClientes = aux;
        capacidades = auxCap;
        numDatos = auxNum;
    }
}

void insertarPedidos(int *&pedidosCliente, int &cap, int &numDatos, int dni,
    int numPed){
    if(numDatos == cap) incrementarMemoriaPedidos(pedidosCliente, cap, numDatos);
    pedidosCliente[0] = dni;
    pedidosCliente[pedidosCliente[1] + 2] = numPed;
    pedidosCliente[1]++;
    numDatos++;
}

void incrementarMemoriaPedidos(int *&pedidosCliente, int &cap, int &numDatos){
    cap += INCREMENTO;
    
    if(pedidosCliente == nullptr){
        pedidosCliente = new int[cap]{};
        numDatos = 3;
    }else{
        int *aux = new int[cap]{};
        
        for(int i=0 ; i<numDatos ; i++){
            aux[i] = pedidosCliente[i];
        }
        
        delete pedidosCliente;
        pedidosCliente = aux;
    }
}

void llenarPedidos(ifstream &arch, char ***libros, int **&stock, 
    char ***&pedidosLibros, bool **&pedidosAtendidos, 
    int numPed, int &capPed, int *capacidades, int *numDatos){
    
    while(capPed < numPed) capPed += INCREMENTO; 
    incrementarMemoriaPedidosLibros(pedidosLibros, pedidosAtendidos, 
                numPed, capPed, capacidades, numDatos);
    
    //capacidades[numPed - 1] = 0;
    //numDatos[numPed - 1] = 0;
    
    char cod[8], *ptr;
    while(true){
        if(arch.get() == '\n') break;
        arch>>cod;
        ptr = new char[strlen(cod) + 1];
        strcpy(ptr, cod);
        insertarLibros(libros, stock, pedidosLibros[numPed - 1],
            pedidosAtendidos[numPed - 1], capacidades[numPed - 1], 
            numDatos[numPed - 1], ptr);
    }
}

void incrementarMemoriaPedidosLibros(char ***&pedidosLibros, 
    bool **&pedidosAtendidos, int numPed, int &capPed,
    int *capacidades, int *numDatos){
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[capPed]{};
        pedidosAtendidos = new bool*[capPed]{};
        capacidades = new int[capPed]{};
        numDatos = new int[capPed]{};
    }else{
        char*** auxLib = new char**[capPed]{};
        bool **auxAtendidos = new bool*[capPed]{};
        int *auxCap = new int[capPed]{};
        int *auxNum = new int[capPed]{};
        
        for(int i=0 ; i<numPed ; i++){
            auxLib[i] = pedidosLibros[i];
            auxAtendidos[i] = pedidosAtendidos[i];
            auxCap[i] = capacidades[i];
            auxNum[i] = numDatos[i];
        }
        
        delete pedidosLibros;
        delete pedidosAtendidos;
        delete capacidades;
        delete numDatos;
        pedidosLibros = auxLib;
        pedidosAtendidos = auxAtendidos;
        capacidades = auxCap;
        numDatos = auxNum;
    }
}

void insertarLibros(char ***libros, int **&stock, char **&pedidosLibros, 
    bool *&pedidosAtendidos,int &cap, int &numDatos, char *ptr){
    if(numDatos == cap) incrementarMemoriaLibrosPedidos(pedidosLibros, 
        pedidosAtendidos, cap, numDatos);
    pedidosLibros[numDatos - 1] = ptr;
    llenarPedidosAtendidos(pedidosAtendidos, numDatos, libros, stock, ptr);
    numDatos++;
}

void incrementarMemoriaLibrosPedidos(char **&pedidosLibros, 
    bool *&pedidosAtendidos, int &cap, int &numDatos){
    cap += INCREMENTO;
    
    if(numDatos == 0){
        pedidosLibros = new char*[cap]{};
        pedidosAtendidos = new bool[cap]{};
        numDatos = 1;
    }else{
        char** auxLib = new char*[cap]{};
        bool *auxAtendidos = new bool[cap]{};
        
        for(int i=0 ; i<numDatos ; i++){
            auxLib[i] = pedidosLibros[i];
            auxAtendidos[i] = pedidosAtendidos[i];
        }
        
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxLib;
        pedidosAtendidos = auxAtendidos;
    }
}

void llenarPedidosAtendidos(bool *&pedidosAtendidos, int numDatos, 
    char ***libros, int **&stock, char *ptr){
    int pos = buscarLibro(libros, ptr);
    if(pos != NO_ENCONTRADO){
        if(stock[pos][0] > 0){
            pedidosAtendidos[numDatos - 1] = true;
            stock[pos][0]--;
        }else{
            pedidosAtendidos[numDatos - 1] = false;
            stock[pos][1]++;
        }
    }
}

int buscarLibro(char ***libros, char *cod){
    for(int i=0 ; libros[i] ; i++){
        if(strcmp(cod, libros[i][0]) == 0) return i;
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

