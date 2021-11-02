#include "arbolmundo.h"

ArbolMundo::ArbolMundo(){
    this->raiz=NULL;
    this->listaPersonas=NULL;
}
void ArbolMundo::insertar(Nodo * persona){
        // Para que se empiece a crear un arbol balanceado deberiamos
    //buscar la persona de la mitad de la lista (se crea un arbol cada 100, se busca al 50, 100,150,200...)
     this->raiz = insertarRecursivo(this->raiz , persona);
}
NodoArbol * ArbolMundo::insertarRecursivo(NodoArbol * raiz, Nodo * nodoPersona){
    //Esta funcion es para crear el primer arbol
    if (raiz==NULL){
        //qDebug()<<"Inserta"<<nodoPersona->persona->ID;
        return new NodoArbol(nodoPersona);
    }else if((raiz->nodoPersona->persona->ID) < (nodoPersona->persona->ID)){
        //qDebug()<<"raiz arbol: "<<raiz->nodoPersona->persona->ID<<" persona: "<<nodoPersona->persona->ID<<" derecha";
        //toma el lado derecho
        raiz->hijoderecho=insertarRecursivo(raiz->hijoderecho,nodoPersona);
    }else if((raiz->nodoPersona->persona->ID) >= (nodoPersona->persona->ID)){
        //qDebug()<<"raiz arbol: "<<" persona: "<<nodoPersona->persona->ID<<" izquierda";
        //toma lado izquierdo
        raiz->hijoizquierdo=insertarRecursivo(raiz->hijoizquierdo,nodoPersona);
    }
    return raiz;
}
void ArbolMundo::imprimirArbol(NodoArbol * raiz){
       if (raiz != NULL){
         imprimirArbol(raiz->hijoizquierdo);
         qDebug()<< raiz->nodoPersona->persona->ID;
         imprimirArbol(raiz->hijoderecho);
       }
}

int ArbolMundo::contadorNodos(NodoArbol* nodoArbol){
    if (nodoArbol == NULL)
        return 0;
     else
        qDebug()<<"Raiz: "<<nodoArbol->nodoPersona->persona->ID;
        if (nodoArbol->hijoderecho!=NULL)
            qDebug()<<"Hijo derecho: "<<nodoArbol->hijoderecho->nodoPersona->persona->ID;
        if (nodoArbol->hijoizquierdo!=NULL)
            qDebug()<<"Hijo izquierdo: "<<nodoArbol->hijoizquierdo->nodoPersona->persona->ID;
        return 1+ contadorNodos(nodoArbol->hijoderecho)+contadorNodos(nodoArbol->hijoizquierdo);
}
int ArbolMundo::maximo (int a, int b){
    if (a>b)
       return a;
       else return b;
}
int ArbolMundo::altura(NodoArbol* nodo){
    if (nodo == NULL)
            return -1;
    else
         return 1 + maximo(altura(nodo->hijoizquierdo),altura(nodo->hijoderecho));
}
int ArbolMundo::cantHojas(NodoArbol* raiz){
    if (raiz == NULL)
       return 0;
    else if (raiz->hijoderecho == NULL && raiz->hijoizquierdo==NULL)
         return 1;
    else
        return cantHojas(raiz->hijoderecho)+cantHojas(raiz->hijoizquierdo);
}
