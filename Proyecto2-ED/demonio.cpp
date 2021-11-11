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
void Demonio::OrdenarHeap(){
        /*
        Para probar que funciona le meto random a los arreglos
        */
        //qDebug()<<"SUPUESTO DATO DEL TIPO DE PECADO DE: "<<this->nombre;
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
        qDebug()<<"Size:"<<this->size;
        //Esta es la parte que ordena
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
