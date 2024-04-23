
#include "funciones.h"

void cargaproductos(void *&productos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Productos2.csv");
    
    void *prod, *buffProd[200], **pr;
    int numProd = 0;
    while(true){
        prod = leeProd(arch);
        if(prod == nullptr) break;
        buffProd[numProd] = prod;
        numProd++;
    }
    
    pr = new void*[numProd];
    for(int i=0 ; i<numProd ; i++) pr[i] = buffProd[i];
    productos = pr;
    
//    void **pro = (void **)productos;
//    for(int i=0 ; pro[i] ; i++){
//        void **aux = (void **)pro[i];
//        char *codigo = (char *)aux[0];
//        char *desc = (char *)aux[1];
//        double *precios = (double *)aux[2];
//        char *tipoo = (char *)aux[3];
//        cout<<left<<setw(10)<<codigo<<setw(60)<<desc<<right<<setw(8)<<*precios<<
//            setw(8)<<*tipoo<<endl;
//    }
}

void *leeProd(ifstream &arch){
    char *cod, *des, c, tipo, *tipos;
    double precio, *precios;
    
    cod = leerCadena(arch, 8, ',');
    if(arch.eof()) return nullptr;
    des = leerCadena(arch, 60, ',');
    arch>>precio>>c>>tipo;
    precios = new double;
    *precios = precio;
    tipos = new char;
    *tipos = tipo;
    arch.get();
    
    void **prod = new void*[4];
    prod[0] = cod;
    prod[1] = des;
    prod[2] = precios;
    prod[3] = tipos;
    
    return prod;
}

char *leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) +  1];
    strcpy(ptr, cadena);
    return ptr;
}

void cargaclientes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Clientes2.csv");
    
    void *cli, *buffCli[200], **cl;
    int numCli = 0;
    while(true){
        cli = leeCli(arch);
        if(cli == nullptr) break;
        buffCli[numCli] = cli;
        numCli++;
    }
    
    cl = new void*[numCli];
    for(int i=0 ; i<numCli ; i++) cl[i] = buffCli[i];
    clientes = cl;
    
//    void **cliente = (void **)clientes;
//    for(int i=0 ; cliente[i] ; i++){
//        void **aux = (void **)cliente[i];
//        int *dni = (int *)aux[0];
//        char *nomb = (char *)aux[1];
//        double *cred = (double *)aux[3];
//        cout<<left<<setw(10)<<*dni<<setw(50)<<nomb<<right<<setw(8)<<*cred<<endl;
//    }
}

void *leeCli(ifstream &arch){
    int dni, tel, *dnii;
    char *nomb, c;
    double credito,  *cred;
    arch>>dni;
    if(arch.eof()) return nullptr;
    arch>>c;
    nomb = leerCadena(arch, 60, ',');
    arch>>tel>>c>>credito;
    dnii = new int;
    *dnii = dni;
    cred = new double;
    *cred = credito;
    
    void **cli = new void*[4];
    cli[0] = dnii;
    cli[1] = nomb;
    cli[2] = nullptr;
    cli[3] = cred;
    return cli;
}

void cargapedidos(void *productos,void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "Pedidos2.csv");
    
    char *cod, c;
    int dni, cant, posCli, numProd[200] = {};
    void **cli = (void **)clientes;
    
    while(true){
        cod = leerCadena(arch, 8, ',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant;
        arch.get();
        posCli = buscarCli(clientes, dni);
        if(posCli != NO_ENCONTRADO) llenarPedidos(productos, cod, cant, 
            cli[posCli], numProd[posCli]);
    }
    
    void **cliente = (void **)clientes;
    for(int i=0 ; cliente[i] ; i++){
        void **aux = (void **)cliente[i];
        asignarEspaciosExactos(aux[2], numProd[i]);
    }
}

void asignarEspaciosExactos(void *&pedidos,int cantDat){
    void **aux, **ped = (void **)pedidos;
    
    if(cantDat != 0){
        aux = new void*[cantDat + 1]{};
        for(int i=0 ; i<cantDat ; i++) aux[i] = ped[i];
        delete ped;
        ped = aux;
    }else{
        delete ped;
        ped = nullptr;
    }
    
    pedidos = ped;
}

int buscarCli(void *clientes,int dni){
    void **cliente = (void **)clientes;
    
    for(int i=0 ; cliente[i] ; i++){
        void **aux = (void **)cliente[i];
        int *dnii = (int *)aux[0];
        if(*dnii == dni) return i;
    }
    
    return NO_ENCONTRADO;
}

void llenarPedidos(void *productos,char *cod,int cant,void *&cliente,
    int &numDat){
    double precio = obtenerPrecio(productos, cod);
    if(precio > 0){
        int *cantidad = new int;
        *cantidad = cant;
        double *tot = new double;
        *tot = precio * cant;

        void **cli = (void **)cliente;
        void **pedidos = (void **)cli[2];
        double *credito = (double *)cli[3];
        
        if(*credito >= *tot){
            void **pedido = new void*[3];
            pedido[0] = cod;
            pedido[1] = cantidad;
            pedido[2] = tot;
            
            if(numDat == 0) pedidos = new void*[10]{};
            pedidos[numDat] = pedido;           
            
            *credito -= *tot; 
            
            cli[2] = pedidos;
            cli[3] = credito;
            
            numDat++;
        }
    }
}

double obtenerPrecio(void *productos,char *cod){
    void **pro = (void **)productos;
    for(int i=0 ; pro[i] ; i++){
        void **aux = (void **)pro[i];
        char *codigo = (char *)aux[0];
        double *precio = (double *)aux[2];
        if(strcmp(codigo, cod) == 0) return *precio;
    }
    
    return NO_ENCONTRADO;
}

void imprimereporte(void *clientes){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, "ReporteClientes.txt");
    
    arch.precision(2);
    arch<<fixed;
    
    void **cl = (void **)clientes;
    for(int i=0 ; cl[i] ; i++){
        void **auxiliar = (void **)cl[i];
        int *dni = (int *)auxiliar[0];
        char *nomb = (char *)auxiliar[1];
        double *cred = (double *)auxiliar[3];
        arch<<endl<<left<<setw(15)<<*dni<<setw(50)<<nomb<<right<<setw(8)<<*cred<<endl;
        if(auxiliar[2]){
            imprimirPedidos(arch, auxiliar);
        }else{
            arch<<"El cliente no tuvo pedidos"<<endl;
        }
    }
}

void imprimirPedidos(ofstream &arch,void **aux){
    void **pedidos = (void **)aux[2];
    arch<<"Pedidos: "<<endl;
    for(int i=0 ; pedidos[i] ; i++){
        void **pedido = (void **)pedidos[i];
        char *codigo = (char *)pedido[0];
        int *cantidad = (int *)pedido[1];
        double *total = (double *)pedido[2];
        arch<<codigo<<setw(7)<<*cantidad<<setw(15)<<*total<<endl;
    }
}

