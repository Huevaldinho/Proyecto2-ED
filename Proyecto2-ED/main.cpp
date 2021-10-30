#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //Sirve ak7
    //Persona * persona1 = new Persona(100,"Felipe","Obando","Costa Rica","N/A","Estudiante","felipeobando2001@gmail.com");
    //Persona * persona2 = new Persona(50,"Carlos","Castro","Paraguay","N/A","Plomero","felipeobando2001@gmail.com");

    Mundo * mundo= new Mundo();
    //mundo->listaPersonas->insertarAlInicio(persona1);
    //mundo->listaPersonas->insertarAlInicio(persona2);
    for (int i=0;i<100;i++)
        mundo->listaPersonas->insertadoEspecialOrdenadoMenorAMayor(new Persona(mundo->GenerarIDRandom(),mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com"));

    mundo->listaPersonas->imprimir();

    return a.exec();
}
