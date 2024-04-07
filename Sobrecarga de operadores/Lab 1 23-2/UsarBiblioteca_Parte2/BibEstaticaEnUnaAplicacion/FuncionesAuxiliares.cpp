
#include "FuncionesAuxiliares.h"

void leerClientes(struct Cliente *arregloClientes){
    struct Cliente c;
    ifstream archCliente;
    AperturaDeUnArchivoDeTextosParaLeer(archCliente, "Clientes.csv");
    int n=0;
    while (true) {
        if (!(archCliente >> arregloClientes[n])) {
            break;
        }
        /*int i = 0;
        for (i = 0; arregloClientes[i].dni != 0; i++);
        arregloClientes[i].dni = c.dni;
        strcpy(arregloClientes[i].nombre, c.nombre);
        arregloClientes[i].telefono = c.telefono;
        arregloClientes[i].cantidadProductosEntrgados = c.cantidadProductosEntrgados;
        arregloClientes[i].montoTotal = c.montoTotal;*/
        arregloClientes[n+1].dni = 0;
        n++;
    }
}

void leerProd(struct Producto *arregloProd){
    struct Producto p;
    ifstream archProd;
    AperturaDeUnArchivoDeTextosParaLeer(archProd, "Productos.csv");
    int n=0;
    while (true) {
        if (!(archProd >> arregloProd[n])) break;
        n++;
        /*int i = 0;
        while (true) {
            if (strcmp(arregloProd[i].codigo, "XXXXXXX") == 0) break;
            i++;
        }
        strcpy(arregloProd[i].codigo, p.codigo);
        strcpy(arregloProd[i].descripcion, p.descripcion);
        arregloProd[i].precio = p.precio;
        arregloProd[i].stock = p.stock;
        for(int j=0 ; j<20 ; j++) arregloProd[i].clientesNoServidos[j] = 
            p.clientesNoServidos[j];
        for(int j=0 ; j<20 ; j++) arregloProd[i].clientesServidos[j] = 
            p.clientesServidos[j];
        arregloProd[i].cantidadClientesNoServidos = p.cantidadClientesNoServidos;
        arregloProd[i].cantidadClientesServidos = p.cantidadClientesServidos;*/
    }
    strcpy(arregloProd[n+1].codigo, "XXXXXXX");
}

void leerPed(struct Cliente *arregloClientes,struct Producto *arregloProd){
    struct Pedido ped;
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos.csv");
    
    while(true){
        if(!(arch>>ped)) break;
        bool booleano = arregloProd += ped;
        arregloClientes += ped;
    }
}

void realizarReporte(struct Cliente *arregloClientes, struct Producto *arregloProd){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    archReporte<<"REPORTE DE CLIENTES"<<endl<<endl;
    
    for (int i = 0; arregloClientes[i].dni != 0; i++) {
        archReporte << arregloClientes[i];
    }
    
    archReporte<<endl<< "REPORTE DE PRODUCTOS"<<endl;
    for (int i = 0; strcmp(arregloProd[i].codigo, "XXXXXXX") != 0 and 
        arregloProd[i].precio > 0; i++) {
        archReporte << arregloProd[i];
    }
}

