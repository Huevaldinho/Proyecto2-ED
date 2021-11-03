#include "mundo.h"

Mundo::Mundo(){
    this->maximoHumanos=99999;
    this->porcentaje=0.01;
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
    this->listaCentros = new ListaPersonas();
    this->arbolMundo->listaPersonas=this->listaPersonas;

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
//Genera una n cantidad de personas con datos aleatorios de los arreglos
void Mundo::GenerarNpersonas(int n){
    Persona * tmp = NULL;
    for (int i=0;i<n;i++){
        tmp = new Persona(GenerarIDRandom(),GenerarNombreRandom(),GenerarApellidoRandom(),GenerarPaisRandom(),GenerarCreenciaRandom(),GenerarProfesionRandom(),"felipeobando2001@gmail.com");
        if (PuedoGenerarArbol(this->listaPersonas->largo)){
            if (this->arbolMundo->raiz!=NULL){
                this->arbolMundo->insertarAListaDesdeArbol(this->arbolMundo->raiz,new Nodo(tmp));
            }else{
                listaPersonas->insertadoEspecialOrdenadoMenorAMayor(tmp);
            }
        }else{
            if (this->arbolMundo->raiz!=NULL){
                this->arbolMundo->insertarAListaDesdeArbol(this->arbolMundo->raiz,new Nodo(tmp));
            }else{
                listaPersonas->insertadoEspecialOrdenadoMenorAMayor(tmp);
            }
        }
        tmp = NULL;
    }
    qDebug()<<"Personas en mundo: "<<listaPersonas->largo;
}
void Mundo::SacarMitades(int bloques,int ciclos){
    qDebug()<<"Sacar mitades";
    int contador=0;
    Nodo * mitad = this->listaPersonas->buscarMitad();
    //Lista centros es la uqe tiene los 15 nodos uqe se van a meter al arbol
    this->listaCentros->insertarAlFinal(mitad->persona);
    ciclos-=1;//14
    ciclos/=2;//7
    Nodo * tmpIzquierdo = mitad;
    Nodo * tmpDerecho = tmpIzquierdo;
    while (ciclos!=0){
        //Listacentros ya tiene la mitad de la lista // 8
        //Ahora es un salto hacia la derecha y hacia la izquierda para meterle sus hijos //4  - 12
        switch (ciclos) {
        case 7:{//4 12
            //Meter hijos de raiz
            while (contador<bloques){//Hace los saltos
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
            //error aqui, si estos tmps estan null es porque se esta insertando mal

                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"7: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 6:{//2 14
            while (contador<bloques+(bloques/2)){//Avanza un bloque y se devuelte o avanza medio
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"6: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 5:{//6 10
            while (contador<bloques/2){//Avanza un bloque y se devuelte o avanza medio
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"5: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 4:{//7 9
            while (contador<bloques/4){//Avanza un bloque y se devuelte o avanza medio
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"4: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 3:{//1 15
            this->listaCentros->insertarAlFinal(this->listaPersonas->primerNodo->persona);
            this->listaCentros->insertarAlFinal(this->listaPersonas->ultimoNodo->persona);
            //qDebug()<<"3: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 2:{
            while (contador<bloques+(bloques/4)){
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"2: "<<tmpIzquierdo->persona->ID;
            break;
        }
        case 1:{
            //Este es un salto mas un tercio o algo asi
            while (contador<bloques-(bloques/3)){
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
            this->listaCentros->insertarAlFinal(tmpIzquierdo->persona);
            this->listaCentros->insertarAlFinal(tmpDerecho->persona);
            //qDebug()<<"1: "<<tmpIzquierdo->persona->ID;
            break;
        }
        }
        tmpIzquierdo=mitad;
        tmpDerecho=mitad;
        contador=0;
        ciclos--;
    }
}
//Si tiene un modulo 1000 en el mundo puede generar otro arbol
bool Mundo::PuedoGenerarArbol(int n){
    //Recibe una cantidad para determinar si es hora de volver a crear el arbol
    //Retorna true si n%this->cantidadHumanosParaCrearArbol==0
    if (this->listaPersonas->primerNodo!=NULL)
        if ((n%this->cantidadHumanosParaCrearArbol)==0){
            //Aqui crear el nuevo arbol
            int cantidadNodos=this->listaPersonas->largo;//Cuanta gente hay
            //qDebug()<<"CantidadNodo: "<<cantidadNodos;
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
            double bloques=trunc(this->listaPersonas->largo/nodoAinsertarEnArbol);
            //qDebug()<<"nodoAInsertarEnArbol: "<<nodoAinsertarEnArbol;//Cuantos se van a poner en el arbol
            //qDebug()<<"BLOQUES: "<<bloques;
            SacarMitades(bloques,nodoAinsertarEnArbol);
            Nodo * tmp = this->listaCentros->primerNodo;
            while (tmp!=NULL){
                this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmp,NULL);
                tmp=tmp->siguiente;
            }
            tmp = this->listaCentros->primerNodo;
            while (tmp!=NULL){
                tmp->anterior=NULL;//borra el anterior
                tmp=tmp->siguiente;
            }
            this->listaCentros->primerNodo=NULL;
            qDebug()<<"Generar arbol retorna true";
            //this->arbolMundo->mostrarArbol(this->arbolMundo->raiz,0);
            return true;
    }
    return false;
}
