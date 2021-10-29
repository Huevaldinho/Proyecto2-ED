#include "mundo.h"

Mundo::Mundo(){
    this->maximoHumanos=99999;
    //Instancia y carga todos los archivos
    this->archivos = new Archivos();

    //Mete la info de los archivos a los arrays
    this->archivos->lecturaApellidos(this->apellidos);
    this->archivos->lecturaNombres(this->nombres);
    this->archivos->lecturaPaises(this->paises);
    this->archivos->lecturaProfesiones(this->profesiones);
    this->archivos->lecturaCreencias(this->creencias);



    this->cantidadApellidos=this->archivos->contadorApellidos;
    this->cantidadNombres=this->archivos->contadorNombres;
    this->cantidadPaises=this->archivos->contadorPaises;
    this->cantidadProfesiones=this->archivos->contadorProfesiones;
    this->cantidadCreencias=this->archivos->contadorCreencias;


    qDebug()<<"APELLIDOS:\n ";
    for (int i=0;i<this->archivos->contadorApellidos;i++){
        qDebug()<<this->apellidos[i];
    }
    qDebug()<<"\nNOMBRES: \n";
    for (int i=0;i<this->archivos->contadorNombres;i++){
        qDebug()<<this->nombres[i];
    }
    qDebug()<<"\nPAISES: \n";
    for (int i=0;i<this->archivos->contadorPaises;i++){
        qDebug()<<this->paises[i];
    }
    qDebug()<<"\nPROFESIONES: \n";
    for (int i=0;i<this->archivos->contadorProfesiones;i++){
        qDebug()<<this->profesiones[i];
    }
    qDebug()<<"\nCREENCIAS: \n";
    for (int i=0;i<this->archivos->contadorCreencias;i++){
        qDebug()<<this->creencias[i];
    }
    qDebug()<<"\nCantidad de apellidos: "<<this->cantidadApellidos;
    qDebug()<<"Cantidad de nombres: "<<this->cantidadNombres;
    qDebug()<<"Cantidad de paises: "<<this->cantidadPaises;
    qDebug()<<"Cantidad de profesiones: "<<this->cantidadProfesiones;
    qDebug()<<"Cantidad de creencias: "<<this->cantidadCreencias;
    qDebug();
    this->listaPersonas= new ListaPersonas();
}
