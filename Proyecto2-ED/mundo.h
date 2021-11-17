#ifndef MUNDO_H
#define MUNDO_H

#include "Estructuras.h"

class Mundo{
    public:
        //Lista doble personas
        ListaPersonas * listaPersonas;//Todas las personas
        ListaFamilias * listaFamilias;//Contiene la raiz de cada arbol de familia
        //ArbolMundo * arbolMundo;//Para insertar personas mas rapido
        ArbolFamilia * arbolMundo;
        Archivos * archivos;//Carga informacion de .txt
        int maximoHumanos;//99999
        double porcentaje;//1%
        int cantidadHumanosParaCrearArbol;//100 o 1000, hay que ver
        int cantidadApellidos;
        int cantidadNombres;
        int cantidadPaises;
        int cantidadProfesiones;
        int cantidadCreencias;

        long long totalPecados;
        long long totalba;

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

        Persona * generarPersona();
        void GenerarNpersonas(int);
        void  SacarMitades(int a,int b);
        bool PuedoGenerarArbol(int n);//utiliza n%cantidadHumanosParaCrearArbol

        void generarPecados();
        void generarBuenasAcciones();

        //consultaPE = consulta de pecados
        Persona * consultaPEestadoFamilia(int); //devulve un arreglo con la información
        Pais * consultaPEtop10mas();
        Pais * consultaPEtop5menos();

        //consultaBA = consulta de buenas acciones
        Persona * consultaBAestadoFamilia(int); //devulve un arreglo con la información
        Pais * consultaBAtop10mas();
        Pais * consultaBAtop5menos();

        void  CrearArbolMundo(int a,int b);


};


#endif // MUNDO_H
