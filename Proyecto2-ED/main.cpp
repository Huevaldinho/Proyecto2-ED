#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Persona * persona = new Persona();

    persona->imprimir();
    Persona * personaConstructorSobreCargado = new Persona(100,"Felipe","Obando","Costa Rica","N/A","Estudiante","felipeobando2001@gmail.com");
    qDebug();
    personaConstructorSobreCargado->imprimir();
    return a.exec();
}
