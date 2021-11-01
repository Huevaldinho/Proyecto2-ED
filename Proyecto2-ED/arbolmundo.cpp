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
        return new NodoArbol(nodoPersona);
    }else if((raiz->nodoPersona->persona->ID) < (nodoPersona->persona->ID)){
        //toma el lado derecho
        raiz->hijoderecho=insertarRecursivo(raiz->hijoderecho,nodoPersona);
    }else if((raiz->nodoPersona->persona->ID) >= (nodoPersona->persona->ID)){
        //toma lado izquierdo
        raiz->hijoizquierdo=insertarRecursivo(raiz->hijoizquierdo,nodoPersona);
    }
    return raiz;
}
void imprimirArbol(NodoArbol * raiz,int contador){
    if (raiz==NULL)
        return;
    else{
        imprimirArbol(raiz->hijoizquierdo,contador+1);
        for (int i=0;i<contador;i++){
            qDebug()<<"  ";
        }
        qDebug()<<raiz->nodoPersona->persona->ID;
        imprimirArbol(raiz->hijoderecho,contador+1);
    }
}
int ArbolMundo::contadorNodos(NodoArbol* nodoArbol){
    if (nodoArbol == NULL)
        return 0;
     else
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
