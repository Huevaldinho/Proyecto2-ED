#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();

    //    //Crea el mundo y lo pasa a la ventana
    MainWindow w;
    w.mundo=mundo;
    w.consultas = new ConsultasPorAcciones(mundo->listaPersonas);
    w.show();


     //mundo->GenerarNpersonas(10000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
     //mundo->listaPersonas->imprimir();

//    mundo->generarPecados();
//    mundo->generarBuenasAcciones();
//    mundo->listaPersonas->imprimirConHijos();
    //mae se hace demasiado rapido, lo que se dura es porque se va imprimiendo, pero si lo comenta se hace en un segundo que leveeeel
    //que nivel pa

    qDebug()<<"TERMINA EL PROGRAMA - MAIN";
    return a.exec();
}
