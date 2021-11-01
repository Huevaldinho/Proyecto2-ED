#include "mundo.h"

Mundo::Mundo(){
    this->maximoHumanos=99999;
    this->arbolMundo = new ArbolMundo();
    this->archivos = new Archivos();//Instancia y carga todos los archivos

    //Mete la info de los archivos a los arrays
    this->archivos->lecturaApellidos(this->apellidos);//Recibe array de apellidos y lo rellena con los datos del .txt
    this->archivos->lecturaNombres(this->nombres);
    this->archivos->lecturaPaises(this->paises);
    this->archivos->lecturaProfesiones(this->profesiones);
    this->archivos->lecturaCreencias(this->creencias);

    //Para saber cuantos apellidos se cargaron
    this->cantidadApellidos=this->archivos->contadorApellidos;
    this->cantidadNombres=this->archivos->contadorNombres;
    this->cantidadPaises=this->archivos->contadorPaises;
    this->cantidadProfesiones=this->archivos->contadorProfesiones;
    this->cantidadCreencias=this->archivos->contadorCreencias;


//    qDebug()<<"APELLIDOS:\n ";
//    for (int i=0;i<this->archivos->contadorApellidos;i++){
//        qDebug()<<this->apellidos[i];
//    }
//    qDebug()<<"\nNOMBRES: \n";
//    for (int i=0;i<this->archivos->contadorNombres;i++){
//        qDebug()<<this->nombres[i];
//    }
//    qDebug()<<"\nPAISES: \n";
//    for (int i=0;i<this->archivos->contadorPaises;i++){
//        qDebug()<<this->paises[i];
//    }
//    qDebug()<<"\nPROFESIONES: \n";
//    for (int i=0;i<this->archivos->contadorProfesiones;i++){
//        qDebug()<<this->profesiones[i];
//    }
//    qDebug()<<"\nCREENCIAS: \n";
//    for (int i=0;i<this->archivos->contadorCreencias;i++){
//        qDebug()<<this->creencias[i];
//    }
//    qDebug()<<"\nCantidad de apellidos: "<<this->cantidadApellidos;
//    qDebug()<<"Cantidad de nombres: "<<this->cantidadNombres;
//    qDebug()<<"Cantidad de paises: "<<this->cantidadPaises;
//    qDebug()<<"Cantidad de profesiones: "<<this->cantidadProfesiones;
//    qDebug()<<"Cantidad de creencias: "<<this->cantidadCreencias;
//    qDebug();

    //Lista de personas
    this->listaPersonas= new ListaPersonas();
}
int Mundo::GenerarIDRandom(){//se se pone el srand NO SIRVE
    //srand(time(NULL));
    int variable=-1;
    int limite_inferior = 0;
    int limite_superior=this->maximoHumanos;
    variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return variable;
}
//Retorna apellido random de la lista
QString Mundo::GenerarApellidoRandom(){
    //srand(time(NULL));
    //Numero random entre n hasta m
    int limite_inferior = 0;
    int limite_superior=this->cantidadApellidos-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return apellidos[variable];
}
//Retorna nombre random de la lista
QString Mundo::GenerarNombreRandom(){
    //srand(time(NULL));
    //Numero random entre n hasta m
    int limite_inferior = 0;
    int limite_superior=this->cantidadNombres-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return nombres[variable];

}
//Retorna pais random de la lista
QString Mundo::GenerarPaisRandom(){
    //srand(time(NULL));
    //Numero random entre n hasta m
    int limite_inferior = 0;
    int limite_superior=this->cantidadPaises-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return paises[variable];

}
//Retorna profesion random de la lista
QString Mundo::GenerarProfesionRandom(){
    //srand(time(NULL));
    //Numero random entre n hasta m
    int limite_inferior = 0;
    int limite_superior=this->cantidadProfesiones-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return profesiones[variable];

}
//Retorna creencia random de la lista
QString Mundo::GenerarCreenciaRandom(){
    //srand(time(NULL));
    //Numero random entre n hasta m
    int limite_inferior = 0;
    int limite_superior=this->cantidadCreencias-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return creencias[variable];

}
void Mundo::GenerarNpersonas(int n){
    Persona * tmp = NULL;
    for (int i=0;i<n;i++){
        tmp = new Persona(GenerarIDRandom(),GenerarNombreRandom(),GenerarApellidoRandom(),GenerarPaisRandom(),GenerarCreenciaRandom(),GenerarProfesionRandom(),"felipeobando2001@gmail.com");
        listaPersonas->insertadoEspecialOrdenadoMenorAMayor(tmp);
        tmp = NULL;
    }
    qDebug()<<"CANTIDAD DE PERSONAS CREADAS: "<<listaPersonas->largo;
}
