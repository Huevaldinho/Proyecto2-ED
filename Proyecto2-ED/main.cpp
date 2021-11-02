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


    mundo->GenerarNpersonas(1000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
    //mundo->listaPersonas->imprimir();//Imprime
    qDebug()<<"PuedoGenerarArbol retorna: "<<mundo->PuedoGenerarArbol(mundo->listaPersonas->largo);

    qDebug()<<"Altura?: "<<mundo->arbolMundo->altura(mundo->arbolMundo->raiz);
    qDebug()<<"ContadorNodos: "<<mundo->arbolMundo->contadorNodos(mundo->arbolMundo->raiz);
    qDebug()<<"CantidadHojas: "<<mundo->arbolMundo->cantHojas(mundo->arbolMundo->raiz);

    //El problema es la manera de insertar porque se va abriendo un pichazo
    //porque la lista esta en orden entonces siempre va a ser mayor que la raiz o meno que la raiz
    //nunca hace izquierda derecha o derecha izquierda
    mundo->arbolMundo->imprimirArbol(mundo->arbolMundo->raiz);


    //Pruebas arbol
//    ArbolMundo * arbol= new ArbolMundo();
//    arbol->listaPersonas=mundo->listaPersonas;
//    for (int i=0;i<10;i++){
//        //arbol->insertar(new Nodo(new Persona(mundo->GenerarIDRandom(),mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com")));
//        arbol->listaPersonas->insertarDesdeArbol(arbol->listaPersonas->primerNodo,new Persona(mundo->GenerarIDRandom(),mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com"));

//    }

//    arbol->listaPersonas->imprimir();
//    arbol->listaPersonas->insertarDesdeArbol(arbol->listaPersonas->ultimoNodo,new Persona(6000,mundo->GenerarNombreRandom(),mundo->GenerarApellidoRandom(),mundo->GenerarPaisRandom(),mundo->GenerarCreenciaRandom(),mundo->GenerarProfesionRandom(),"felipeobando2001@gmail.com"));
//    arbol->listaPersonas->imprimir();

//    qDebug()<<"Cantidad de nodos: "<<arbol->contadorNodos(arbol->raiz);
//    qDebug()<<"Altura: "<<arbol->altura(arbol->raiz);
//    qDebug()<<"Cantidad de hojas: "<<arbol->cantHojas(arbol->raiz);



    return a.exec();
}
