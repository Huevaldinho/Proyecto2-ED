#ifndef LISTAPAISES_H
#define LISTAPAISES_H

#include "Estructuras.h"

class ListaPaises{
    public:
        Pais * primerPais;
        Pais * ultimoPais;
        int largo;
        double totalPecados;
        double totalBA;
        ListaPaises();
        void insertarAPais(QString,int pecados,int ba);

        Pais * buscarPorNombre(QString);
        void imprimir();
        void imprimirDesdeAtras();
        bool estaVacia();
        void OrdenarPaisesPorMasPecados();
        void OrdenarPaisesPorMasBN();
};

#endif // LISTAPAISES_H
