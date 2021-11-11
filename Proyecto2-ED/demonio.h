#ifndef DEMONIO_H
#define DEMONIO_H

#include "Estructuras.h"
class Demonio{
    public:
        QString nombre;
        int posicionPecadoEnArreglo;
        QVector <FamiliaHeapDemonio *> heapFamilias; // Declaracion del vector.
        int cantidadFamilias=0;
        Demonio();
        Demonio(QString);
        Demonio(QString,int cantidaFamilias);
        void InsertarEnHeap(QString,QString);//Inserta a todas las familias
        int BuscarFamilia(QString,QString);
        void imprimirFamilia();

        //Metodos para ordenar el heap de familias, FALTA CAMBIAR LOS DATOS  DE LOS METODOS
        void swap (int & a, int & b);
        void Heap (int array [], int length, int index);
        void HeapSort (int array [], int size);
};

#endif // DEMONIO_H
