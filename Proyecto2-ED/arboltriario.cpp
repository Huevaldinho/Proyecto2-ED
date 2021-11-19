#include "arboltriario.h"

ArbolTriario::ArbolTriario()//se crea ya con los 4 primeros [Dios,serafines,querubines,tronos]
{
    root=new Angel(1,1,"Dios"); //dios
    root->left=new Angel(2,2,"Serafines"); //serafines
    root->mid=new Angel(3,2,"Querubines"); //querubines
    root->right=new Angel(4,2,"Tronos"); //tronos
    genActual = 2;
    cntNodos = 4;
}
void ArbolTriario::crearNivel(){
    genActual++;
    root = crearNivel(root);
}

Angel* ArbolTriario::crearNivel(Angel*nodo){
    if (nodo==NULL){
        uniform_int_distribution<int> distribution (0,9); //random
        cntNodos++;
        return new Angel (cntNodos,genActual,nombresAngeles[distribution(*QRandomGenerator::global())]);
    }else{
        nodo->left=crearNivel(nodo->left);
        nodo->mid=crearNivel(nodo->mid);
        nodo->right=crearNivel(nodo->right);
    }
    return nodo;
}
void ArbolTriario::print(){
    print(root);
}
void ArbolTriario::print(Angel*nodo){
    if (nodo!=NULL){
        print(nodo->left);
        print(nodo->mid);
        print(nodo->right);
        cout << "ID: "<<nodo->id<<" Gen: "<<nodo->generacion<<endl;
    }
}
