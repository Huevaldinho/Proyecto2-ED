#include "nodoarbolhashcielo.h"

NodoArbolHashCielo::NodoArbolHashCielo(){
    this->persona=NULL;
    this->hijoderecho=NULL;
    this->hijoizquierdo=NULL;
}
NodoArbolHashCielo::NodoArbolHashCielo(Persona * _persona){
    this->persona= _persona;
    this->hijoderecho=NULL;
    this->hijoizquierdo=NULL;
}

