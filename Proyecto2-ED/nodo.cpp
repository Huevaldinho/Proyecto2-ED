#include "nodo.h"

Nodo::Nodo(){
    this->persona = NULL;
    this->siguiente = NULL;
    this->anterior = NULL;
}
Nodo::Nodo(Persona * _persona){
    this->persona = _persona;
    this->siguiente=NULL;
    this->anterior=NULL;
}
void Nodo::imprimir(){
    persona->imprimir();
}

