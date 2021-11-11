#include "demonio.h"

Demonio::Demonio(){
}
Demonio::Demonio(QString _nombre){
    this->nombre=_nombre;
}
Demonio::Demonio(QString nombreDemonio,int _cantidaFamilias){
    this->nombre=nombreDemonio;
    this->cantidadFamilias=_cantidaFamilias;
    this->heapFamilias.resize(this->cantidadFamilias);
    for (int i=0;i<_cantidaFamilias;i++){
        this->heapFamilias[i] = new FamiliaHeapDemonio();
    }
}
void Demonio::InsertarEnHeap(QString apellidoFamilia,QString paisFamilia){//Inserta a todas las familias
    //Primero busca si ya esta registrada esa familia
    int familiaBuscada = BuscarFamilia(apellidoFamilia,paisFamilia);
    int i=0;
    if (familiaBuscada==-1){//No esta asi que la registra en el heap
        while(i<this->cantidadFamilias){
            if (this->heapFamilias[i]->apellido==""){
                this->heapFamilias[i]->apellido=apellidoFamilia;
                this->heapFamilias[i]->pais=paisFamilia;
                break;
            }
            i++;
        }
    }
}
int Demonio::BuscarFamilia(QString apeBuscado,QString paisBuscado){
    int i =0;
    while (i<this->cantidadFamilias){
        if ((this->heapFamilias[i]->apellido)==apeBuscado && (this->heapFamilias[i]->pais)==paisBuscado)
            return i;
        i++;
    }
    return -1;
}
void Demonio::imprimirFamilia(){
    qDebug()<<"Nombre demonio: "<<this->nombre;
    int i =0;
    while(i<cantidadFamilias){
        qDebug()<<"Apellido: "<<this->heapFamilias[i]->apellido<<" - Pais: "<<this->heapFamilias[i]->pais;
        i++;
    }
}
void Demonio::swap (int & a, int & b){ // Función de intercambio de posición
    int temp = a;
    a = b;
    b = temp;
}
void Demonio::Heap (int array [], int length, int index){// Algoritmo de clasificación de montón (big top heap)
     int left = 2 * index + 1; // left array index
     int right = 2 * index + 2; // El índice de la matriz de nodos derecha
     int max = index; // index es el nodo padre
     if (left <length && array [left]> array [max]){ // El nodo izquierdo se compara con el nodo padre
        max = left;
    }
     if (right <length && array [right]> array [max]){ // El nodo derecho se compara con el nodo padre
        max = right;
    }
    if (array[index] != array[max]){
        swap(array[index], array[max]);
         Heap (array, length, max); // Llamada recursiva
    }
}
void Demonio::HeapSort (int array [], int size){// Función de ordenación del montón
   for (int i = size / 2-1; i>= 0; i--){// crea un montón
       Heap(array, size, i);
   }
   for (int i = size - 1; i >= 1; i--){
        swap (array [0], array [i]); // Coloque el valor máximo de array [0] en la posición de array [i], el valor máximo se inclina hacia atrás
        Heap (array, i, 0); // Llame al algoritmo de ordenación del montón para comparar
   }
}
