#ifndef ARBOLTRIARIO_H
#define ARBOLTRIARIO_H

#include "Estructuras.h"

class ArbolTriario{
    public:
        ArbolTriario();
        Angel *root;
        int cntNodos;
        int genActual; // altura
        QString nombresAngeles[10];

        Angel* crearNivel(Angel*);
        void crearNivel();//se llama a este
        void print();//se llama a este
        void print(Angel*);
};

#endif // ARBOLTRIARIO_H
