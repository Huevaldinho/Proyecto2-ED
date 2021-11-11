#ifndef LISTAPAISES_H
#define LISTAPAISES_H

#include "Estructuras.h"

class ListaPaises{
    public:
        Pais * primerPais;
        Pais * ultimoPais;
        int largo;
        long long int totalPecados;
        long long int totalBA;
        ListaPaises();
        void insertarAPais(QString,long long pecados,long long ba);

        Pais * buscarPorNombre(QString);
        void imprimir();
        void imprimirDesdeAtras();
        bool estaVacia();
        void OrdenarPaisesPorMasPecados();
        void OrdenarPaisesPorMasBN();
};

#endif // LISTAPAISES_H
