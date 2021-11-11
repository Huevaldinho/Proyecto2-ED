#ifndef DEMONIO_H
#define DEMONIO_H

#include "Estructuras.h"
class Demonio{
    public:
        QString nombre;
        int posicionPecadoEnArreglo;
        QVector <FamiliaHeapDemonio *> heapFamilias; // Declaracion del vector.
        int cantidadFamilias=0;//capacidad
        int size;
        Demonio();
        Demonio(QString);
        Demonio(QString,int cantidaFamilias);
        void InsertarEnHeap(QString,QString);//Inserta a todas las familias
        int BuscarFamilia(QString,QString);
        void imprimirFamilia();
        int findSmallest(QVector <FamiliaHeapDemonio *>  array,int i);


        //Ordena de menor a mayor, al final solo es de darle vuelta al array,
        //es porque no consegui el codigo para hacerlo de una vez de mayor a menor xD
        //Originales
//      void swap (int & a, int & b);
//      void Heap (int array [], int length, int index);
//      void HeapSort (int array [], int size);

        void swap (FamiliaHeapDemonio * a,  FamiliaHeapDemonio* b);
        void Heap (QVector <FamiliaHeapDemonio *>, int length, int index);
        void HeapSort (QVector <FamiliaHeapDemonio *>, int size);
        void OrdenarHeap();
};

#endif // DEMONIO_H
