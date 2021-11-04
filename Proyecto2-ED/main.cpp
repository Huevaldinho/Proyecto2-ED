#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    mundo->arbolMundo->listaPersonas=mundo->listaPersonas;

//    MainWindow w;
//    //Crea el mundo y lo pasa a la ventana
//    w.mundo=mundo;
//    w.show();


      //mundo->generarMundo(10000);

    //EL ERROR ESTA EN LA LISTA CENTRALES, ELLA CUANDO INSERTA LOS NODOS QUE VAN PARA LA LISTA
    //CAMBIA LOS PUNTEROS ORIGINALES
     mundo->GenerarNpersonas(2000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
     mundo->listaPersonas->imprimir();


    return a.exec();
}
