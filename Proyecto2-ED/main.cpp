#include "mainwindow.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Mundo * mundo = new Mundo();


//    MainWindow w;
//    //Crea el mundo y lo pasa a la ventana
//    w.mundo=mundo;
//    w.show();

//    mundo->GenerarNpersonas(10);//Genera personas con informacion random y las ordena de menor a mayor en la lista
//    mundo->listaPersonas->imprimir();
//    qDebug()<<"1% de "<<mundo->listaPersonas->largo<<": "<<(mundo->listaPersonas->largo*0.1);


    //Pruebas arbol
    ArbolMundo * arbol= new ArbolMundo();
    arbol->listaPersonas=mundo->listaPersonas;
    for (int i=0;i<10;i++){
        //arbol->insertar(new Nodo(new Persona(mundo->GenerarIDRandom(),mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com")));
        arbol->listaPersonas->insertarDesdeArbol(arbol->listaPersonas->primerNodo,new Persona(mundo->GenerarIDRandom(),mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com"));

    }

    arbol->listaPersonas->imprimir();
    arbol->listaPersonas->insertarDesdeArbol(arbol->listaPersonas->ultimoNodo,new Persona(6000,mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com"));
    arbol->listaPersonas->imprimir();

    qDebug()<<"Cantidad de nodos: "<<arbol->contadorNodos(arbol->raiz);
    qDebug()<<"Altura: "<<arbol->altura(arbol->raiz);
    qDebug()<<"Cantidad de hojas: "<<arbol->cantHojas(arbol->raiz);



    return a.exec();
}
