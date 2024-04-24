
#include "funciones.h"

void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv", ios::in);
    
    void *prod, **pr = nullptr;
    int numProd = 0, cap = 0;
    while(true){
        prod = leeProd(arch);
        if(prod == nullptr) break;
        if(numProd == cap) incrementarProd(pr, cap, numProd);
        pr[numProd - 1] = prod;
        numProd++;
    }
    
    productos = pr;
    
    /*void **pro = (void **)productos;
    for(int i=0 ; pro[i] ; i++){
        void **aux = (void **)pro[i];
        char *codigo = (char *)aux[0];
        char *desc = (char *)aux[1];
        double *precios = (double *)aux[2];
        char *tipoo = (char *)aux[3];
        cout<<left<<setw(10)<<codigo<<setw(60)<<desc<<right<<setw(8)<<*precios<<
            setw(8)<<*tipoo<<endl;
    }*/
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

void incrementarProd(void **&pr,int &cap,int &numProd){
    cap += INCREMENTO;

    if(pr == nullptr){
        pr = new void*[cap]{};
        numProd = 1;
    }else{
        void **aux = new void*[cap]{};
        for(int i=0 ; i<numProd ; i++) aux[i] = pr[i];
        delete pr;
        pr = aux;
    }

}

void cargaclientes(void *&clientes){
    ifstream arch("Clientes2.csv", ios::in);
    
    void *cli, **cl = nullptr;
    int numCli = 0, cap = 0;
    while(true){
        cli = leeCli(arch);
        if(cli == nullptr) break;
        if(numCli == cap) incrementarCli(cl, cap, numCli);
        cl[numCli - 1] = cli;
        numCli++;
    }
    
    clientes = cl;
    
    /*void **cliente = (void **)clientes;
    for(int i=0 ; cliente[i] ; i++){
       void **aux = (void **)cliente[i];
       int *dni = (int *)aux[0];
       char *nomb = (char *)aux[1];
       double *cred = (double *)aux[3];
       cout<<left<<setw(10)<<*dni<<setw(50)<<nomb<<right<<setw(8)<<*cred<<endl;
    }*/
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

void incrementarCli(void **&cl,int &cap,int &numCli){
    cap += INCREMENTO;

    if(cl == nullptr){
        cl = new void*[cap]{};
        numCli = 1;
    }else{
        void **aux = new void*[cap]{};
        for(int i=0 ; i<numCli ; i++) aux[i] = cl[i];
        delete cl;
        cl = aux;
    }

}

void cargapedidos(void *productos,void *&clientes){
    ifstream arch("Pedidos2.csv", ios::in);

    void **cli = (void **)clientes;
    char *cod, c;
    int dni, cant, posCli, numProd[200] = {0}, cap[200] = {0};
    while(true){
        cod = leerCadena(arch, 8, ',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant;
        arch.get();
        posCli = buscarCli(clientes, dni);
        if(posCli != NO_ENCONTRADO) llenarPedidos(productos, cod, cant, 
            cli[posCli], numProd[posCli], cap[posCli]);
    }
}

int buscarCli(void *clientes,int dni){
    void **aux = (void **)clientes;
    for(int i=0 ; aux[i] ; i++){
        void **aux2 = (void **)aux[i];
        int *dnii = (int *)aux2[0];
        if(*dnii == dni) return i;
    }

    return NO_ENCONTRADO;
}

void llenarPedidos(void *productos,char *cod,int cant,void *cliente,int &numProd,int &cap){
    char tipo;
    double precio = obtenerPrecio(productos, cod, tipo);

    if(precio > 0){
        void **aux = (void **)cliente;
        void **pedidos = (void **)aux[2];
        double *cred = (double *)aux[3];
        int *cantidad = new int;
        *cantidad = cant;
        double *total = new double;
        *total = precio * cant;

        if(tipo == 'S'){
            if(*cred >= precio * cant){
                *cred -= *total;

                if(numProd == cap) incrementarPedidos(pedidos, cap, numProd);
                void **pedido = new void*[3];
                pedido[0] = cod;
                pedido[1] = cantidad;
                pedido[2] = total;

                pedidos[numProd - 1] = pedido;

                aux[2] = pedidos;
                aux[3] = cred;
                numProd++;
            }
        }else{
            if(numProd == cap) incrementarPedidos(pedidos, cap, numProd);
            void **pedido = new void*[3];
            pedido[0] = cod;
            pedido[1] = cantidad;
            pedido[2] = total;

            pedidos[numProd - 1] = pedido;

            aux[2] = pedidos;
            numProd++;
        }
    }
}

double obtenerPrecio(void *productos,char *cod,char &tipo){
    void **aux = (void **)productos;
    for(int i=0 ; aux[i] ; i++){
        void **aux2 = (void **)aux[i];
        char *codigo = (char *)aux2[0];
        if(strcmp(codigo, cod) == 0){
            double *precio = (double *)aux2[2];
            char *tipoo = (char *)aux2[3];
            tipo = *tipoo; //para ver si va a consumir linea de credito o no
            return *precio;
        }
    }

    return NO_ENCONTRADO;
}

void incrementarPedidos(void **&pedidos,int &cap,int &numProd){
    cap += INCREMENTO;

    if(pedidos == nullptr){
        pedidos = new void*[cap]{};
        numProd = 1;
    }else{
        void **aux = new void*[cap]{};
        for(int i=0 ; i<numProd ; i++) aux[i] = pedidos[i];
        delete pedidos;
        pedidos = aux;
    }

}

void imprimereporte(void *clientes){
    ofstream arch("ReporteClientes.txt", ios::out);
    arch.precision(2);
    arch<<fixed;

    void **aux = (void **)clientes;
    for(int i=0 ; aux[i] ; i++){
        void **aux2 = (void **)aux[i];
        int *dni = (int *)aux2[0];
        char *nomb = (char *)aux2[1];
        double *cred = (double *)aux2[3];
        void **pedidos = (void **)aux2[2];
        arch<<endl<<left<<setw(10)<<*dni<<setw(50)<<nomb<<right<<setw(8)<<*cred<<endl;
        if(aux2[2]){
            imprimirPedidos(pedidos, arch);
        }else{
            arch<<"El cliente no tiene pedidos"<<endl;
        }
    }
}

void imprimirPedidos(void **pedidos,ofstream &arch){
    for(int i=0 ; pedidos[i] ; i++){
        void **aux = (void **)pedidos[i];
        char *cod = (char *)aux[0];
        int *cant = (int *)aux[1];
        double *total = (double *)aux[2];
        arch<<cod<<setw(7)<<*cant<<setw(15)<<*total<<endl;
    }
}

