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
NodoArbol * ArbolFamilia::insert(NodoArbol* r, Nodo * persona){
    if (r == NULL) {
       r = new NodoArbol;
       r->nodoPersona=persona;
       r->hijoizquierdo = NULL;
       r->hijoderecho = NULL;
       return r;
    } else if (persona->persona->ID < r->hijoderecho->nodoPersona->persona->ID) {
       r->hijoizquierdo = insert(r->hijoizquierdo, persona);
       r = balance(r);
    } else if (persona->persona->ID >= r->hijoderecho->nodoPersona->persona->ID) {
       r->hijoderecho = insert(r->hijoderecho, persona);
       r = balance(r);
    } return r;
}
void ArbolFamilia::show(NodoArbol* arbol, int cont){
//    int i;
//    if (p != NULL) {
//       show(p->hijoderecho, l+ 1);
//       std::cout<<" ";
//       if (p->nodoPersona->persona->ID == this->raiz->nodoPersona->persona->ID)
//          cout << "Root -> ";
//       for (i = 0; i < l&& p->nodoPersona->persona->ID != this->raiz->nodoPersona->persona->ID; i++)
//          std::cout << " ";
//          std::cout << p->hijoderecho->nodoPersona->persona->ID;
//          show(p->hijoizquierdo, l + 1);
//    }
    //qDebug()<<"MOSTRAR ARBOL";//si entra aqui
    if (arbol == NULL) {
        return;
    }
    else {
        show(arbol->hijoderecho, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout <<"    ";
        }
        std::cout << arbol->nodoPersona->persona->ID << endl;
        show(arbol->hijoizquierdo, cont + 1);
    }
}
void ArbolFamilia::inorder(NodoArbol * t){
    if (t == NULL)
       return;
   inorder(t->hijoizquierdo);
   std::cout << t->nodoPersona->persona->ID << " ";
   inorder(t->hijoderecho);
}
void ArbolFamilia::preorder(NodoArbol * t){
    if (t == NULL)
       return;
   std::cout << t->nodoPersona->persona->ID << " ";
   preorder(t->hijoizquierdo);
   preorder(t->hijoderecho);
}
void ArbolFamilia::postorder(NodoArbol* t){
    if (t == NULL)
       return;
   postorder(t ->hijoizquierdo);
   postorder(t ->hijoderecho);
   std::cout << t->nodoPersona->persona->ID << " ";
}
