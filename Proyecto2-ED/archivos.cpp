#include "archivos.h"

Archivos::Archivos(){
    this->contadorApellidos=0;
    this->contadorNombres=0;
    this->contadorPaises=0;
    this->contadorProfesiones=0;
    this->contadorCreencias=0;
}
void Archivos::lecturaApellidos(QString * apellidos){
    std::string line;        //Donde se va guardando cada linea del archivo para meterla al arreglo
    std::ifstream rfile;    //Para cargar el archivo
    rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//apellidos100.txt");
    if (rfile.is_open()) {//Si lo pudo abrir hace la vara
        while (std::getline(rfile, line)) {//mientras tenga lineas para avanzar
            QString qstr = QString::fromStdString(line);//Convierte la linea en QString
            apellidos[contadorApellidos]=qstr;
            this->contadorApellidos++;
        }
        rfile.close();
    }
}
void Archivos::lecturaNombres(QString * nombres){
    std::string line;
    std::ifstream rfile;//
    rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//nombres100.txt");
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            QString qstr = QString::fromStdString(line);//Convierte la linea en QString
            nombres[contadorNombres]=qstr;
            this->contadorNombres++;
        }
        rfile.close();
    }
}
void Archivos::lecturaPaises(QString * paises){
    std::string line;
    std::ifstream rfile;//
    rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//paises10.txt");//100 y 10
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            QString qstr = QString::fromStdString(line);//Convierte la linea en QString
            paises[contadorPaises]=qstr;
            this->contadorPaises++;
        }
        rfile.close();
    }
}
void Archivos::lecturaProfesiones(QString * profesiones){
    std::string line;
    std::ifstream rfile;//
    rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//profesiones50.txt");
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            QString qstr = QString::fromStdString(line);//Convierte la linea en QString
            profesiones[contadorProfesiones]=qstr;
            this->contadorProfesiones++;
        }
        rfile.close();
    }
}
void Archivos::lecturaCreencias(QString * creencias){
    std::string line;
    std::ifstream rfile;
    rfile.open("D:\\OneDrive - Estudiantes ITCR\\Documentos\\GitHub\\ED\\Proyecto2-ED\\Proyecto2-ED\\archivosTexto//creencias.txt");
    if (rfile.is_open()) {
        while (std::getline(rfile, line)) {
            QString qstr = QString::fromStdString(line);//Convierte la linea en QString
            creencias[contadorCreencias]=qstr;
            this->contadorCreencias++;
        }
        rfile.close();
    }
}
