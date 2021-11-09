#ifndef CONSULTASPORACCIONES_H
#define CONSULTASPORACCIONES_H

#include "Estructuras.h"
#include <QTextBrowser>
#include <QMessageBox>
class ConsultasPorAcciones{
    public:
        /*
        Esta clase se usa para hacer la consulta de un humano (pecados y buenas acciones por familia) y
        para hacer las consultas de los paises mas pecadores, etc...
        La hice para no mezclar el mundo con la parte de consultas porque si no queda muy desordenado.
        */
        int IDBuscado;//A quien buscamos en el mundo para hacer el calculo de pecados por familia
        ListaPersonas * listaPersonas;
        ListaPaises * listaPaises;

        ConsultasPorAcciones();
        ConsultasPorAcciones(ListaPersonas *);
        void AccionesFamilia(int ID,QTextBrowser *,QTextBrowser *);//Recibe a la persona que buscamos por ID
        void AccionesHijos(Persona *,QTextBrowser *,QTextBrowser *);
        //Opcion 1: Top paises pecadores, Opcion 2: Top paises con mas buenas acciones
        void TopTenAccionesPaises(int opcion, QTextBrowser *);//Paises mas pecadores/buenas acciones
        //Opcion 2: Top paises menos pecadores, Opcion 2: Top paises con menos acciones buenas
        void TopFiveAccionesPaises(int,QTextBrowser *);//Paises menos pecadores/buenas acciones


        /*
        Top 10 de países más pecadores = los primeros 5 son los "menos buenos"
        Top 5 de países menos pecadores
        Top 10 de países con buenas acciones = los primeros 5 son los menos pecadores
        Top 5 de países “menos Buenos”
            */


};

#endif // CONSULTASPORACCIONES_H
