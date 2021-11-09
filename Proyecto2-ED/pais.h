#ifndef PAIS_H
#define PAIS_H

#include "Estructuras.h"

class Pais{
    public:
        QString nombre;
        int cantidadPecados;
        int cantidadBuenasAcciones;
        int continente;// 1 - ASIA · 2 - AMÉRICA · 3 - ÁFRICA · 4 - ANTÁRTIDA · 5 - EUROPA · 6 - OCEANÍA.
        Pais * siguiente;
        Pais * anterior;
        Pais();
        Pais(QString _nombre,int pecados,int ba){
            this->nombre=_nombre;
            this->cantidadPecados=pecados;
            this->cantidadBuenasAcciones=ba;
            this->siguiente=NULL;
            this->anterior=NULL;
        }
        void calcularContinente();
        void imprimir(){
            qDebug()<<"<-"<<this->nombre<<"->";
        }
};
#endif // PAIS_H
