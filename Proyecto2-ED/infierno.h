#ifndef INFIERNO_H
#define INFIERNO_H

#include "Estructuras.h"

class Infierno{
    public:
        Demonio * demonios[7];
        ListaPersonas * humanosMundo;
        Infierno(int,ListaPersonas *);
        void MeterFamiliaALosHeap();
        void Condenar(QString nombreDemonio);
        void imprimirFamiliasDeminios();
};

#endif // INFIERNO_H
