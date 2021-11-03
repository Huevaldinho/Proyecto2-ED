#ifndef ARBOLMUNDO_H
#define ARBOLMUNDO_H

#include "Estructuras.h"

class ArbolMundo{
    public:
        NodoArbol * raiz;
        ListaPersonas * listaPersonas;

            //MIO
       ArbolMundo();       
       int contadorNodos(NodoArbol*);
       void insertarAListaDesdeArbol(NodoArbol *& ,Nodo *);
       int maximo (int a, int b);
       int altura(NodoArbol*);
       int cantHojas(NodoArbol*);
       void mostrarArbol(NodoArbol*, int);//Listo

       //Codigo youtube, es la misma vara pero el problema sigue en como insertar usando la lista
       //siempre se abre hacia los costados poruqe esta ordenada
       bool esHoja(NodoArbol * );
       NodoArbol * crearNodo(Nodo *,NodoArbol*);//Listo
       void insertarNodo(NodoArbol*&, Nodo *,NodoArbol*);//Listo
       bool busqueda(NodoArbol*, int);//Listo
       void preOrden(NodoArbol*);//Listo
       void inOrden(NodoArbol*);//Listo
       void postOrden(NodoArbol*);//Listo
       void eliminar(NodoArbol*, int);//Listo
       void eliminarNodo(NodoArbol*);//Listo
       NodoArbol* minimo(NodoArbol*);//Listo
       void reemplazar(NodoArbol*, NodoArbol*);//Listo
       void destruirNodo(NodoArbol*);//Listo

};

#endif // ARBOLMUNDO_H
