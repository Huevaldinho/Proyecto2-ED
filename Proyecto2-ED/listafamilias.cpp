#include "listafamilias.h"

ListaFamilias::ListaFamilias(){
    this->largo=0;
    this->primerNodo=NULL;
    this->ultimoNodo=NULL;
}
bool ListaFamilias::estaVacia(){
    return this->primerNodo=NULL;
}
void ListaFamilias::insertarFamilia(Nodo * nodoPersona){//recibe un nodoPersona (tiene persona, padre, hijoDerecho y izquierdo)
    //Inserta al final
   //Primero busca si existe esa familia
    NodoListaFalimias * buscado = buscarFamilia(nodoPersona->persona->apellido,nodoPersona->persona->pais);
    if (buscado!=NULL){
        //Si entra es porque si existe esa familia en la lista familias entonces
        //Aqui no se inserta en esta lista porque ya existe la familia y esta en buscado->familia
        //Manda a insertar al mae al arbol de la familia
        buscado->familia->insert(buscado->familia->raiz,nodoPersona);//NodoArbol*,  Nodo * persona
        this->largo--;//NO se agrega nodos a la lista porque ya existia
    }else{//No existe esa familia
        //Esta parte crea un arbol familia en new NoroListaFalimias
        //crea el nodo de la lista y como no existia esa familia el queda como raiz del arbol
        if (estaVacia()){//BuscadrFamilia retorno NULL pero puede ser que el primerNodo haya sido NULL
            this->primerNodo = this->ultimoNodo = new NodoListaFalimias(new NodoArbol (nodoPersona));
        }else{//BuscarFamilia retorno NULL pero porque no existe esa familia en la lista
            this->ultimoNodo->siguiente = new NodoListaFalimias(new NodoArbol(nodoPersona));
            this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
            this->ultimoNodo = this->ultimoNodo->siguiente;
        }//El mae creo un nuevo Nodo de la lista pero tambien al crear ese nodo hizo el arbol familia
        //y puso al nodoPersona como raiz
    }
    this->largo++;
}
NodoListaFalimias * ListaFamilias::buscarFamilia(QString _apellido, QString _pais){
    //Busca si ya existe esa familia
    NodoListaFalimias * tmp = this->primerNodo;
    while (tmp!=NULL){
        //Si la raiz existe
        //revisa si ese arbol tiene el mismo apellido y pais
        //tmp->familia es un arbol
        if ((tmp->familia->apellidoFamilia==_apellido )&&(tmp->familia->paisFamilia==_pais)){
            return tmp;
        }
        tmp=tmp->siguiente;
    }
    //retorna null en caso 1: primerNodo es NULL o caso 2: no existe esa familia
    return tmp;
}
