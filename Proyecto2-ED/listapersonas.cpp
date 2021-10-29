#include "listapersonas.h"

ListaPersonas::ListaPersonas(){
    this->primerNodo=NULL;
    this->ultimoNodo=NULL;
}

bool ListaPersonas::estaVacia(){
    return this->primerNodo == NULL;
}
void ListaPersonas::insertarAlInicio(Persona * _persona){
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(_persona);
    else{
        this->primerNodo->anterior = new Nodo(_persona);
        this->primerNodo->anterior->siguiente = this->primerNodo;
        this->primerNodo = this->primerNodo->anterior;
    }
    qDebug()<<"Se inserto persona con ID: "<<this->primerNodo->persona->ID;
    this->largo++;
}
void ListaPersonas::insertarAlFinal(Persona * _persona){
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(_persona);
    else{
        this->ultimoNodo->siguiente = new Nodo(_persona);
        this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
        this->ultimoNodo = this->ultimoNodo->siguiente;
    }
    largo++;
}
void ListaPersonas::imprimir(){
    Nodo * tmp = this->primerNodo;
    while (tmp != NULL){
        tmp->imprimir();
        tmp = tmp->siguiente;
    }
    qDebug();
}
void ListaPersonas::imprimirDesdeElFinal(){
    Nodo * tmp = this->ultimoNodo;
    while (tmp != NULL){
        tmp->imprimir();
        tmp = tmp->anterior;
    }
    qDebug();
}
Nodo * ListaPersonas::borrarAlInicio(){
    Nodo * borrado = primerNodo;
    if (!estaVacia()){
        if (this->primerNodo == this->ultimoNodo)
            this->primerNodo = this->ultimoNodo = NULL;
        else{
            this->primerNodo = primerNodo->siguiente;
            this->primerNodo->anterior = NULL;
            borrado->siguiente = NULL;
        }
        return borrado;
    }
    return borrado;
}
Nodo * ListaPersonas::borrarAlFinal(){
    Nodo * borrado = ultimoNodo;
    if (!estaVacia()){
        if (this->primerNodo == this->ultimoNodo)
            this->primerNodo = this->ultimoNodo = NULL;
        else{
            this->ultimoNodo = this->ultimoNodo->anterior;
            this->ultimoNodo->siguiente = NULL;
            borrado->anterior = NULL;
        }
        return borrado;
    }
    return borrado;
}
Nodo * ListaPersonas::buscar(Persona * _persona){
    Nodo * tmp = primerNodo;
    while (tmp != NULL){
        if (tmp->persona->ID == _persona->ID)
            return tmp;
        tmp = tmp->siguiente;
    }
    return NULL;
}
