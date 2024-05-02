
#include "listasGen.h"

void crearListaHeroes(void *arregloHeroes,void *&listaHeroes,void * 
    (*leerHeroe)(void *)){
    
    //inicializar lista
    construirLista(listaHeroes);
    
    //leer los datos
    void **heroes = (void **)arregloHeroes;
    for(int i=0 ; heroes[i] ; i++){
        void *reg = leerHeroe(heroes[i]); 
        //inserto los datos a la lista
        insertarRegistro(reg, listaHeroes);
    }
}

void construirLista(void *&lista_heroes){
    void **listaCola = new void *[2]{};
    listaCola[0] = nullptr;
    listaCola[1] = nullptr;
    
    lista_heroes = listaCola;
}

void insertarRegistro(void *dato, void*&lista){
    void **list = (void **)lista;
    void **ultimoNodo;

    //nodo a ingresar a la lista
    void **nuevoNodo = new void *[2]{};
    nuevoNodo[0] = dato;
    nuevoNodo[1] = nullptr;
    
    if(esListaVacia(lista)){ //simplemente agrego al comienzo
        list[0] = nuevoNodo;
    }else{
        ultimoNodo = (void **)list[1];
        ultimoNodo[1] = nuevoNodo;
    }
    
    list[1] = nuevoNodo;
}

bool esListaVacia(void *lista){
    void **list = (void **)lista;    
    return list[0] == nullptr;
}

void *leerHeroe(void *heroe){
    void **reg = (void **)heroe;
    
    int *cod = (int *)reg[0];
    char *nom = (char *)reg[1];
    char *rol = (char *)reg[2];
    char *cat = (char *)reg[3];
    double *puntaje = (double *)reg[4];
    
    void **dato = new void*[5];
    dato[0] = cod;
    dato[1] = nom;
    dato[2] = rol;
    dato[3] = cat;
    dato[4] = puntaje;
    
    return dato;
}

void imprimirListaHeroes(const char *nom,void *listaHeroes,
    void (*imprimirRegistro)(void *,ofstream &)){
    ofstream arch(nom, ios::out);
    
    void **recorrido, **nodo;
    void **registros = (void **)listaHeroes;
    
    if(!esListaVacia(listaHeroes)){
        recorrido = (void **)registros[0];
        
        while(recorrido){
            nodo = (void **)recorrido;
            imprimirRegistro(nodo[0], arch);
            recorrido = (void **)nodo[1];
        }
    }
}

void imprimirRegistro(void *registro,ofstream &arch){
    void **reg = (void **)registro;
    int *cod = (int *)reg[0];
    char *nom = (char *)reg[1];
    char *rol = (char *)reg[2];
    char *cat = (char *)reg[3];
    double *puntaje = (double *)reg[4];
    
    arch<<left<<setw(8)<<*cod<<setw(25)<<nom<<setw(12)<<rol<<setw(10)<<cat<<
        right<<setw(10)<<*puntaje<<endl;
}

void eliminarListaHeroes(void *&listaHeroes, void (*eliminarRegistro)
    (void **&,void **&)) {
    void **registros = (void **)listaHeroes;
    
    void **actual = (void **)registros[0];
    void **siguiente = nullptr;
    
    while (actual != nullptr) {
        siguiente = (void **)actual[1];
        // Comparamos el nodo actual con los siguientes para encontrar duplicados
        void **siguienteComparacion = (void **)siguiente;
        void **anterior = actual; // Nodo anterior al actual
        while (siguienteComparacion != nullptr) {
            if (sonRegistrosIguales(actual[0], siguienteComparacion[0])) {
                void **temp = (void **)siguienteComparacion[1]; // Siguiente nodo del duplicado
                eliminarRegistro(siguienteComparacion, temp); // Eliminar el duplicado
                anterior[1] = siguienteComparacion; // Enlazar el nodo anterior con el siguiente válido
            } else {
                // No es duplicado entonces avanzamos
                anterior = siguienteComparacion;
                siguienteComparacion = (void **)siguienteComparacion[1];
            }
        }

        // Avanzar al siguiente nodo
        actual = siguiente;
    }
}

bool sonRegistrosIguales(void *registro1, void *registro2){
    void **reg1 = (void **)registro1;
    void **reg2 = (void **)registro2;
        
    char *nom1 = (char *)reg1[1];
    char *nom2 = (char *)reg2[1];
    if (strcmp(nom1, nom2) != 0) {
        return false;
    }
    
    return true;
}

void eliminarRegistro(void **&siguienteComparacion,void **&temp){
    delete siguienteComparacion; // Liberar la memoria del duplicado
    siguienteComparacion = temp; // Apuntar al siguiente nodo después del duplicado
}

