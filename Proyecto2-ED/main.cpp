#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);
    Cielo * cielo = new Cielo(infiernoMain);


//    cielo->funcionHash(0);
//    cielo->funcionHash(500);
//    cielo->funcionHash(999);
//    cielo->funcionHash(1000);
//    cielo->funcionHash(1001);
//    cielo->funcionHash(2000);
//    cielo->funcionHash(2001);
//    cielo->funcionHash(10000);
//    cielo->funcionHash(10001);
//    cielo->funcionHash(99999);


    qDebug()<<"Prueba arbol cielo: ";
    mundo->GenerarNpersonas(10000);
    Nodo * tmp = mundo->listaPersonas->primerNodo;
    int i=1;
    while (tmp!=NULL){
        i= cielo->funcionHash(tmp->persona->ID);//Se fija en cual rango tiene que insertar
        cielo->hash[i]->raiz = cielo->hash[i]->insert(cielo->hash[i]->raiz,tmp->persona);
        tmp=tmp->siguiente;
    }
    //Ver los arboles del hash
    for(int i=1;i<1001;i++){
          qDebug()<<"Rango: " <<i<<'\n';//Esta es la posicion del arreglo donde ser inserta
          //cielo->hash[i]->inorder(cielo->hash[i]->raiz);//muestra los nodos que estan en ese rango
          cielo->hash[i]->mostrarArbol(cielo->hash[i]->raiz,0);
          qDebug();
      }



    MainWindow w;
    w.mundo=mundo;
    w.infierno=infiernoMain;
    w.consultas = new ConsultasPorAcciones(mundo->listaPersonas);
    w.show();








    return a.exec();
}
