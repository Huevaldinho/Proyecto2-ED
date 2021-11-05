#ifndef NODOLISTAFALIMIAS_H
#define NODOLISTAFALIMIAS_H

#include "Estructuras.h"
class NodoListaFalimias{
    public:
        //Esta es una familia
//      NodoArbol * raiz;//Raiz del arbol de familia
        ArbolFamilia * familia;
        NodoListaFalimias * siguiente;//Siguiente familia
        NodoListaFalimias * anterior;//Familia anterior
        NodoListaFalimias();
        NodoListaFalimias(NodoArbol *);
        void imprimir();
};

#endif // NODOLISTAFALIMIAS_H
