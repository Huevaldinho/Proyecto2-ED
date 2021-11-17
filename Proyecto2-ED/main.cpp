#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);
    Cielo * cieloMain = new Cielo(infiernoMain);
    ConsultasPorAcciones * consultasMain = new ConsultasPorAcciones(mundo->listaPersonas,cieloMain,infiernoMain);

    /*
        REVISAR LOS PORCENTAJES Y CANTIDADES DE PECADOS
        En la parte de consultas por pais, apellido, profesion
        Las cantidades de todos los paises no dan el total de pecados del mundo
        El porcentaje tampoco

        O sea, la suma de porcentajes no da el 100% ni los pecados/ba sumados dan el total
*/


    MainWindow w;
    w.mundo=mundo;
    w.infierno=infiernoMain;
    w.cielo=cieloMain;
    w.consultas = consultasMain;
    w.show();

    return a.exec();
}
