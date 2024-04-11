
#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos(const char *nom,char ***&productos, int *&stock,
    double *&precios){
    char **buffPro[200], c;
    double buffPre[200];
    int buffStock[200], nDat = 0;
    
    ifstream arch(nom, ios::in);
    if(not arch.is_open()){
        cout<<"Error en el archivo "<<nom<<endl;
        exit(1);
    }
    
    while(true){
        buffPro[nDat] = leerProd(arch);
        if(arch.eof()) break;
        arch>>buffPre[nDat]>>c>>buffStock[nDat];
        arch.get();
        nDat++;
    }
    
    //esta parte hay que modular
    productos=new char**[nDat+1];
    stock = new int[nDat];
    precios = new double[nDat];
    
    for(int i=0 ; i<nDat ; i++){
        productos[i] = buffPro[i];
        stock[i] = buffStock[i];
        precios[i] = buffPre[i];
    }
    productos[nDat] = buffPro[nDat];
}

char **leerProd(ifstream &arch){
    char **dupla, *cadena;
    cadena = leerCadena(arch, 10, ',');
    if(arch.eof()) return nullptr;
    dupla = new char*[2];
    dupla[0] = cadena;
    dupla[1] = leerCadena(arch, 150, ',');
    return dupla;
}

char* leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char [strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
} 

void pruebaDeLecturaDeProductos(const char *nom,char ***productos, int *stock,
    double *precios){
    char **aux;
    ofstream arch(nom, ios::out);
    if(!arch){
        cout << "No se puede escribir";
        exit(1);
    }    
    
    for(int i=0 ; productos[i]!=nullptr ; i++){
        aux = productos[i];
        arch << setw(10) << aux[0] << setw(60) << aux[1] 
            <<setw(10)<< precios[i] <<setw(5)<<stock[i]<< endl;           
    }
}

