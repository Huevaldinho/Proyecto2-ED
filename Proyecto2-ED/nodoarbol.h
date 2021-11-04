#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Estructuras.h"

class NodoArbol{
    public:
       Nodo * nodoPersona;//Persona
       NodoArbol* padre;
       NodoArbol* hijoizquierdo;
       NodoArbol* hijoderecho;

       NodoArbol();
       NodoArbol(Nodo *);

};

#endif // NODOARBOL_H
