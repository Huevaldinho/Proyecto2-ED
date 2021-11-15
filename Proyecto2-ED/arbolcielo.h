#ifndef ARBOLCIELO_H
#define ARBOLCIELO_H

#include "Estructuras.h"

class ArbolCielo{//Almacena personas rescatadas del infierno
    public:
        NodoArbolHashCielo * raiz;//Persona rescatada

        ArbolCielo();
        int height(NodoArbolHashCielo *);//
        int difference(NodoArbolHashCielo *);//
        int cantidadNiveles(NodoArbolHashCielo *);
        int contadorNodos(NodoArbolHashCielo *);
        NodoArbolHashCielo *rr_rotat(NodoArbolHashCielo *);//
        NodoArbolHashCielo *ll_rotat(NodoArbolHashCielo *);//
        NodoArbolHashCielo *lr_rotat(NodoArbolHashCielo*);//
        NodoArbolHashCielo *rl_rotat(NodoArbolHashCielo *);//
        NodoArbolHashCielo * balance(NodoArbolHashCielo *);//
        NodoArbolHashCielo * insert(NodoArbolHashCielo*,  Persona * persona);//
        void show(NodoArbolHashCielo*, int);//
        void inorder(NodoArbolHashCielo *);//
        void preorder(NodoArbolHashCielo *);//
        void postorder(NodoArbolHashCielo*);//
        bool esHoja(NodoArbolHashCielo * arbol);
        void mostrarArbol(NodoArbolHashCielo * arbol , int cont);
        void escribirEnArchivoInorden(NodoArbolHashCielo *,QString,int);
};

#endif // ARBOLCIELO_H
