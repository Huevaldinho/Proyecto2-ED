#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);

    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";
    QString pathInfiernoCondenacionH="";
    QString pathInfiernoConsultaH="";

    QDateTime actual = QDateTime::currentDateTime();
    infiernoMain->archivoCondenacion=pathInfiernoCondenacionB+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    infiernoMain->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    mundo->GenerarNpersonas(1000);
    mundo->generarPecados();
    mundo->generarBuenasAcciones();

    infiernoMain->MeterFamiliaALosHeap();
    infiernoMain->OrdenarHeapsDemonios();

    infiernoMain->Condenar(infiernoMain->buscarDemonio("Abadón"));
    infiernoMain->consulta();


//    MainWindow w;
//    w.mundo=mundo;
//    w.infierno=infiernoMain;
//    w.consultas = new ConsultasPorAcciones(mundo->listaPersonas);
//    w.show();





    return a.exec();
}
