#include "arbolcielo.h"

ArbolCielo::ArbolCielo(){
    this->raiz=NULL;
}
int ArbolCielo::height(NodoArbolHashCielo * t){
    int h = 0;
    if (t != NULL) {
       int l_height = height(t->hijoizquierdo);
       int r_height = height(t->hijoderecho);
       int max_height = max(l_height, r_height);
       h = max_height + 1;
    }
    return h;
}
int ArbolCielo::difference(NodoArbolHashCielo * t){
    int l_height = height(t->hijoizquierdo);
    int r_height = height(t->hijoderecho);
    int b_factor = l_height - r_height;
    return b_factor;
}
int ArbolCielo::cantidadNiveles(NodoArbolHashCielo * aux){
    if (aux!=NULL){
        int izq=cantidadNiveles(aux->hijoizquierdo)+1;
        int der=cantidadNiveles(aux->hijoderecho)+1;
        if (izq>der)
            return izq;
        return der;
    }
    return -1;
}
int ArbolCielo::contadorNodos(NodoArbolHashCielo * aux){
    if (aux!=NULL){
        return contadorNodos(aux->hijoizquierdo)+contadorNodos(aux->hijoderecho)+1;
    }
    return 0;
}
NodoArbolHashCielo * ArbolCielo::rr_rotat(NodoArbolHashCielo * parent){
    NodoArbolHashCielo * t;
    t = parent->hijoderecho;
    parent->hijoderecho = t->hijoizquierdo;
    t->hijoizquierdo = parent;
    //std::cout<<"Right-Right Rotation"<<std::endl;
    return t;
}
NodoArbolHashCielo * ArbolCielo::ll_rotat(NodoArbolHashCielo * parent){
    NodoArbolHashCielo * t;
    t = parent->hijoizquierdo;
    parent->hijoizquierdo = t->hijoderecho;
    t->hijoderecho= parent;
    //std::cout<<"Left-Left Rotation"<<std::endl;
    return t;
}
NodoArbolHashCielo *ArbolCielo::lr_rotat(NodoArbolHashCielo * parent){
    NodoArbolHashCielo *t;
    t = parent->hijoizquierdo;
    parent->hijoizquierdo = rr_rotat(t);
    //std::cout<<"Left-Right Rotation"<<std::endl;
    return ll_rotat(parent);
}
NodoArbolHashCielo *ArbolCielo::rl_rotat(NodoArbolHashCielo * parent){
    NodoArbolHashCielo * t;
    t = parent->hijoderecho;
    parent->hijoderecho = ll_rotat(t);
    //std::cout<<"Right-Left Rotation"<<std::endl;
    return rr_rotat(parent);
}
NodoArbolHashCielo * ArbolCielo::balance(NodoArbolHashCielo * t){
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
NodoArbolHashCielo * ArbolCielo::insert(NodoArbolHashCielo * r,  Persona * _persona){
    if (r == NULL) {
       r=new NodoArbolHashCielo();
       r->persona=_persona;
       r->hijoizquierdo = NULL;
       r->hijoderecho = NULL;
       return r;
    }else if(_persona->ID < r->persona->ID) {
       r->hijoizquierdo = insert(r->hijoizquierdo, _persona);
       r = balance(r);
    } else if (_persona->ID >= r->persona->ID) {
       r->hijoderecho = insert(r->hijoderecho, _persona);
       r = balance(r);
    } return r;
}
void ArbolCielo::show(NodoArbolHashCielo* arbol, int cont){
    if (arbol == NULL) {
        return;
    }
    else {
        show(arbol->hijoderecho, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout <<"    ";
        }
        qDebug()<<QString::number(arbol->persona->ID);
        show(arbol->hijoizquierdo, cont + 1);
    }
}
void ArbolCielo::inorder(NodoArbolHashCielo * t){
    if (t == NULL)
       return;
   inorder(t->hijoizquierdo);
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->persona->ID<<" ";
   inorder(t->hijoderecho);
}
void ArbolCielo::preorder(NodoArbolHashCielo * t){
    if (t == NULL)
       return;
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->persona->ID;
   preorder(t->hijoizquierdo);
   preorder(t->hijoderecho);
}
void ArbolCielo::postorder(NodoArbolHashCielo * t){
    if (t == NULL)
       return;
   postorder(t ->hijoizquierdo);
   postorder(t ->hijoderecho);
   //std::cout << t->nodoPersona->persona->ID << " ";
   qDebug()<<t->persona->ID;
}
bool ArbolCielo::esHoja(NodoArbolHashCielo * arbol){
    if ((arbol->hijoderecho==NULL) && (arbol->hijoizquierdo==NULL))
        return true;
    return false;
}
void ArbolCielo::mostrarArbol(NodoArbolHashCielo * arbol , int cont){
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->hijoderecho, cont + 1);
        for (int i = 0; i < cont; i++) {
            std::cout <<"    ";
        }
        std::cout << arbol->persona->ID << endl;
        mostrarArbol(arbol->hijoizquierdo, cont + 1);
    }
}
void ArbolCielo::escribirEnArchivoInorden(NodoArbolHashCielo * t,QString nombreArchivo,int i){
    if (t == NULL)
       return;
   escribirEnArchivoInorden(t->hijoizquierdo,nombreArchivo,i);
   QDateTime actual = QDateTime::currentDateTime();
   QFile file(nombreArchivo);
   if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
       QTextStream w(&file);
       /*
        La informacion que debemos grabar en el archivo es:

        fecha y hora  Humano #ID Nombre Apellido Pais Salva el fechaActual por # pecados
        vs # buenas acciones por el angel NombreAngel(#) Generacion #
        */
       //Obtiene los pecados y bn
       int cantidadPecados=t->persona->pecados[0] + t->persona->pecados[1] + t->persona->pecados[2] +
               t->persona->pecados[3] + t->persona->pecados[4] + t->persona->pecados[5] + t->persona->pecados[6];
       int cantidadBN=t->persona->buenasAcciones[0] + t->persona->buenasAcciones[1] + t->persona->buenasAcciones[2] +
               t->persona->buenasAcciones[3] + t->persona->buenasAcciones[4] + t->persona->buenasAcciones[5] + t->persona->buenasAcciones[6];

       w<< actual.toString("yyyy-MM-dd")<<" "<<actual.time().toString("hh:mm:ss")<< " Humano "<<t->persona->ID<<" "<<t->persona->nombre<<
" "<<t->persona->apellido<<" "<<t->persona->pais<<" Salva el"<<actual.toString("yyy-MM-dd")<<" por "<<
cantidadPecados<<" pecados vs "<<cantidadBN<<" buenas acciones por el angel "<<"nombreAngel"<<" # "<<
" Generacion"<<" #\n";
       file.close();
   }
   escribirEnArchivoInorden(t->hijoderecho,nombreArchivo,i);
}
void ArbolCielo::insert(Persona*p){
    this->raiz=insert(this->raiz,p);
}
QVector<int> ArbolCielo::pecadosCielo(NodoArbolHashCielo * t, QVector<int> pecados){
    if (t == NULL){
        return pecados;
    }

   pecadosCielo(t->hijoizquierdo,pecados);

    pecados[0]+=t->persona->pecados[0];
    pecados[1]+=t->persona->pecados[1];
    pecados[2]+=t->persona->pecados[2];
    pecados[3]+=t->persona->pecados[3];
    pecados[4]+=t->persona->pecados[4];
    pecados[5]+=t->persona->pecados[5];
    pecados[6]+=t->persona->pecados[6];

   pecadosCielo(t->hijoderecho,pecados);
   return pecados;
}
QVector<int> ArbolCielo::baCielo(NodoArbolHashCielo * t,QVector<int> ba){
    if (t == NULL){
        return ba;
    }

   baCielo(t->hijoizquierdo,ba);

    ba[0]+=t->persona->buenasAcciones[0];
    ba[1]+=t->persona->buenasAcciones[1];
    ba[2]+=t->persona->buenasAcciones[2];
    ba[3]+=t->persona->buenasAcciones[3];
    ba[4]+=t->persona->buenasAcciones[4];
    ba[5]+=t->persona->buenasAcciones[5];
    ba[6]+=t->persona->buenasAcciones[6];

   baCielo(t->hijoderecho,ba);
   return ba;
}
