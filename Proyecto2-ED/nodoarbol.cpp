#include "nodoarbol.h"

NodoArbol::NodoArbol(){
    this->hijoderecho=NULL;
    this->hijoizquierdo=NULL;
    this->nodoPersona=NULL;
    this->padre=NULL;
}
NodoArbol::NodoArbol(Nodo * _persona){
        this->nodoPersona = _persona;
        hijoizquierdo = hijoderecho = NULL;
}
