#ifndef CIELO_H
#define CIELO_H

#include "Estructuras.h"
class Cielo{
    public:
        QVector<ArbolCielo *> hash;//array de arboles balanceados que tienen personas
        Infierno * infierno;
        QString archivoCielo;
        ArbolTriario * angeles;
        //Hacer arbol triario para la salvacion

        Cielo();
        Cielo(Infierno *);
        int funcionHash(int ID);
        void mostrarCielo();
        void salvacion();
        Angel* salvacion(Angel*);
        bool esHoja(Angel*);
        void escribirEnArchivo(Persona *);
        void hacerArreglo();
        QVector<Persona*> p;
        QVector <int> CantidadPecadosCielo();
        QVector <int> CantidadBACielo();
};

#endif // CIELO_H
