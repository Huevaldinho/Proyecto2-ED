#ifndef ARBOLMUNDO_H
#define ARBOLMUNDO_H

#include "Estructuras.h"

class ArbolMundo{
    public:
        NodoArbol * raiz;
        ListaPersonas * listaPersonas;


       ArbolMundo();
       void insertar(Nodo *);//Esta funcion utiliza insertar Nodo * insertar(NodoArbol*,Nodo*)
       NodoArbol * insertarRecursivo (NodoArbol *,Nodo *);
       int contadorNodos(NodoArbol*);
       int maximo (int a, int b);
       int altura(NodoArbol*);
       int cantHojas(NodoArbol*);
       void imprimirArbol(NodoArbol *,int);


};

#endif // ARBOLMUNDO_H
