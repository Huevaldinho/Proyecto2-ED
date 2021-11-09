#ifndef PAIS_H
#define PAIS_H

#include "Estructuras.h"

class Pais{
    public:
        QString nombre;
        int cantidadPecados;
        int cantidadBuenasAcciones;
        int continente;// 1 - ASIA · 2 - AMÉRICA · 3 - ÁFRICA · 4 - ANTÁRTIDA · 5 - EUROPA · 6 - OCEANÍA.

        void calcularContinente();
};
#endif // PAIS_H
