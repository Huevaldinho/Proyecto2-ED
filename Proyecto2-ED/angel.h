#ifndef ANGEL_H
#define ANGEL_H

#include "Estructuras.h"

struct Angel{//nodo del arbol triario
    int id; //version
    QString nombre;
    int generacion;
    Persona * persona;
    Angel *left,*right,*mid;

    Angel(int c,int g,QString n){
        id=c;
        generacion = g;
        nombre = n;
        left=right=mid=NULL;
    }
};
#endif // ANGEL_H
