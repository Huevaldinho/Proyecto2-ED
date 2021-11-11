#include "infierno.h"

Infierno::Infierno(int cantidadFamilias, ListaPersonas * personas){
    //Crea los demonios
    this->humanosMundo = personas;
    this->demonios[0]= new Demonio("Asmodeo",cantidadFamilias);//Lujuria
    this->demonios[0]->posicionPecadoEnArreglo=0;
    this->demonios[1]= new Demonio("Belfegor",cantidadFamilias);//Gula
    this->demonios[1]->posicionPecadoEnArreglo=1;
    this->demonios[2]= new Demonio("Mammón",cantidadFamilias);//Avaricia
    this->demonios[2]->posicionPecadoEnArreglo=2;
    this->demonios[3]= new Demonio("Abadón",cantidadFamilias);//Pereza
    this->demonios[3]->posicionPecadoEnArreglo=3;
    this->demonios[4]= new Demonio("Satán",cantidadFamilias);//Ira
    this->demonios[4]->posicionPecadoEnArreglo=4;
    this->demonios[5]= new Demonio("Belcebú",cantidadFamilias);//Envidia
    this->demonios[5]->posicionPecadoEnArreglo=5;
    this->demonios[6]= new Demonio("Lucifer",cantidadFamilias);//Soberbia
    this->demonios[6]->posicionPecadoEnArreglo=6;
}
void Infierno::MeterFamiliaALosHeap(){
    Nodo * tmp = humanosMundo->primerNodo;
    int demonio=0;
    while (tmp!=NULL){
        //Mete a todas las familias en todos los demonios
        while (demonio<7){
            this->demonios[demonio]->InsertarEnHeap(tmp->persona->apellido,tmp->persona->pais);
            demonio++;
        }
        demonio=0;
        tmp=tmp->siguiente;
    }
    qDebug()<<"Termina meter familia a los heap de demonios";
}
void Infierno::imprimirFamiliasDeminios(){
    int demonio=0;
    while(demonio<7){//Avanza en todos los demonios
        this->demonios[demonio]->imprimirFamilia();
        demonio++;
    }
    qDebug()<<"Termina imprimir familia deminioos infierno";
}
