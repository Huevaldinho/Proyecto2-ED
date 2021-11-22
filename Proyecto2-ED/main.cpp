#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);
    Cielo * cieloMain = new Cielo(infiernoMain);
    ConsultasPorAcciones * consultasMain = new ConsultasPorAcciones(mundo->listaPersonas,cieloMain,infiernoMain,mundo);

    /*
        REVISAR LOS TOP, LAS CANTIDADES SON MAYORES
        ERROR EN CONSULTASPORACCIONES, se estan sumando cuando pecados no deben y por eso
        no salen las cuentas
    */


    MainWindow w;
    w.mundo=mundo;
    w.infierno=infiernoMain;
    w.cielo=cieloMain;
    w.consultas = consultasMain;
    w.show();

    return a.exec();
}
