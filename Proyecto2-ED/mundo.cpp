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
        double bloques=trunc(this->listaPersonas->largo/nodoAinsertarEnArbol);
        //nodoAInsertar es la cantidad de inserts que voy a hacerle al arbol

        this->listaPersonas->imprimir();
        //Nodo * tmp = this->listaPersonas->primerNodo;
        qDebug()<<"nodoAInsertarEnArbol: "<<nodoAinsertarEnArbol;//Cuantos se van a poner en el arbol
        qDebug()<<"PARA BALANCEO HAY : "<<this->listaPersonas->largo<<" personas.";
        qDebug()<<"BLOQUES: "<<bloques;//6, hay que ir restando-1 para que no se pase
        Nodo * tmpIzquierdo = this->listaPersonas->buscarMitad();
        Nodo * tmpDerecho = tmpIzquierdo;
        int contadorIzquierdo=0;
        int contadorDerecho=0;
        this->arbolMundo->insertar(tmpIzquierdo);//Pone la mitad de la lista como raiz
        qDebug()<<"MITAD: "<<this->listaPersonas->buscarMitad()->persona->ID;
        int nodosIngresados=1;
        for (int i=0;i<(nodoAinsertarEnArbol/2);i++){//Ciclo para meter los 127 nodos al arbol

            //qDebug()<<"iteracion: "<<i;

            //Empezar a insertar utilizando los bloques,
            //Empieza con hijo izquierdo (7 saltos hacia la izquierda de mitad) y luego derecho

            //Ciclo para hacer los saltos de 7 en 7

            while (contadorIzquierdo<=bloques){//Se mueve desde el centro, haciendo saltos cada vez mas grandes
                if (tmpIzquierdo->persona->ID==this->listaPersonas->primerNodo->persona->ID)
                    break;
                //qDebug()<<"tmpIzquierdo: "<<tmpIzquierdo->persona->ID;
                //qDebug()<<"tmpizquierdo=tmpIzquierdo->anterior: "<<tmpIzquierdo->anterior->persona->ID;
                tmpIzquierdo=tmpIzquierdo->anterior;//Se mueve 7 hacia la izquierda
                contadorIzquierdo++;
                //qDebug()<<"contadorIzquierdo: "<<contadorIzquierdo;
            }
            while (contadorDerecho<=bloques){
                if (tmpDerecho->persona->ID==this->listaPersonas->ultimoNodo->persona->ID)
                    break;
                //qDebug()<<"tmpDerecho: "<<tmpDerecho->persona->ID;
                //qDebug()<<"tmpDerecho=tmpDerecho->siguiente: "<<tmpDerecho->siguiente->persona->ID;
                tmpDerecho=tmpDerecho->siguiente;//se mueve 7 hacia la derecha
                contadorDerecho++;
                //qDebug()<<"contadorDerecho: "<<contadorDerecho;
            }
            if (tmpDerecho->persona->ID==this->listaPersonas->ultimoNodo->persona->ID){
                this->arbolMundo->insertar(this->listaPersonas->primerNodo);
                //qDebug()<<"Inserta primero: "<<this->listaPersonas->primerNodo->persona->ID;
                nodosIngresados++;
            }else{
                this->arbolMundo->insertar(tmpIzquierdo);
                //qDebug()<<"Inserta izquierdo: "<<tmpIzquierdo->persona->ID;
                nodosIngresados++;
            }
            if (tmpDerecho->persona->ID==this->listaPersonas->ultimoNodo->persona->ID){
                this->arbolMundo->insertar(this->listaPersonas->ultimoNodo);
                //qDebug()<<"Inserta ultimo: "<<this->listaPersonas->ultimoNodo->persona->ID;
                nodosIngresados++;
                break;
            }else{
                this->arbolMundo->insertar(tmpDerecho);
                //qDebug()<<"Inserta derecha: "<<tmpDerecho->persona->ID;
                nodosIngresados++;
            }
            contadorIzquierdo=0;
            contadorDerecho=0;
            tmpIzquierdo=this->listaPersonas->buscarMitad();
            tmpDerecho=tmpIzquierdo;
            bloques += 7;//Se va sumando los saltos, 0,7,14,21,28
            //qDebug()<<"Bloques: "<<bloques;
        }
        return true;
    }
    return false;
}
