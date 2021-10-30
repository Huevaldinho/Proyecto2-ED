#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Estructuras.h"

class NodoArbol{
    public:
        //DATO
       Nodo * nodoPersona;//Para poder avanzar una vez se encuentre a la persona.

       NodoArbol* hijoizquierdo;
       NodoArbol* hijoderecho;

       NodoArbol();
       NodoArbol(Nodo *);

};

#endif // NODOARBOL_H
