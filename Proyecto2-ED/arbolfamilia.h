#ifndef ARBOLFAMILIA_H
#define ARBOLFAMILIA_H

#include "Estructuras.h"

class ArbolFamilia{
    public:
        NodoArbol * raiz;
        QString apellidoFamilia;
        QString paisFamilia;

        ArbolFamilia();
        int height(NodoArbol *);//Listo
        int difference(NodoArbol *);//Listo
        NodoArbol *rr_rotat(NodoArbol *);//Listo
        NodoArbol *ll_rotat(NodoArbol *);//Listo
        NodoArbol *lr_rotat(NodoArbol*);//Listo
        NodoArbol *rl_rotat(NodoArbol *);//Listo
        NodoArbol * balance(NodoArbol *);//Listo
        NodoArbol * insert(NodoArbol*,  Nodo * persona);//Listo
        void show(NodoArbol*, int);//Listo
        void inorder(NodoArbol *);//Listo
        void preorder(NodoArbol *);//Listo
        void postorder(NodoArbol*);//Listo

};

#endif // ARBOLFAMILIA_H
