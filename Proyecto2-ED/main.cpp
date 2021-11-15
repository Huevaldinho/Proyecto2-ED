#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();
    Infierno * infiernoMain = new Infierno(mundo->cantidadApellidos*mundo->cantidadPaises,mundo->listaPersonas);
    Cielo * cielo = new Cielo(infiernoMain);

    qDebug()<<"Prueba arbol cielo: ";
    mundo->GenerarNpersonas(10000);
    Nodo * tmp = mundo->listaPersonas->primerNodo;
    int i=1;
    while (tmp!=NULL){
        i= cielo->funcionHash(tmp->persona->ID);//Se fija en cual rango tiene que insertar
        cielo->hash[i]->raiz = cielo->hash[i]->insert(cielo->hash[i]->raiz,tmp->persona);
        tmp=tmp->siguiente;
    }
//    //Ver los arboles del hash (en consola)
//    for(int i=1;i<1001;i++){
//          qDebug()<<"Rango: " <<i<<'\n';//Esta es la posicion del arreglo donde ser inserta
//          //cielo->hash[i]->inorder(cielo->hash[i]->raiz);//muestra los nodos que estan en ese rango
//          cielo->hash[i]->mostrarArbol(cielo->hash[i]->raiz,0);
//          qDebug();
//      }


    //Esta parte se llama cuando se hace la salvacion
    //QString pathCieloB;
    QString pathCieloH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Cielo/";
    QDateTime actual = QDateTime::currentDateTime();
    cielo->archivoCielo=pathCieloH+"Salvados_"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    qDebug()<<cielo->archivoCielo;
    cielo->mostrarCielo();//Hace el .txt


    MainWindow w;
    w.mundo=mundo;
    w.infierno=infiernoMain;
    w.consultas = new ConsultasPorAcciones(mundo->listaPersonas);
    w.show();

    return a.exec();
}
