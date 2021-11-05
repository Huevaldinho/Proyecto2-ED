#ifndef LISTAFAMILIAS_H
#define LISTAFAMILIAS_H

#include "Estructuras.h"
class ListaFamilias{
    public:
        //LISTA DE TODAS LAS FAMILIAS EN EL MUNDO
        NodoListaFalimias * primerNodo;//CADA NODO TIENE UNA RAIZ A SU FAMILIA
        NodoListaFalimias * ultimoNodo;
        int largo;
        ListaFamilias();
        bool estaVacia();
        void insertarFamilia(Nodo *);//recibe un nodoPersona (tiene persona, padre, hijoDerecho y izquierdo)
        NodoListaFalimias * buscarFamilia(QString apellido, QString pais);
        void imprimir();
        void verMiembrosFamilia();


};

#endif // LISTAFAMILIAS_H
