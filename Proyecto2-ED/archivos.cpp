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
    QString filename(":/txt/archivosTxt/apellidos10.txt");
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
}

void Archivos::lecturaNombres(QString * nombres){
    QString filename(":/txt/archivosTxt/nombres100.txt");
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
                nombres[contadorNombres]=tmp;
                this->contadorNombres++;
                tmp = "";
            }
        }
    }
    file.close();

}
void Archivos::lecturaPaises(QString * paises){
    QString filename(":/txt/archivosTxt/paises10.txt");
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
