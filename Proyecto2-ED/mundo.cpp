#include "mundo.h"

Mundo::Mundo(){
    this->maximoHumanos=99999;
    this->porcentaje=0.1;
    this->cantidadHumanosParaCrearArbol=1000;//Cada 1000 debe crear un arbol nuevo
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
    this->listaPersonas= new ListaPersonas();
}
int Mundo::GenerarIDRandom(){
    int variable=-1;
    int limite_inferior = 0;
    int limite_superior=this->maximoHumanos;
    variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return variable;
}
//Retorna apellido random de la lista
QString Mundo::GenerarApellidoRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadApellidos-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return apellidos[variable];
}
//Retorna nombre random de la lista
QString Mundo::GenerarNombreRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadNombres-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return nombres[variable];

}
//Retorna pais random de la lista
QString Mundo::GenerarPaisRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadPaises-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return paises[variable];

}
//Retorna profesion random de la lista
QString Mundo::GenerarProfesionRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadProfesiones-1;
    int variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    return profesiones[variable];

}
//Retorna creencia random de la lista
QString Mundo::GenerarCreenciaRandom(){
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
    qDebug()<<"Personas en mundo: "<<listaPersonas->largo;
}
bool Mundo::PuedoGenerarArbol(int n){
    //Recibe una cantidad para determinar si es hora de volver a crear el arbol
    //Retorna true si n%this->cantidadHumanosParaCrearArbol==0
    if ((n%this->cantidadHumanosParaCrearArbol)==0){
        //Aqui crear el nuevo arbol
        int cantidadNodos=this->listaPersonas->largo;//Cuanta gente hay
        qDebug()<<"CantidadNodo: "<<cantidadNodos;
        int nodoAinsertarEnArbol = cantidadNodos*porcentaje;//100*0.1 = 10

        //Buscar potencia de 2 mayor a la cantidadNodos
        int i=0;//Potencia del 2 y tambien sirve para saber cuantas personas faltan para completar el balanceo
        int potenciaDos =0;
        while (potenciaDos<nodoAinsertarEnArbol){//Cuenta cuantos nodos faltan para hacer un arbol balanceado
            potenciaDos =pow(2,i);
            if (potenciaDos>=cantidadNodos)
                break;
            i++;
        }
        i--;
        nodoAinsertarEnArbol+=(pow(2,i)-nodoAinsertarEnArbol-1);//Se le suma lo que faltaba para llegar a la potencia del 2,
        //NO ESTA SIRVIENDO, deberia ser 78
        double bloques=trunc(this->listaPersonas->largo/nodoAinsertarEnArbol)*10;
        //nodoAInsertar es la cantidad de inserts que voy a hacerle al arbol
        qDebug()<<"nodoAInsertarEnArbol: "<<nodoAinsertarEnArbol;//Cuantos se van a poner en el arbol
        qDebug()<<"PARA BALANCEO HAY : "<<this->listaPersonas->largo<<" personas.";
        qDebug()<<"BLOQUES: "<<bloques;//6, hay que ir restando-1 para que no se pase
        this->listaPersonas->imprimir();
        //Nodo * tmp = this->listaPersonas->primerNodo;
        bool insertarRaiz=true;
        for (int i=0;i<nodoAinsertarEnArbol;i++){
            if (insertarRaiz){
                this->arbolMundo->insertar(this->listaPersonas->buscarMitad());//Pone la mitad de la lista como raiz
                insertarRaiz=false;
                //qDebug()<<"MITAD: "<<this->listaPersonas->buscarMitad()->persona->ID;
            }
            //Empezar a insertar utilizando los bloques,
        }
        return true;
    }
    return false;
}
