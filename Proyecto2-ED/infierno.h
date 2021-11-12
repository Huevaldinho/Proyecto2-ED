#ifndef INFIERNO_H
#define INFIERNO_H

#include "Estructuras.h"

class Infierno{
    public:
        Demonio * demonios[7];
        ListaPersonas * humanosMundo;
        Infierno(int,ListaPersonas *);
        QString archivoCondenacion;
        QString archivoConsulta;
        void imprimirFamiliasDeminios();

        void MeterFamiliaALosHeap();
        void escribirArchivo(Persona*,Demonio*);
        void Condenar(Demonio* );
        void consulta();

        Demonio * buscarDemonio(QString);
        void OrdenarHeapsDemonios();
};

#endif // INFIERNO_H
