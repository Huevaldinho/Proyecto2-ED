#include "demonio.h"

Demonio::Demonio(){
    this->pecadosAcumulados=0;
    this->personasTotales=0;
    this->size=0;
    this->cantidadFamilias=0;
    this->baAcumuladas=0;
}
Demonio::Demonio(QString _nombre){
    this->nombre=_nombre;
    this->personasTotales=0;
    this->pecadosAcumulados=0;
    this->baAcumuladas=0;
}
Demonio::Demonio(QString nombreDemonio,int _cantidaFamilias){
    this->nombre=nombreDemonio;
    this->cantidadFamilias=_cantidaFamilias;
    this->heapFamilias.resize(this->cantidadFamilias);
    this->size=0;
    this->personasTotales=0;
    this->pecadosAcumulados=0;
    this->baAcumuladas=0;
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
//        uniform_int_distribution<int> distribution (0,100); //random
//        int k=0;
//        while (k<this->cantidadFamilias){
//            if (this->heapFamilias[k]->apellido!=""){
//                this->heapFamilias[k]->contadorPecadosFamilia=distribution(*QRandomGenerator::global());;
//                //this->heapFamilias[k]->contadorPecadosFamilia=100-k;
//                k++;
//            }else
//                break;
//        }
        //Estas lineas de arriba son solo para probar, estos datos son los uqe se toman en la
        //condenacion
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
}
QString Demonio::nombrePecado(){
    switch (this->posicionPecadoEnArreglo){
        case 0: return "lujuria";
        case 1: return "gula";
        case 2: return "avaricia";
        case 3: return "pereza";
        case 4: return "ira";
        case 5: return "envidia";
        case 6: return "soberbia";
    }
    return "";
}
QString Demonio::nombreAntagonico(){
    switch (this->posicionPecadoEnArreglo){
        case 0: return "castidad";
        case 1: return "ayuno";
        case 2: return "donación";
        case 3: return "diligencia";
        case 4: return "calma";
        case 5: return "solidaridad";
        case 6: return "humildad";
    }
    return "";
}
int Demonio::maxPecado(){
    int max = 0;
    for (int i = 0 ; i < this->cantidadFamilias ; i++){
        Nodo * tmp = this->heapFamilias[i]->listaPersonas->primerNodo;
        while (tmp!=NULL){
            if (tmp->persona->pecados[this->posicionPecadoEnArreglo]>max)
                max = tmp->persona->pecados[this->posicionPecadoEnArreglo];
            tmp=tmp->siguiente;
        }
    }
    return max;
}
int Demonio::minPecado(){
    int min = 1000;
    for (int i = 0 ; i < this->cantidadFamilias ; i++){
        Nodo * tmp = this->heapFamilias[i]->listaPersonas->primerNodo;
        while (tmp!=NULL){
            if (tmp->persona->pecados[this->posicionPecadoEnArreglo]<min)
                min = tmp->persona->pecados[this->posicionPecadoEnArreglo];
            tmp=tmp->siguiente;
        }
    }
    if (min == 1000)
        min = 0;
    return min;
}
QString Demonio::detallePecadores(){
    QString s = "";
    for (int i = 0 ; i < this->cantidadFamilias ; i++){
        Nodo * tmp = this->heapFamilias[i]->listaPersonas->primerNodo;
        while (tmp!=NULL){
            s+="\t"+tmp->persona->nombre+" "+tmp->persona->apellido+", cantidad de pecados de "+this->nombrePecado()+": "+QString::number(tmp->persona->pecados[this->posicionPecadoEnArreglo])+"\n";
            tmp=tmp->siguiente;
        }
    }
    return s;
}
