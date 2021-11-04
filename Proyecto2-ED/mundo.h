#ifndef MUNDO_H
#define MUNDO_H

#include "Estructuras.h"

class Mundo{
    public:
        //Lista doble personas
        ListaPersonas * listaPersonas;//Todas las personas
        ListaFamilias * listaFamilias;//Contiene la raiz de cada arbol de familia
        ArbolMundo * arbolMundo;//Para insertar personas mas rapido
        Archivos * archivos;//Carga informacion de .txt
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
        QString GenerarCorreo(QString, QString);

        void GenerarNpersonas(int);
        void  SacarMitades(int a,int b);
        bool PuedoGenerarArbol(int n);//utiliza n%cantidadHumanosParaCrearArbol

        //yop jijijijijijiji
        Persona * generarPersona();
        void generarMundo(int);
        int cantidadNivelesArbol(int);
};


#endif // MUNDO_H
