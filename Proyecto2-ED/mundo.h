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
        int cantidadApellidos;
        int cantidadNombres;
        int cantidadPaises;
        int cantidadProfesiones;
        int cantidadCreencias;

        //Arreglo que se llena con los .txt

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

};


#endif // MUNDO_H
