#ifndef PERSONA_H
#define PERSONA_H

#include "Estructuras.h"

class Persona{
    public:
        int estado;             //-1 Muerto, 0 Mundo y 1 Cielo
        int ID;                 //ID unico
        QString nombre;         //Nombre persona
        QString apellido;       //Apellido de familia
        QString pais;           //Pais
        QString creencia;       //Creencia religiosa
        QString profesion;      //Profesion
        QString correo;         //Correo electronico
        QDate fechaNacimiento;  //Fecha de nacimiento. QDate esta bien?
        QTime horaNacimiento;//Hora de nacimiento QDate esta bien??
        int sizeArrays;         //Para recorrer el array mas facil
        int pecados[7];         //Pecados
        int buenasAcciones[7];  //Buenas acciones
        Persona * padre;
        ListaPersonas * hijos;// o es mejor hacer dos punteros, uno de Padre y otro de Hijo?

        Persona();
        Persona(int,QString,QString,QString,QString,QString,QString);//ID,Nombre,Apellido,Pais,Creencia,Profesion
        void imprimir();
};

#endif // PERSONA_H
