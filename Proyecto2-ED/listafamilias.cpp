#include "listafamilias.h"

ListaFamilias::ListaFamilias(){
    this->largo=0;
    this->primerNodo=NULL;
    this->ultimoNodo=NULL;
}
bool ListaFamilias::estaVacia(){
    return this->primerNodo==NULL;
}
void ListaFamilias::insertarFamilia(Nodo * nodoPersona){//recibe un nodoPersona (tiene persona, padre, hijoDerecho y izquierdo)
    //Inserta al final
   //Primero busca si existe esa familia
    NodoListaFalimias * buscado = buscarFamilia(nodoPersona->persona->apellido,nodoPersona->persona->pais);
    if (buscado!=NULL){
        //Si entra es porque si existe esa familia en la lista familias entonces
        //Aqui no se inserta en esta lista porque ya existe la familia y esta en buscado->familia
        //Manda a insertar al mae al arbol de la familia
        //qDebug()<<"Raiz de familia "<<buscado->familia->apellidoFamilia<<" es: "<<buscado->familia->raiz;
        buscado->familia->raiz = buscado->familia->insert(buscado->familia->raiz,nodoPersona);//NodoArbol*,  Nodo * persona
        //Le agrega hijos
        buscado->familia->agregarHijos(buscado->familia->raiz,nodoPersona->persona,nodoPersona->persona->cantidadHijos);
        this->largo--;//NO se agrega nodos a la lista porque ya existia
    }else{//No existe esa familia
        //Esta parte crea un arbol familia en new NoroListaFalimias
        //crea el nodo de la lista y como no existia esa familia el queda como raiz del arbol
        if (estaVacia()){//BuscadrFamilia retorno NULL pero puede ser que el primerNodo haya sido NULL
            this->primerNodo = this->ultimoNodo = new NodoListaFalimias(new NodoArbol (nodoPersona));
            //qDebug()<<"Inserta primer familia: "<<nodoPersona->persona->apellido;
        }else{//BuscarFamilia retorno NULL pero porque no existe esa familia en la lista
            this->ultimoNodo->siguiente = new NodoListaFalimias(new NodoArbol(nodoPersona));
            this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
            this->ultimoNodo = this->ultimoNodo->siguiente;
            //qDebug()<<"Crea familia nueva"<<nodoPersona->persona->apellido;
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
void ListaFamilias::imprimir(){
    NodoListaFalimias * tmp = this->primerNodo;
    int contador=0;
    while (tmp!=NULL){
        tmp->imprimir();
        contador++;
        tmp=tmp->siguiente;
    }
    qDebug()<<"TOTAL DE FAMILIAS: "<<contador;
    qDebug()<<"Termina de imprimir";
}
void ListaFamilias::verMiembrosFamilia(){
    NodoListaFalimias * tmp = this->primerNodo;
    while (tmp!=NULL){
        qDebug()<<"Apellido: "<<tmp->familia->apellidoFamilia<<" - pais: "<<tmp->familia->paisFamilia;
        //qDebug()<<"Raiz: "<<tmp->familia->raiz->nodoPersona->persona->ID;//TODOS TIENEN RAIZ
        tmp->familia->show(tmp->familia->raiz,0);//pero por que si todos tienen raiz no siempre imprime el arbol
        //creo que el show no funciona por el std::cout
//        qDebug()<<"Preorder";
//        tmp->familia->preorder(tmp->familia->raiz);
        tmp=tmp->siguiente;
    }
    qDebug()<<"Termina verMiembrosFamilia";
}
