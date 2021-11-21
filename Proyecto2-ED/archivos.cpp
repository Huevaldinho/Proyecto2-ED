#include "archivos.h"

Archivos::Archivos(){
    this->contadorApellidos=0;
    this->contadorNombres=0;
    this->contadorPaises=0;
    this->contadorProfesiones=0;
    this->contadorCreencias=0;
}
void Archivos::lecturaApellidos(QString * apellidos){
    QString data="";
    QString filename(":/txt/archivosTxt/apellidos1000.txt");
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
    }
    else
    {
        data=file.readAll();
        QString tmp="";
        for(int i=0; i<(int)data.size(); i++){
            if(data[i] != '\n')
               tmp += data[i];
            else{
                apellidos[contadorApellidos]=tmp;
                this->contadorApellidos++;
                tmp = "";
            }
        }
    }
    file.close();
    qDebug()<<"TERMINA DE CARGAR APELLIDOS DEL .TEXT";
}
void Archivos::lecturaNombres(QString * nombres){
    QString filename(":/txt/archivosTxt/nombres1000.txt");
    QString data="";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
    }
    else
    {
        file.write("Hola grupo soy Vanesa");
        data=file.readAll();
        QString tmp="";
        for(int i=0; i<(int)data.size(); i++){
            if(data[i] != '\n')
               tmp += data[i];
            else{
                nombres[contadorNombres]=tmp;
                this->contadorNombres++;
                tmp = "";
            }
        }
    }
    file.close();
    qDebug()<<"TERMINA DE CARGAR NOMBRES DEL .TEXT";

}
void Archivos::lecturaPaises(QString * paises){
    QString filename(":/txt/archivosTxt/paises100.txt");
    QString data="";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
    }
    else
    {
        data=file.readAll();
        QString tmp="";
        for(int i=0; i<(int)data.size(); i++){
            if(data[i] != '\n')
               tmp += data[i];
            else{
                paises[contadorPaises]=tmp;
                this->contadorPaises++;
                tmp = "";
            }
        }
    }
    file.close();
    qDebug()<<"TERMINA DE CARGAR PAISES DEL .TEXT";
}
void Archivos::lecturaProfesiones(QString * profesiones){
    QString filename(":/txt/archivosTxt/profesiones50.txt");
    QString data="";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
    }
    else
    {
        data=file.readAll();
        QString tmp="";
        for(int i=0; i<(int)data.size(); i++){
            if(data[i] != '\n')
               tmp += data[i];
            else{
                profesiones[contadorProfesiones]=tmp;
                this->contadorProfesiones++;
                tmp = "";
            }
        }
    }
    file.close();
    qDebug()<<"TERMINA DE CARGAR PROFESIONES DEL .TEXT";
}
void Archivos::lecturaCreencias(QString * creencias){
    QString filename(":/txt/archivosTxt/creencias.txt");
    QString data="";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened";
    }
    else
    {
        data=file.readAll();
        QString tmp="";
        for(int i=0; i<(int)data.size(); i++){
            if(data[i] != '\n')
               tmp += data[i];
            else{
                creencias[contadorCreencias]=tmp;
                this->contadorCreencias++;
                tmp = "";
            }
        }
    }
    file.close();
    qDebug()<<"TERMINA DE CARGAR CREENCIAS DEL .TEXT";
}

//Por si acaso dejo esto aqui
//std::string line;
//std::ifstream rfile;//
//rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//nombres100.txt");
//if (rfile.is_open()) {
//    while (std::getline(rfile, line)) {
//        QString qstr = QString::fromStdString(line);//Convierte la linea en QString
//        nombres[contadorNombres]=qstr;
//        this->contadorNombres++;
//    }
//    rfile.close();
//}
