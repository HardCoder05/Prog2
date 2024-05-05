
#include "Pregunta02Examen01PunterosGenericos.h"
#include "Pregunta01Examen01PunterosMultiples.h"

void cargarProductos(void *&productos,const char *nom){
    ifstream arch(nom, ios::in);
    
    void ***prod = nullptr, *producto;
    int cap = 0, nDat = 0;
    while(true){
        producto = leerProducto(arch);
        if(producto == nullptr) break;
        if(cap == nDat) incrementarProd(prod, cap, nDat);
        prod[nDat - 1] = new void*[2];
        void **auxProd = prod[nDat - 1];
        auxProd[0] = producto;
        auxProd[1] = nullptr;
        nDat++;
    }
    
    productos = prod;
    
    qsort(productos, nDat - 1, sizeof(void *), cmpProd);
}

void *leerProducto(ifstream &arch){
    char *cod, *des, c;
    int stock;
    double precio;
    
    cod = leerCadena(arch, 8, ',');
    if(arch.eof()) return nullptr;
    des = leerCadena(arch, 60, ',');
    arch>>precio>>c>>stock;
    arch.get();
    
    int *st = new int(stock);
    double *pre = new double(precio);
    
    void **producto = new void*[4];
    producto[0] = cod;
    producto[1] = des;
    producto[2] = pre;
    producto[3] = st;
    
    return producto;
}

void incrementarProd(void ***&prod,int &cap,int &nDat){
    cap += INCREMENTO;
    
    if(prod == nullptr){
        prod = new void **[cap]{};
        nDat = 1;
    }else{
        void ***auxProd = new void **[cap]{};
        
        for(int i=0 ; i<nDat ; i++){
            auxProd[i] = prod[i];
        }
        
        delete prod;
        prod = auxProd;
    }
}

int cmpProd(const void *a,const void *b){
    void **prodA = (void **)a, **prodB = (void **)b;
    void **proA = (void **)prodA[0], **proB = (void **)prodB[0];
    void **prA = (void **) proA[0], **prB = (void **)proB[0];
    char *codA = (char *)prA[0], *codB = (char *)prB[0];
    return strcmp(codA, codB);
}

void pruebaDeCargaDeProductos(void *productos,const char *nom){
    ofstream arch(nom, ios::out);
    
    void ***pro = (void ***)productos;
    for(int i=0 ; pro[i] ; i++){
        void **auxProd = pro[i];
        void **auxProductos = (void **)auxProd[0];
        //cout<<(int *)auxProd[1]<<endl;
        char *codigo = (char *)auxProductos[0];
        char *desc = (char *)auxProductos[1];
        double *precio = (double *)auxProductos[2];
        int *stock = (int *)auxProductos[3];
        arch<<left<<setw(10)<<codigo<<setw(60)<<desc<<right<<setw(8)<<*precio<<
            setw(8)<<*stock<<endl;
    }
}

