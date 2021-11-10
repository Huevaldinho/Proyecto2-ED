#include "listapaises.h"

ListaPaises::ListaPaises(){
    this->largo=0;
    this->totalBA=0;
    this->totalPecados=0;
    this->primerPais=NULL;
    this->ultimoPais=NULL;
}
bool ListaPaises::estaVacia(){
    return this->primerPais==NULL;
}
void ListaPaises::insertarAPais(QString _nombre,int pecados,int ba){
    Pais * buscado = buscarPorNombre(_nombre);
    if (buscado==NULL){//Pais aun no estaba en lista
        Pais * nuevo = new Pais(_nombre,pecados,ba);
        if (estaVacia())
            this->primerPais = this->ultimoPais = nuevo;
        else{
            this->ultimoPais->siguiente = nuevo;
            this->ultimoPais->siguiente->anterior = this->ultimoPais;
            this->ultimoPais = this->ultimoPais->siguiente;
        }
        this->largo++;
    }else{//El pais ya esta en lista
        buscado->cantidadPecados+=pecados;
        buscado->cantidadBuenasAcciones+=ba;
    }
    this->totalPecados+=pecados;
    this->totalBA+=ba;

}
Pais * ListaPaises::buscarPorNombre(QString _nombre){
    Pais * tmp = this->primerPais;
    while (tmp!=NULL){
        if (tmp->nombre==_nombre)
            return tmp;
        tmp=tmp->siguiente;
    }
    return tmp;//NULL
}
void ListaPaises::imprimir(){
    Pais * tmp=this->primerPais;
    while (tmp!=NULL){
        tmp->imprimir();
        tmp=tmp->siguiente;
    }
}
void ListaPaises::imprimirDesdeAtras(){
    Pais * tmp=this->ultimoPais;
    while (tmp!=NULL){
        tmp->imprimir();
        tmp=tmp->anterior;
    }
}
void ListaPaises::OrdenarPaisesPorMasPecados(){
    Pais * p=this->primerPais;
    Pais * aux=NULL;
    int bn;
    int pecados;
    QString nombre;
    while (p->siguiente!=NULL){
        aux=p->siguiente;
        while (aux!=NULL){
            if (p->cantidadPecados < aux->cantidadPecados){
                bn =  aux->cantidadBuenasAcciones;
                pecados = aux->cantidadPecados;
                nombre = aux->nombre;

                aux->nombre=p->nombre;
                aux->cantidadBuenasAcciones=p->cantidadBuenasAcciones;
                aux->cantidadPecados=p->cantidadPecados;

                p->nombre=nombre;
                p->cantidadBuenasAcciones=bn;
                p->cantidadPecados=pecados;
            }
            aux=aux->siguiente;
        }
        p=p->siguiente;
    }
    qDebug()<<"Termina de ordenar por Pecados";
}
void ListaPaises::OrdenarPaisesPorMasBN(){
    Pais * p=this->primerPais;
    Pais * aux=NULL;
    int bn;
    int pecados;
    QString nombre;
    while (p->siguiente!=NULL){
        aux=p->siguiente;
        while (aux!=NULL){
            if (p->cantidadBuenasAcciones < aux->cantidadBuenasAcciones){
                bn =  aux->cantidadBuenasAcciones;
                pecados = aux->cantidadPecados;
                nombre = aux->nombre;

                aux->nombre=p->nombre;
                aux->cantidadBuenasAcciones=p->cantidadBuenasAcciones;
                aux->cantidadPecados=p->cantidadPecados;

                p->nombre=nombre;
                p->cantidadBuenasAcciones=bn;
                p->cantidadPecados=pecados;
            }
            aux=aux->siguiente;
        }
        p=p->siguiente;
    }
    qDebug()<<"Termina de ordenar por BN";
}
