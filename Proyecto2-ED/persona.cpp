#include "persona.h"

Persona::Persona(){
    this->estado=0;
    this->cantidadHijos=0;
    this->ID = -1;           //ID unico, lo inicio en -1 para que se entienda que este no se le ha asignado ID
    //Los QString siempre se instancian como "", no hay necesidad de limpiarlos
    this->fechaNacimiento = QDate::currentDate();  //Fecha de nacimiento //Se limpia?
    this->horaNacimiento = QTime::currentTime();   //Hora de nacimiento QDate esta bien??
    this->sizeArrays=7;
    for (int i=0;i<sizeArrays;i++){//Ciclo para limpiar los arreglos
        this->pecados[i]=0;
        this->buenasAcciones[i]=0;
    }
    this->padre=NULL;
    this->hijos = new ListaPersonas();
}
//ID,Nombre,Apellido,Pais,Creencia,Profesion
Persona::Persona(int _ID,QString _nombre,QString _apellido,QString _pais,QString _creencia,QString _profesion,QString _correo){
    this->estado=0;
    this->ID = _ID;
    this->nombre=_nombre;
    this->apellido=_apellido;
    this->pais=_pais;
    this->creencia=_creencia;
    this->profesion=_profesion;
    this->correo=_correo;
    this->fechaNacimiento = QDate::currentDate();  //Fecha de nacimiento //Se limpia?
    this->horaNacimiento = QTime::currentTime();   //Hora de nacimiento QDate esta bien??
    this->sizeArrays=7;
    for (int i=0;i<sizeArrays;i++){//Ciclo para limpiar los arreglos
        this->pecados[i]=0;
        this->buenasAcciones[i]=0;
    }
    this->padre=NULL;
    this->hijos = new ListaPersonas();

}
void Persona::imprimir(){
          qDebug()<<"<-"<<this->ID<<"->";
}
