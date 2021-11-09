#include "arbolfamilia.h"

ArbolFamilia::ArbolFamilia(){
    this->raiz=NULL;
}
int ArbolFamilia::height(NodoArbol * t){
    int h = 0;
    if (t != NULL) {
       int l_height = height(t->hijoizquierdo);
       int r_height = height(t->hijoderecho);
       int max_height = max(l_height, r_height);
       h = max_height + 1;
    }
    return h;
}
int ArbolFamilia::difference(NodoArbol * t){
    int l_height = height(t->hijoizquierdo);
    int r_height = height(t->hijoderecho);
    int b_factor = l_height - r_height;
    return b_factor;
}
NodoArbol *ArbolFamilia::rr_rotat(NodoArbol * parent){
    NodoArbol *t;
    t = parent->hijoderecho;
    parent->hijoderecho = t->hijoizquierdo;
    t->hijoizquierdo = parent;
    //std::cout<<"Right-Right Rotation"<<std::endl;
    return t;
}
NodoArbol *ArbolFamilia::ll_rotat(NodoArbol * parent){
    NodoArbol *t;
    t = parent->hijoizquierdo;
    parent->hijoizquierdo = t->hijoderecho;
    t->hijoderecho= parent;
    //std::cout<<"Left-Left Rotation"<<std::endl;
    return t;
}
NodoArbol *ArbolFamilia::lr_rotat(NodoArbol * parent){
    NodoArbol *t;
    t = parent->hijoizquierdo;
    parent->hijoizquierdo = rr_rotat(t);
    //std::cout<<"Left-Right Rotation"<<std::endl;
    return ll_rotat(parent);
}
NodoArbol *ArbolFamilia::rl_rotat(NodoArbol * parent){
    NodoArbol * t;
    t = parent->hijoderecho;
    parent->hijoderecho = ll_rotat(t);
    //std::cout<<"Right-Left Rotation"<<std::endl;
    return rr_rotat(parent);
}
NodoArbol * ArbolFamilia::balance(NodoArbol * t){
    int bal_factor = difference(t);
    if (bal_factor > 1) {
       if (difference(t->hijoizquierdo) > 0)
          t = ll_rotat(t);
       else
          t = lr_rotat(t);
    } else if (bal_factor < -1) {
       if (difference(t->hijoderecho) > 0)
          t = rl_rotat(t);
       else
          t = rr_rotat(t);
    }
    return t;
}
NodoArbol * ArbolFamilia::insert(NodoArbol * r, Nodo * persona){
    if (r == NULL) {
       r = new NodoArbol;
       r->nodoPersona=persona;
       r->hijoizquierdo = NULL;
       r->hijoderecho = NULL;
       //qDebug()<<"ArbolFamilia insert: "<<r->nodoPersona->persona->apellido<<" arbol familia: "<<this->apellidoFamilia;
       return r;
    }else if(persona->persona->ID < r->nodoPersona->persona->ID) {
       r->hijoizquierdo = insert(r->hijoizquierdo, persona);
       r = balance(r);
    } else if (persona->persona->ID >= r->nodoPersona->persona->ID) {
       r->hijoderecho = insert(r->hijoderecho, persona);
       r = balance(r);
    } return r;
}
void ArbolFamilia::show(NodoArbol* arbol, int cont){
    if (arbol == NULL) {
        return;
    }
    else {
        show(arbol->hijoderecho, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout <<"    ";
        }

        std::cout<< arbol->nodoPersona->persona->nombre.toStdString()<<std::endl;
        show(arbol->hijoizquierdo, cont + 1);
    }
}
void ArbolFamilia::agregarHijos(NodoArbol * raiz,Persona * padre,int hijosDeseados){
    //recorre todo el arbol buscando personas sin padre para agregarlos a una lista de hijos
    if (raiz == NULL)
       return;
    if (hijosDeseados==0)
        return;
   if (raiz->nodoPersona->persona->ID!=padre->ID){//No puede agregarse a si mismo como hijo
        if (raiz->nodoPersona->persona->padre==NULL){//Esta disponible para ser hijo
            padre->hijos->insertarAlFinal(raiz->nodoPersona->persona);//Pone al hijo en la lista del papa
            raiz->nodoPersona->persona->padre=padre;//Le pone el papa al hijo
            hijosDeseados--;
            padre->cantidadHijos=padre->hijos->largo;//Actualiza la cantidad de hijos del mae
            //qDebug()<<"AGREGA UN HIJO";
        }
   }
   agregarHijos(raiz->hijoizquierdo,padre,hijosDeseados);
   agregarHijos(raiz->hijoderecho,padre,hijosDeseados);

   //return hijos y este se le asigna a persona->cantidadHijos

}
void ArbolFamilia::inorder(NodoArbol * t){
    if (t == NULL)
       return;
   inorder(t->hijoizquierdo);
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->nodoPersona->persona->ID<<" ";
   inorder(t->hijoderecho);
}
void ArbolFamilia::preorder(NodoArbol * t){
    if (t == NULL)
       return;
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->nodoPersona->persona->ID;
   preorder(t->hijoizquierdo);
   preorder(t->hijoderecho);
}
void ArbolFamilia::postorder(NodoArbol* t){
    if (t == NULL)
       return;
   postorder(t ->hijoizquierdo);
   postorder(t ->hijoderecho);
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->nodoPersona->persona->ID ;
}
bool ArbolFamilia::esHoja(NodoArbol * arbol){
    if ((arbol->hijoderecho==NULL) && (arbol->hijoizquierdo==NULL))
        return true;
    return false;
}
void ArbolFamilia::insertarAListaDesdeArbol(NodoArbol *arbol,Nodo * nodoPersona){
    //Podria hacerse antes
    if (nodoPersona->persona->ID > this->listaPersonas->ultimoNodo->persona->ID){
        //Es mayor que el ultimo nodo
        this->listaPersonas->insertarAlFinal(nodoPersona->persona);
        return ;
    }if(nodoPersona->persona->ID < this->listaPersonas->primerNodo->persona->ID){
        //Es menor que el primer nodo
        this->listaPersonas->insertarAlInicio(nodoPersona->persona);
        return ;
    }
    while (!esHoja(arbol)){//Mientras no sea hoja baja
        if (arbol->nodoPersona->persona->ID==nodoPersona->persona->ID){
            return;//se sale de la funcion
        }else if(arbol->nodoPersona->persona->ID < nodoPersona->persona->ID){
            if(arbol->hijoderecho==NULL){
                //qDebug()<<"El arbol se hizo null y para que no se caiga se sale del ciclo";
                break;
            }
            arbol=arbol->hijoderecho;//baja hacia la derecha
        }else if (arbol->nodoPersona->persona->ID > nodoPersona->persona->ID){
            if(arbol->hijoizquierdo==NULL){
                //qDebug()<<"El arbol se hizo null y para que no se caiga se sale del ciclo";
                break;
            }
            arbol=arbol->hijoizquierdo;//baja hacia la izquierda
        }

    }
     //Usa hojas
    if (nodoPersona->persona->ID > arbol->nodoPersona->persona->ID){//usa las hojas para buscar donde insertar
        //Es mayor que la hoja
        this->listaPersonas->insertarMayor(arbol->nodoPersona,nodoPersona->persona);
    }else{
        //Es menor que la hoja
        this->listaPersonas->insertarMenor(arbol->nodoPersona,nodoPersona->persona);
    }
}
void ArbolFamilia::mostrarArbol(NodoArbol*arbol , int cont){
    //qDebug()<<"MOSTRAR ARBOL";//si entra aqui
    if (arbol == NULL) {
        //qDebug()<<"Raiz null";
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

