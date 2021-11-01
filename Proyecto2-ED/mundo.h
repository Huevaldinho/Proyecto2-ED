#ifndef MUNDO_H
#define MUNDO_H

#include "Estructuras.h"

class Mundo{
    public:
        //Lista doble personas
        ListaPersonas * listaPersonas;
        ArbolMundo * arbolMundo;
        Archivos * archivos;
        int maximoHumanos;//99999
        double porcentaje;//1%
        int cantidadHumanosParaCrearArbol;//100 o 1000, hay que ver
        int cantidadApellidos;
        int cantidadNombres;
        int cantidadPaises;
        int cantidadProfesiones;
        int cantidadCreencias;

        //Arreglos que se llenan con los .txt
        QString apellidos[1000];
        QString nombres[1000];
        QString paises[100];
        QString creencias[10];
        QString profesiones[50];

        Mundo();
        int GenerarIDRandom();
        QString GenerarApellidoRandom();
        QString GenerarNombreRandom();
        QString GenerarPaisRandom();
        QString GenerarProfesionRandom();
        QString GenerarCreenciaRandom();
        void GenerarNpersonas(int);
        bool PuedoGenerarArbol(int n);//utiliza n%cantidadHumanosParaCrearArbol
};


#endif // MUNDO_H
