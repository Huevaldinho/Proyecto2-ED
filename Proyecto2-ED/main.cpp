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


     mundo->GenerarNpersonas(2000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
     //mundo->listaPersonas->imprimir();
     //Hay un error despues de 2000, el arbol baja y llega a ser null, no se cae porque le hice la validacion
     //pero no deberia pasar eso, es porque el arbol se genera mal despues de 2000

    //FALTA HACER logica para ver quien es papa de quien y si puedo insertarle hijos y toda esa vara

    //PRUEBA ARBOL FAMILIA funciona ak7
//    Persona * tmp = NULL;
//    int n=100;
//    for (int i=0;i<n;i++){
//        tmp = mundo->generarPersona();
//        mundo->listaFamilias->insertarFamilia(new Nodo(tmp));
//    }
    //mundo->listaFamilias->verMiembrosFamilia();
    mundo->listaPersonas->imprimirConHijos();
    //Falta revisar que hacer cuando no hay cantiad suficiente para los hijos
    //me parece que una solucion es que la funcion que asigna los hijos retorne el contador que recibe,
    //ese contador cada vez que se inserta un hijo se disminuye y solo seria retornar
    //no se si es necesario el contador de hijos, solo lo agregue para tener una referencia de cuantos,
    //hijos esperaba pero seria mas facil agregarle solo los que pueda y ya, sin tener que llevar un contador





    qDebug()<<"TERMINA EL PROGRAMA - MAIN";
    return a.exec();
}
