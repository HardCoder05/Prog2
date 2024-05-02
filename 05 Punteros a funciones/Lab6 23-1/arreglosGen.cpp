
#include "arreglosGen.h"

void llenarArreglo(void *&arregloHeroes,int &cantHeroes,const char *nom){
    ifstream arch(nom, ios::in);
    
    void *buffHeroes[300]{};
    cantHeroes = 0;
    while(true){
        buffHeroes[cantHeroes] = leerHeroes(arch);
        if(buffHeroes[cantHeroes] == nullptr) break;
        cantHeroes++;
    }
    
    void **reg = new void*[cantHeroes + 1];
    for(int i=0 ; i<cantHeroes ; i++)  reg[i] = buffHeroes[i];
    arregloHeroes = reg;
    
//    void **arreglo = (void **)arregloHeroes;
//    for(int i=0 ; arreglo[i] ; i++){
//        void **reg = (void **)arreglo[i];
//        int *cod = (int *)reg[0];
//        char *nom = (char *)reg[1];
//        char *rol = (char *)reg[2];
//        char *cat = (char *)reg[3];
//        double *puntaje = (double *)reg[4];
//        cout<<left<<setw(8)<<*cod<<setw(25)<<nom<<setw(12)<<rol<<setw(10)<<cat<<
//            right<<setw(10)<<*puntaje<<endl;
//    }
}

void *leerHeroes(ifstream &arch){
    int cod, *codigo;
    char *nom, *rol, *cat, c;
    double puntaje, *punt;
    
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch>>c; //coma
    nom = leerCadena(arch, 60, ',');
    rol = leerCadena(arch, 60, ',');
    cat = leerCadena(arch, 60, ',');
    arch>>puntaje;
    
    codigo = new int(cod);
    punt = new double(puntaje);
    
    void **registro = new void*[5];
    registro[0] = codigo;
    registro[1] = nom;
    registro[2] = rol;
    registro[3] = cat;
    registro[4] = punt;
    
    return registro;
}

char *leerCadena(ifstream &arch,int cantCar,char del){
    char cadena[cantCar], *ptr;
    arch.getline(cadena, cantCar, del);
    if(arch.eof()) return nullptr;
    ptr = new char[strlen(cadena) + 1];
    strcpy(ptr, cadena);
    return ptr;
}

int cmpMulticriterioVoid(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    
    void **regA = (void **)ai[0];
    void **regB = (void **)bi[0];
    
    double *punA = (double *)regA[4];
    char *nomA = (char *)regA[1];
    
    double *punB = (double *)regB[4];
    char *nomB = (char *)regB[1];
    
    if(strcmp(nomA, nomB) == 0){
        return *punB - *punA;
    }else{
        return strcmp(nomA, nomB);
    }
}

