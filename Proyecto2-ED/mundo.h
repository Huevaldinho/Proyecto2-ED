#ifndef MUNDO_H
#define MUNDO_H

#include "Estructuras.h"

class Mundo{
    public:
        //Lista doble personas
        ListaPersonas * listaPersonas;
        int cantidadNombres;
        int cantidadApellidos;
        //QString nombres[cantidadNombres];
        //QString apellidos[cantidadApellidos];

        Mundo();
};

#endif // MUNDO_H
