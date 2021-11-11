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
    this->size=0;
    for (int i=0;i<_cantidaFamilias;i++){
        this->heapFamilias[i] = new FamiliaHeapDemonio();
    }
}
void Demonio::InsertarEnHeap(QString apellidoFamilia,QString paisFamilia){//Inserta a todas las familias
    //Metodo para meter a todas las familias al array
    int familiaBuscada = BuscarFamilia(apellidoFamilia,paisFamilia);
    int i=0;
    if (familiaBuscada==-1){//No esta asi que la registra en el heap
        while(i<this->cantidadFamilias){
            if (this->heapFamilias[i]->apellido==""){
                this->heapFamilias[i]->apellido=apellidoFamilia;
                this->heapFamilias[i]->pais=paisFamilia;
                this->size++;
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

//Original
//void Demonio::swap (int & a, int & b){ // Función de intercambio de posición
//    int temp = a;
//    a = b;
//    b = temp;

//}
//ESTA PICHA NO ESTA ORDENANDO, ES OTRO CODIGO JAJA
void Demonio::swap (FamiliaHeapDemonio * a , FamiliaHeapDemonio * b){ // Función de intercambio de posición
    //qDebug()<<"Swap entra - a: "<<a->contadorPecadosFamilia<<" b: "<<b->contadorPecadosFamilia;
    FamiliaHeapDemonio * temp = a;
    a = b;
    b = temp;
    //qDebug()<<"Swap cambio - a: "<<a->contadorPecadosFamilia<<" b: "<<b->contadorPecadosFamilia;
    //si los intercambia

}
void Demonio::Heap(QVector <FamiliaHeapDemonio *> array, int length, int index){// Algoritmo de clasificación de montón (big top heap)
     int left = 2 * index + 1; // left array index
     int right = 2 * index + 2; // El índice de la matriz de nodos derecha
     int max = index; // index es el nodo padre
     if (left <length &&((array [left]->contadorPecadosFamilia)> (array [max]->contadorPecadosFamilia))){ // El nodo izquierdo se compara con el nodo padre
        max = left;
    }
     if (right <length && array [right]->contadorPecadosFamilia> array [max]->contadorPecadosFamilia){ // El nodo derecho se compara con el nodo padre
        max = right;
    }
    if (array[index]->contadorPecadosFamilia != array[max]->contadorPecadosFamilia){
        swap(array[index], array[max]);
        Heap (array, length, max); // Llamada recursiva
    }
}
void Demonio::HeapSort (QVector <FamiliaHeapDemonio *>  array, int size){// Función de ordenación del montón
   for (int i = size / 2-1; i>= 0; i--){// crea un montón
       Heap(array, size, i);
   }
   for (int i = size - 1; i >= 1; i--){
       //Toma el primer elemento y lo empieza a comparar con el ultimo
       qDebug()<<"Array[0]"<<array[0]->contadorPecadosFamilia<<" array["<<i<<"]"<<array[i]->contadorPecadosFamilia;
        swap (array [0], array [i]); // Coloque el valor máximo de array [0] en la posición de array [i], el valor máximo se inclina hacia atrás
        Heap (array, i, 0); // Llame al algoritmo de ordenación del montón para comparar
   }
}

int Demonio::findSmallest(QVector <FamiliaHeapDemonio *>  myarray,int i){
    int position,j;
    FamiliaHeapDemonio * ele_small;
    ele_small = myarray[i];
    position = i;
    for(j=i+1;j<5;j++){
       if(myarray[j]->contadorPecadosFamilia>ele_small->contadorPecadosFamilia){
       ele_small = myarray[j];
       position=j;
       }
    }
    return position;
}
void Demonio::OrdenarHeap(){
        /*
        Para probar que funciona le meto random a los arreglos
        */
        qDebug()<<"SUPUESTO DATO DEL TIPO DE PECADO DE: "<<this->nombre;
        uniform_int_distribution<int> distribution (0,100); //random
        int k=0;
        while (k<this->cantidadFamilias){
            if (this->heapFamilias[k]->apellido!=""){
                this->heapFamilias[k]->contadorPecadosFamilia=distribution(*QRandomGenerator::global());;
                //this->heapFamilias[k]->contadorPecadosFamilia=100-k;
                qDebug()<<"Inserta random a familia:"<<this->heapFamilias[k]->contadorPecadosFamilia;
                k++;
            }else
                break;
        }
        //Estas lineas de arriba son solo para probar, estos datos son los uqe se toman en la
        //condenacion


        //Esta es la parte que ordena, apartir de aqui es donde esta el error de orden
        qDebug()<<"Size:"<<this->size;
        for(int k=1; k<this->size; k++){
              //int temp = this->heapFamilias[k];
              FamiliaHeapDemonio * temp = this->heapFamilias[k];
              int j= k-1;
              while(j>=0 && temp->contadorPecadosFamilia >= this->heapFamilias[j]->contadorPecadosFamilia){
                 this->heapFamilias[j+1] = this->heapFamilias[j];
                 j = j-1;
              }
           this->heapFamilias[j+1] = temp;
        }
        qDebug()<<"Lista ordenada por pecado: ";
        for (int k=0;k<this->size;k++)
            qDebug()<<this->heapFamilias[k]->contadorPecadosFamilia;
}
