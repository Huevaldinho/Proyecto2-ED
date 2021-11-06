#include "nodolistafalimias.h"

NodoListaFalimias::NodoListaFalimias(){
    this->familia=NULL;
    this->siguiente=NULL;
    this->anterior=NULL;
}

NodoListaFalimias::NodoListaFalimias(NodoArbol * nodoArbol){
    this->familia = new ArbolFamilia();
    this->familia->apellidoFamilia=nodoArbol->nodoPersona->persona->apellido;//Asigna el apellido al arbol
    this->familia->paisFamilia=nodoArbol->nodoPersona->persona->pais;//Asigna el pais al arbol
    this->familia->raiz = this->familia->insert(this->familia->raiz,nodoArbol->nodoPersona);//Mete al mae al arbol (seria la raiz)
    this->siguiente=NULL;
    this->anterior=NULL;
    //Como este nodo persona es la raiz, no hay personas en el arbol para agregarle hijos, asi que
    //se le resetea el contador de hijos
    nodoArbol->nodoPersona->persona->cantidadHijos=0;
}
void NodoListaFalimias::imprimir(){
    qDebug()<<"Apellido: "<<this->familia->apellidoFamilia<<" - pais: "<<this->familia->paisFamilia;
}
