#include "nodolistafalimias.h"

NodoListaFalimias::NodoListaFalimias(){
    this->familia=NULL;
    this->siguiente=NULL;
    this->anterior=NULL;
}

NodoListaFalimias::NodoListaFalimias(NodoArbol * nodoArbol){
    this->familia = new ArbolFamilia();//Basicamente la familia es nuestro dato de toda la vida
    this->familia->apellidoFamilia=nodoArbol->nodoPersona->persona->apellido;//Asigna el apellido al arbol
    this->familia->paisFamilia=nodoArbol->nodoPersona->persona->pais;//Asigna el pais al arbol
    this->familia->insert(this->familia->raiz,nodoArbol->nodoPersona);//Mete al mae al arbol (seria la raiz)
    this->siguiente=NULL;
    this->anterior=NULL;
}
