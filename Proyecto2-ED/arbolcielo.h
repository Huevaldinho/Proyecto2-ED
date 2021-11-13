#ifndef ARBOLCIELO_H
#define ARBOLCIELO_H

#include "Estructuras.h"

class ArbolCielo{//Almacena personas rescatadas del infierno
    public:
        Persona * raiz;//Persona rescatada
        ArbolCielo * hijoIzquierdo;
        ArbolCielo * hijoDerecho;
        ArbolCielo();
};

#endif // ARBOLCIELO_H
