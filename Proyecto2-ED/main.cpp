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
     mundo->GenerarNpersonas(10000);//Genera personas con informacion random y las ordena de menor a mayor en la lista
     //mundo->GenerarNpersonas(2000);
     mundo->listaPersonas->imprimir();
     //Hay un error despues de 2000, el arbol baja y llega a ser null, no se cae porque le hice la validacion
     //pero no deberia pasar eso, es porque el arbol se genera mal despues de 2000

    //El mundo tiene una lista de familias,
    //en la lista de familias esta un nodo que tiene la raiz de cada familia

    //HACER logica para ver quien es papa de quien y si puedo insertarle hijos y toda esa vara

    //PRUEBA ARBOL FAMILIA
//    Persona * tmp = NULL;
//    int n=100;
//    for (int i=0;i<n;i++){
//        tmp = mundo->generarPersona();
//        mundo->listaFamilias->insertarFamilia(new Nodo(tmp));
//    }
//    mundo->listaFamilias->verMiembrosFamilia();
    //mundo->listaFamilias->imprimir();




    return a.exec();
}
