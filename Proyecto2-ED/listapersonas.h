#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include "Estructuras.h"

class ListaPersonas{
    public:
        //Esta estructura se puede usar para el mundo
        int largo;//Cantidad de personas en el mundo
        Nodo * primerNodo;//Primera persona
        Nodo * ultimoNodo;//Ultima persona

        ListaPersonas();
        bool estaVacia();
        //Este mae tiene que insertar en orden, es un algoritmo como el que se usa en heap
        void insertarAlInicio(Persona *);
        void insertarAlFinal(Persona *);
        void insertadoEspecialOrdenadoMenorAMayor(Persona *);
        void insertarDesdeArbol(Nodo * tmp,Persona * nueva);
        //Falta Insertar en orden
        void imprimir();
        void imprimirDesdeElFinal();
        Nodo * borrarAlInicio();
        Nodo * borrarAlFinal();
        Nodo * buscar(Persona *);
        Nodo * buscarMitad();
        void insertarEnPosicion(int);
};
#endif // LISTAPERSONAS_H
