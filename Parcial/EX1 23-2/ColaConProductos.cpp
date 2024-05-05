
#include "ColaConProductos.h"
#include "ColaGenerica.h"

void procesarPedidos(int **fechaClienteCantidad,char **&codigoDelProducto, 
    void *&productos){
    
    for(int i=0 ; fechaClienteCantidad[i] ; i++){
        int *auxFecha = fechaClienteCantidad[i]; 
        char *cod = codigoDelProducto[i];
        int posProd = buscarProd(productos, cod);
        if(posProd != NO_ENCONTRADO){
            void **prod = (void **)productos;
            void **pro = (void **)prod[posProd];
            void **producto = (void **)pro[0];
            int *stock = (int *)producto[3];
            
            if(*stock >= auxFecha[2]){
                llenarProd(auxFecha, pro);
                *stock -= auxFecha[2];
            }
        }
    }
}

int buscarProd(void *productos,char *cod){
    void **prod = (void **)productos;
    
    for(int i=0 ; prod[i] ; i++){
        void **pro = (void **)prod[i];
        void **producto = (void **)pro[0];
        char *codigo = (char *)producto[0];
        if(strcmp(codigo, cod) == 0) return i;
    }
    
    return NO_ENCONTRADO;
}

void llenarProd(int *auxFecha,void **pro){
    void *cola = pro[1];
    
    if(cola == nullptr) generacola(cola);
    
    void **elementos = new void*[3];
    int *fecha = new int(auxFecha[0]);
    int *dni = new int(auxFecha[1]);
    int *cant = new int(auxFecha[2]);
    
    elementos[0] = fecha;
    elementos[1] = dni;
    elementos[2] = cant;
    
    void *dato = elementos;
    
    encolar(cola, dato);
    
    pro[1] = cola;
}

void reporteDePedidos(void *productos,const char *nom){
    ofstream arch(nom, ios::out);
    
    void ***pro = (void ***)productos;
    for(int i=0 ; pro[i] ; i++){
        void **auxProd = pro[i];
        void **auxProductos = (void **)auxProd[0];
        char *codigo = (char *)auxProductos[0];
        char *desc = (char *)auxProductos[1];
        double *precio = (double *)auxProductos[2];
        int *stock = (int *)auxProductos[3];
        arch<<"Producto "<<i+1<<":"<<endl;
        arch<<left<<setw(10)<<codigo<<setw(60)<<desc<<right<<endl;
        arch<<"Precio: "<<*precio<<setw(15)<<"Stock: "<<*stock<<endl;
        arch<<"Pedidos aceptados: "<<endl;
        arch<<"Fecha"<<setw(15)<<"DNI"<<setw(15)<<"Cantidad"<<endl;
        if(auxProd[1]){
            imprimirDetallesPed(auxProd[1], arch);
        }else{
            arch<<"-----"<<setw(16)<<"-----"<<setw(12)<<"-----"<<endl;
        }
        arch<<endl;
    }
}

void imprimirDetallesPed(void *cola,ofstream &arch){
    void **queue = (void **)cola;
    void **recorrido = (void **)queue[0]; //paso el inicio (cabeza)
    
    while(recorrido){
        void **nodo = (void **)recorrido; 
        void *dato = (void **)nodo[0]; 
        void **elementos = (void **)dato;
        int *fecha = (int *)elementos[0];
        int *dni = (int *)elementos[1];
        int *cant = (int *)elementos[2];
        arch<<*fecha<<setw(15)<<*dni<<setw(8)<<*cant<<endl;
        recorrido = (void **)nodo[1]; //sgte
    }
}

