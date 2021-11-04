#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();

//    MainWindow w;
//    //Crea el mundo y lo pasa a la ventana
//    w.mundo=mundo;
//    w.show();


      //mundo->generarMundo(10000);
//     mundo->GenerarNpersonas(2000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
//     mundo->listaPersonas->imprimir();

    //El mundo tiene una lista de familias,
    //en la lista de familias esta un nodo que tiene la raiz de cada familia

    //HACER logica para ver quien es papa de quien y si puedo insertarle hijos y toda esa vara


    qDebug()<<"COMPILA BIEN";




    return a.exec();
}