void lecturaDePedidos(const char *nom,int *&fechapedidos,
    char ***&codigopedidos,int ***&dnicantpedidos){
    int bufffecha[600],**buffcantped[600],dni,cant,dd,mm,aa,fecha;
    int ind,i=0,numped[600];
    char **buffcodped[600],*codigo,c;
    
    ifstream arch(nom,ios::in);
    if(!arch){
        cout << "No se puede leer el archivo "<<nom<<endl;
        exit(1);
    }
    while(1){
        codigo=leerCadena(arch,8,',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa; 
        arch.get();
        fecha=aa*10000+mm*100+dd;
        ind = buscafecha(fecha,bufffecha,i);
        if(ind==-1)agregarfecha(bufffecha,buffcodped,buffcantped,fecha,numped,ind,i);
        agregarpedido(buffcodped[ind],buffcantped[ind],numped[ind],dni,cant,codigo);
    }
    cargaarreglos(fechapedidos,codigopedidos,dnicantpedidos,
            bufffecha,buffcodped,buffcantped,numped,i);
}

void cargaarreglos(int *&fechapedidos,
    char ***&codigopedidos,int ***&dnicantpedidos,
    int *bufffecha,char ***buffcodped,int ***buffcantped,
    int *numped,int n){
    fechapedidos = new int[n+1];
    codigopedidos = new char**[n];
    dnicantpedidos = new int**[n];
    
    for(int i=0;i<n;i++){
        fechapedidos[i] = bufffecha[i];
        codigopedidos[i] = new char*[numped[i]+1]; 
        dnicantpedidos[i] = new int*[numped[i]];
        carganivelinterno(codigopedidos[i],dnicantpedidos[i],
                buffcodped[i],buffcantped[i],numped[i]);
        // aqui elimina los buffers dinamicos
        delete buffcodped[i];
        delete buffcantped[i];
    }
    fechapedidos[n] = 0;
}

void carganivelinterno(char **&codigoped,int **&dnicantped,
    char **buffcodpe,int **buffcantpe,int cantped){
    for(int i=0;i<cantped;i++){
        codigoped[i] = buffcodpe[i];
        dnicantped[i] = buffcantpe[i];
    }
    codigoped[cantped] = nullptr;   
}

void agregarpedido(char **buffcod,int **buffdni,int &n,
        int dni,int cant,char *codigo){
    int *aux;
    
    buffdni[n]= new int[2];
    aux = buffdni[n];
    aux[0] = dni;
    aux[1] = cant;
    buffcod[n] = codigo;
    n++;
}

void agregarfecha(int *buffecha,char ***buffcodped,
       int ***buffcantped,int fecha,int *numped, int &ind,int &n){
    buffecha[n] = fecha;
    buffcodped[n] = new char*[600];
    buffcantped[n] = new int*[600];
    numped[n] = 0;
    ind = n;
    n++;
}

int  buscafecha(int fecha,int *bufffecha,int n){
    for(int i=0;i<n;i++)
        if(fecha==bufffecha[i]) return i;
    return -1;
}

void pruebaDeLecturaDePedidos(const char *nom, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos){
    ofstream arch (nom, ios::out);
    if(not arch.is_open()){
        cout << "No se pudo abrir el archivo"<<nom;
        exit(1);
    }
    
    char **auxCodigos;
    int **auxDni, *auxDniCant;
    
    for(int i=0 ; fechaPedidos[i] != 0 ; i++){
        arch << fechaPedidos[i] << endl;
        auxCodigos = codigoPedidos[i];
        auxDni = dniCantPedidos[i];
        for(int j=0 ; auxCodigos[j] != nullptr ; j++){
            auxDniCant = auxDni[j];
            arch << setw(10) << auxCodigos[j] << setw(15) << auxDniCant[0] << "  " 
                << auxDniCant[1] << endl;
        }
        arch << endl;    
    }
}

void reporteDeEnvioDePedidos (const char *nom,char ***productos,int *&stock, 
    double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    ofstream  arch(nom, ios::out);
    if(not arch.is_open()){
        cout<<"Error no se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    
    imprimirEncabezado(arch);
    char **auxCodPed;
    int **aux, *auxDniCant;
    double totalIngresado, totalPerdido, totalIngresos = 0, totalPerdidas = 0;
    for(int i=0 ; fechaPedidos[i] != 0 ; i++){
        imprimirFecha(arch,fechaPedidos[i]);
        arch<<"No.   DNI"<<setw(20)<<"Producto"<<setw(62)<<"Cantidad"<<setw(12)
            <<"Precio"<<setw(20)<<"Total de ingresos"<<endl;
        imprimirLinea(arch, '-');
        auxCodPed = codigoPedidos[i];
        aux = dniCantPedidos[i];
        totalIngresado = 0;
        totalPerdido = 0;
        for(int j=0 ; auxCodPed[j] != nullptr ; j++){
            auxDniCant = aux[j];
            arch << setw(2) << j+1 << ")  " << auxDniCant[0] << setw(6);
            imprimirPedido(arch, auxCodPed[j], productos, auxDniCant[1],
                precios, stock, totalIngresado, totalPerdido);
        }
        imprimirTotales(arch, totalIngresado, totalPerdido, totalIngresos, 
            totalPerdidas);
    }
    imprimirResumen(arch, totalIngresos, totalPerdidas);
}

void imprimirPedido(ofstream &arch, char *codProd,char ***productos,int cant,
    double *precios,int *&stock,double &totalIngresado,double &totalPerdido){
    int pos = buscarProd(productos, codProd);
    char **aux;
    if(pos != NO_ENCONTRADO){
        for(int i=0 ; codProd[i] ; i++) arch<<codProd[i];
        arch<<"  ";
        for(int i=0 ; productos[i] != nullptr ; i++){
            aux = productos[i];
            if(i == pos){
                arch<<aux[1];
                for(int j=0 ; j < 60 - strlen(aux[1]) ; j++) arch<<" ";
            }
        }
        arch<<cant<<setw(15)<<precios[pos];
        if(stock[pos] >= cant){
            arch<<setw(15)<<precios[pos] * cant<<endl;
            if(stock[pos] - cant >= 0) stock[pos] -= cant;
            totalIngresado +=  precios[pos] * cant;
        }else{
            arch<<setw(15)<<"SIN STOCK"<<endl;
            totalPerdido +=  precios[pos] * cant;
        }
    }
}

int buscarProd(char ***productos,char *codProd){
    char **aux;
    for(int i=0 ; productos[i] != nullptr ; i++){
        aux = productos[i];
        if(strcmp(aux[0], codProd) == 0) return i;
    }
    
    return NO_ENCONTRADO;
}

void imprimirEncabezado(ofstream &arch){
    arch<<setw(50)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    imprimirLinea(arch,'=');
}

//20230828
void imprimirFecha(ofstream &arch,int fecha){
    int dd, mm, aa;
    aa = fecha/10000;
    mm = (fecha/100)%100;
    dd = fecha%100;
    arch<<"Fecha:   "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"
        <<setfill(' ')<<setw(4)<<aa<<endl;
    imprimirLinea(arch, '=');
}

void imprimirResumen(ofstream &arch,double totalIngresos,double totalPerdidas){
    arch<<"Resumen de ingresos: "<<endl;
    arch<<"Total de ingresos en el periodo:  "<<totalIngresos<<endl;
    arch<<"Total perdido por falta de stock:  "<<totalPerdidas<<endl;
    imprimirLinea(arch, '=');
}

void imprimirTotales(ofstream &arch,double totalIngresado,double totalPerdido,
    double &totalIngresos,double &totalPerdidas){
    imprimirLinea(arch, '-');
    arch<<"Total ingresado: "<<setw(102)<<totalIngresado<<endl;
    arch<<"Total perdido por falta de stock: ";
    if(totalPerdido > 0){
        arch<<setw(84)<<totalPerdido<<endl;
    }else{
        arch<<setw(83)<<totalPerdido<<endl;
    }
    
    imprimirLinea(arch, '=');
    //Tambien lleno lo del resumen final
    totalIngresos += totalIngresado;
    totalPerdidas += totalPerdido;
}

void imprimirLinea(ofstream &arch,char car){
    for(int i=0 ; i<125 ; i++) arch<<car;
    arch<<endl;
    //tambien establezco numero de decimales
    arch.precision(2);
    arch<<fixed;
}

