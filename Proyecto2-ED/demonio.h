#ifndef DEMONIO_H
#define DEMONIO_H

#include "Estructuras.h"
class Demonio{
    public:
        QString nombre;
        int posicionPecadoEnArreglo;
        QVector <FamiliaHeapDemonio *> heapFamilias; // Declaracion del vector. //heap
        int cantidadFamilias=0;//capacidad
        int pecadosAcumulados;
        int personasTotales;
        int size;

        Demonio();
        Demonio(QString);
        Demonio(QString,int cantidaFamilias);
        void InsertarEnHeap(QString,QString);//Inserta a todas las familias
        int BuscarFamilia(QString,QString);
        QString nombrePecado();
        QString nombreAntagonico();
        int maxPecado();
        int minPecado();
        QString detallePecadores();
        void imprimirFamilia();
        void OrdenarHeap();
};

#endif // DEMONIO_H
