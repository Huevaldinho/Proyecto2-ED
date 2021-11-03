#include "arbolmundo.h"

ArbolMundo::ArbolMundo(){
    this->raiz=NULL;
    this->listaPersonas=NULL;
}
NodoArbol * ArbolMundo::crearNodo(Nodo * _nodoPersona,NodoArbol* padre){
    NodoArbol* nuevo_nodo = new NodoArbol();
    nuevo_nodo->nodoPersona = _nodoPersona;
    nuevo_nodo->hijoderecho = NULL;
    nuevo_nodo->hijoizquierdo = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}
void ArbolMundo::insertarNodo(NodoArbol*&arbol, Nodo * _nodoPersona,NodoArbol* _padre){
    if (arbol == NULL) { //Si el arbol está vacío
        NodoArbol *nuevo_nodo = crearNodo(_nodoPersona,_padre);
        arbol = nuevo_nodo;
    }else { // Si el arbol tiene un nodo o más
        int valorRaiz = arbol->nodoPersona->persona->ID; // Obtener valor de la raíz
        if (_nodoPersona->persona->ID < valorRaiz) {
            insertarNodo(arbol->hijoizquierdo, _nodoPersona,arbol);
        }else {
            insertarNodo(arbol->hijoderecho, _nodoPersona,arbol);
        }
    }
}
bool ArbolMundo::esHoja(NodoArbol * arbol){
    if (arbol->hijoderecho==NULL && arbol->hijoizquierdo==NULL)
        return true;
    return false;
}
void ArbolMundo::insertarAListaDesdeArbol(NodoArbol *arbol,Nodo * nodoPersona){
    if (arbol->nodoPersona->persona->ID!=nodoPersona->persona->ID){
        //persona va hacia la derecha
        if (esHoja(arbol)){
            if (nodoPersona->persona->ID<this->listaPersonas->primerNodo->persona->ID)//Si el nodo es menor que el primero lo inserta de una vez
                this->listaPersonas->insertarAlInicio(nodoPersona->persona);
            else if (nodoPersona->persona->ID>this->listaPersonas->ultimoNodo->persona->ID)
                this->listaPersonas->insertarAlFinal(nodoPersona->persona);//si el nodo es mayor que el ultimo lo inserta de una vez
            else{
                qDebug()<<"EL ELSE DE insertarAListaDesdeArbol (DESDE EL ARBOL): "<<arbol->nodoPersona->persona->ID;
                qDebug()<<"EL ELSE DE insertarAListaDesdeArbol(SIN EL ARBOL): "<<nodoPersona->persona->ID;
                this->listaPersonas->insertarDesdeArbol(arbol->nodoPersona,nodoPersona->persona);//Tiene que buscar donde
            }
        }
        else if (arbol->nodoPersona->persona->ID<nodoPersona->persona->ID)
                insertarAListaDesdeArbol(arbol->hijoderecho,nodoPersona);
        else
            insertarAListaDesdeArbol(arbol->hijoizquierdo,nodoPersona);
    }else{
        qDebug()<<"REPETIDO";
    }

}
void ArbolMundo::mostrarArbol(NodoArbol*arbol , int cont){
    //qDebug()<<"MOSTRAR ARBOL";//si entra aqui
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->hijoderecho, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout <<"    ";
        }
        std::cout << arbol->nodoPersona->persona->ID << endl;
        mostrarArbol(arbol->hijoizquierdo, cont + 1);
    }
}
bool ArbolMundo::busqueda(NodoArbol* arbol, int n){
    if (arbol == NULL) {
        return false;
    }else if (arbol->nodoPersona->persona->ID == n){
        return true;
    }else if (n <arbol->nodoPersona->persona->ID) {
        return busqueda(arbol->hijoizquierdo, n);
    }else {
        return busqueda(arbol->hijoderecho, n);
    }
}
void ArbolMundo::preOrden(NodoArbol* arbol){
    if (arbol == NULL) {
        return;
    }else {
        std::cout << arbol->nodoPersona->persona->ID << " - ";
        preOrden(arbol->hijoizquierdo);
        preOrden(arbol->hijoderecho);
    }
}
void ArbolMundo::inOrden(NodoArbol* arbol){
    if (arbol == NULL) {
        return;
    }else {
        inOrden(arbol->hijoizquierdo);
        std::cout << arbol->nodoPersona->persona->ID << " - ";
        inOrden(arbol->hijoderecho);
    }
}
void ArbolMundo::postOrden(NodoArbol* arbol){
    if (arbol == NULL) {
        return;
    }else {
        postOrden(arbol->hijoizquierdo);
        postOrden(arbol->hijoderecho);
        std::cout << arbol->nodoPersona->persona->ID << " - ";
    }
}
void ArbolMundo::eliminar(NodoArbol* arbol, int n){
    if (arbol == NULL) {
        return;
    }else if (n < arbol->nodoPersona->persona->ID) { //Si el valor es menor
        eliminar(arbol->hijoizquierdo, n); // Busca por la izquierda
    }else if (n > arbol->nodoPersona->persona->ID) { // Si el valor es mayor
        eliminar(arbol->hijoderecho, n); //Busca por la derecha
    }else {
        eliminarNodo(arbol);
    }
}
NodoArbol* ArbolMundo::minimo(NodoArbol* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->hijoizquierdo) { // Si tiene hijo izquierdo
        return minimo(arbol->hijoizquierdo); // retorna el hijo izquierdo
    }
    else { // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
        return arbol; // se retorna a sí mismo
    }
}
void ArbolMundo::eliminarNodo(NodoArbol* nodoEliminar){
    if (nodoEliminar->hijoizquierdo && nodoEliminar->hijoderecho) {
        NodoArbol* menor = minimo(nodoEliminar->hijoderecho); // Primero te vas hacia la derecha
        nodoEliminar->nodoPersona->persona->ID = menor->nodoPersona->persona->ID;
        eliminarNodo(menor);
    }else if (nodoEliminar->hijoizquierdo) {
        reemplazar(nodoEliminar, nodoEliminar->hijoizquierdo);
        destruirNodo(nodoEliminar);
    }else if (nodoEliminar->hijoderecho) {
        reemplazar(nodoEliminar, nodoEliminar->hijoderecho);
        destruirNodo(nodoEliminar);
    }else { // No tiene hijos
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}
void ArbolMundo::reemplazar(NodoArbol* arbol, NodoArbol* nuevoNodo){
    if (arbol->padre) {
        //arbol->padre hay que asignarle su nuevo hijo
        if (arbol->nodoPersona->persona->ID == arbol->padre->hijoizquierdo->nodoPersona->persona->ID) {
            arbol->padre->hijoizquierdo = nuevoNodo;
        }
        else if (arbol->nodoPersona->persona->ID == arbol->padre->hijoderecho->nodoPersona->persona->ID) {
            arbol->padre->hijoderecho = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        // Procedemos a asignarle su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}
void ArbolMundo::destruirNodo(NodoArbol* nodo){
    nodo->hijoizquierdo = NULL;
    nodo->hijoderecho = NULL;
    delete nodo;
}

int ArbolMundo::contadorNodos(NodoArbol* nodoArbol){
    if (nodoArbol == NULL)
        return 0;
     else
        //qDebug()<<"Raiz: "<<nodoArbol->nodoPersona->persona->ID;
        if (nodoArbol->hijoderecho!=NULL)
            //qDebug()<<"Hijo derecho: "<<nodoArbol->hijoderecho->nodoPersona->persona->ID;
        if (nodoArbol->hijoizquierdo!=NULL)
            //qDebug()<<"Hijo izquierdo: "<<nodoArbol->hijoizquierdo->nodoPersona->persona->ID;
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
