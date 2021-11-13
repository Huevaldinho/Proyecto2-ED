#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);

    MainWindow w;
    w.mundo=mundo;
    w.infierno=infiernoMain;
    w.consultas = new ConsultasPorAcciones(mundo->listaPersonas);
    w.show();





    return a.exec();
}
