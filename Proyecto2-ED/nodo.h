#ifndef NODO_H
#define NODO_H

#include "Estructuras.h"

class Nodo{
    public:
        Persona * persona;
        Nodo * siguiente;
        Nodo * anterior;

        Nodo();
};

#endif // NODO_H
