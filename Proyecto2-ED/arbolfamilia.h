#ifndef ARBOLFAMILIA_H
#define ARBOLFAMILIA_H

#include "Estructuras.h"

class ArbolFamilia{
    public:
        NodoArbol * raiz;
        QString apellidoFamilia;
        QString paisFamilia;

        ListaPersonas * listaPersonas;

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
        void agregarHijos(NodoArbol *,Persona * padre,int cantidadHijosAinsertar);//Recibe una raiz para empezar a buscar
        //se le pasa el padre porque el hijo tiene que saber quien es su padre
        void insertarAListaDesdeArbol(NodoArbol *arbol,Nodo * nodoPersona);
        bool esHoja(NodoArbol * arbol);
        void mostrarArbol(NodoArbol*arbol , int cont);

};

#endif // ARBOLFAMILIA_H
