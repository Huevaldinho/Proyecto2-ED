#ifndef NODOARBOLHASHCIELO_H
#define NODOARBOLHASHCIELO_H

#include "Estructuras.h"
class NodoArbolHashCielo{
    public:
        Persona * persona;
        NodoArbolHashCielo * hijoizquierdo;
        NodoArbolHashCielo * hijoderecho;
        NodoArbolHashCielo();
        NodoArbolHashCielo(Persona *);
};

#endif // NODOARBOLHASHCIELO_H
