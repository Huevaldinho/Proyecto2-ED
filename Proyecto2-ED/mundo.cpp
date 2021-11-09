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
    //Crea la lista de personas del mundo
    this->listaPersonas= new ListaPersonas();
    this->arbolMundo->listaPersonas=this->listaPersonas;//Le pasa la misma lista al arbol
    this->listaFamilias = new ListaFamilias();//Crea la lista (raices arboles) de familias
}
int Mundo::GenerarIDRandom(){
    int limite_inferior = 0;
    int limite_superior=this->maximoHumanos;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return variable;
}
//Retorna apellido random de la lista
QString Mundo::GenerarApellidoRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadApellidos-1;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return apellidos[variable];
}
//Retorna nombre random de la lista
QString Mundo::GenerarNombreRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadNombres-1;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return nombres[variable];

}
//Retorna pais random de la lista
QString Mundo::GenerarPaisRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadPaises-1;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return paises[variable];

}
//Retorna profesion random de la lista
QString Mundo::GenerarProfesionRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadProfesiones-1;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return profesiones[variable];

}
//Retorna creencia random de la lista
QString Mundo::GenerarCreenciaRandom(){
    int limite_inferior = 0;
    int limite_superior=this->cantidadCreencias-1;
    uniform_int_distribution<int> distribution (limite_inferior,limite_superior); //random
    int variable = distribution(*QRandomGenerator::global());
    return creencias[variable];

}
QString Mundo::GenerarCorreo(QString nombre, QString apellido){
    uniform_int_distribution<int> distribution (1,3); //random
    int variable = distribution(*QRandomGenerator::global());

    for (int i=0;i<apellido.size();i++){
        if (apellido[i].isUpper()){
            apellido[i]=apellido[i].toLower();
        }
    }
    for (int i=0;i<nombre.size();i++){
        if (nombre[i].isUpper()){
            nombre[i]=nombre[i].toLower();
        }
    }

    QString correo = apellido+nombre+"@";
    if (variable==1)
        correo+="hotmail.com";
    else if (variable==2)
        correo+="outlook.com";
    else
        correo+="gmail.com";
    return correo;
}
Persona * Mundo::generarPersona(){
    uniform_int_distribution<int> distribution (0,4); //random
    int hijos = distribution(*QRandomGenerator::global()); //random hijos 0-4

    int id = GenerarIDRandom();
    QString apellido = GenerarApellidoRandom();
    QString nombre = GenerarNombreRandom();
    QString pais = GenerarPaisRandom();
    QString profesion = GenerarProfesionRandom();
    QString creencia = GenerarCreenciaRandom();
    QString correo = GenerarCorreo(nombre,apellido);
    Persona * persona = new Persona(id,nombre,apellido,pais,creencia,profesion,correo);
    persona->cantidadHijos=hijos;

    return persona;

}
//Genera una n cantidad de personas con datos aleatorios de los arreglos
void Mundo::GenerarNpersonas(int n){
    Persona * tmp = NULL;
    for (int i=0;i<n;i++){
        tmp = generarPersona();
        PuedoGenerarArbol(this->listaPersonas->largo);
        if(this->arbolMundo->raiz!=NULL){
            this->arbolMundo->insertarAListaDesdeArbol(this->arbolMundo->raiz,new Nodo(tmp));
        }else{
            this->listaPersonas->insertadoEspecialOrdenadoMenorAMayor(tmp);
        }
        //Despues de insertarlo en la lista lo va a meter a un arbol de familia
        this->listaFamilias->insertarFamilia(new Nodo(tmp));//Mete al mae al arbol familia
        //los hijos se le agregan en insertarFamilia

        tmp = NULL;
    }
    qDebug()<<"Personas en mundo: "<<listaPersonas->largo;
}
void Mundo::SacarMitades(int bloques,int ciclos){
    int contador=0;
    Nodo * mitad = this->listaPersonas->buscarMitad();
    //Lista centros es la uqe tiene los 15 nodos uqe se van a meter al arbol
    //this->listaCentros->insertarAlFinal(mitad->persona);
    this->arbolMundo->insertarNodo(this->arbolMundo->raiz,mitad,NULL);
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
                contador++;
            }
            this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
            this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
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
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
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
            this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
            this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
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
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
            break;
        }
        case 3:{//1 15
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,this->listaPersonas->primerNodo,NULL);
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,this->listaPersonas->ultimoNodo,NULL);
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
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
            break;
        }
        case 1:{
            while (contador<bloques-(bloques/3)){
                if (tmpIzquierdo->anterior!=NULL)
                    tmpIzquierdo=tmpIzquierdo->anterior;
                if (tmpDerecho->siguiente!=NULL)
                    tmpDerecho=tmpDerecho->siguiente;
                contador++;
            }
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpIzquierdo,NULL);
              this->arbolMundo->insertarNodo(this->arbolMundo->raiz,tmpDerecho,NULL);
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
            SacarMitades(bloques,nodoAinsertarEnArbol);//aqui mismo se inserta al arbol
            //this->arbolMundo->mostrarArbol(this->arbolMundo->raiz,0);
            return true;
    }
    return false;
}

void Mundo::generarPecados(){
    uniform_int_distribution<int> distribution (0,100); //random
    Nodo*tmp = this->listaPersonas->primerNodo;
    while (tmp!=NULL){
        tmp->persona->pecados[0]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[1]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[2]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[3]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[4]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[5]+=distribution(*QRandomGenerator::global());
        tmp->persona->pecados[6]+=distribution(*QRandomGenerator::global());

        if (tmp->persona->hijos->primerNodo!=NULL){
            Nodo*tmpHijo = tmp->persona->hijos->primerNodo;
            while (tmpHijo!=NULL){
                tmpHijo->persona->pecados[0]+=(tmp->persona->pecados[0]*0.5);
                tmpHijo->persona->pecados[1]+=(tmp->persona->pecados[1]*0.5);
                tmpHijo->persona->pecados[2]+=(tmp->persona->pecados[2]*0.5);
                tmpHijo->persona->pecados[3]+=(tmp->persona->pecados[3]*0.5);
                tmpHijo->persona->pecados[4]+=(tmp->persona->pecados[4]*0.5);
                tmpHijo->persona->pecados[5]+=(tmp->persona->pecados[5]*0.5);
                tmpHijo->persona->pecados[6]+=(tmp->persona->pecados[6]*0.5);

                if (tmpHijo->persona->hijos->primerNodo!=NULL){
                    Nodo*tmpNieto = tmpHijo->persona->hijos->primerNodo;
                    while (tmpNieto!=NULL){
                        tmpNieto->persona->pecados[0]+=(tmp->persona->pecados[0]*0.25);
                        tmpNieto->persona->pecados[1]+=(tmp->persona->pecados[1]*0.25);
                        tmpNieto->persona->pecados[2]+=(tmp->persona->pecados[2]*0.25);
                        tmpNieto->persona->pecados[3]+=(tmp->persona->pecados[3]*0.25);
                        tmpNieto->persona->pecados[4]+=(tmp->persona->pecados[4]*0.25);
                        tmpNieto->persona->pecados[5]+=(tmp->persona->pecados[5]*0.25);
                        tmpNieto->persona->pecados[6]+=(tmp->persona->pecados[6]*0.25);

                        tmpNieto=tmpNieto->siguiente;
                    }
                }
                tmpHijo=tmpHijo->siguiente;
            }
        }
        tmp=tmp->siguiente;
    }

}
void Mundo::generarBuenasAcciones(){
    uniform_int_distribution<int> distribution (0,100); //random
    Nodo*tmp = this->listaPersonas->primerNodo;
    while (tmp!=NULL){

        tmp->persona->buenasAcciones[0]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[1]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[2]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[3]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[4]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[5]+=distribution(*QRandomGenerator::global());
        tmp->persona->buenasAcciones[6]+=distribution(*QRandomGenerator::global());

        if (tmp->persona->hijos->primerNodo!=NULL){
            Nodo*tmpHijo = tmp->persona->hijos->primerNodo;
            while (tmpHijo!=NULL){

                tmpHijo->persona->buenasAcciones[0]+=(tmp->persona->buenasAcciones[0]*0.5);
                tmpHijo->persona->buenasAcciones[1]+=(tmp->persona->buenasAcciones[1]*0.5);
                tmpHijo->persona->buenasAcciones[2]+=(tmp->persona->buenasAcciones[2]*0.5);
                tmpHijo->persona->buenasAcciones[3]+=(tmp->persona->buenasAcciones[3]*0.5);
                tmpHijo->persona->buenasAcciones[4]+=(tmp->persona->buenasAcciones[4]*0.5);
                tmpHijo->persona->buenasAcciones[5]+=(tmp->persona->buenasAcciones[5]*0.5);
                tmpHijo->persona->buenasAcciones[6]+=(tmp->persona->buenasAcciones[6]*0.5);

                if (tmpHijo->persona->hijos->primerNodo!=NULL){
                    Nodo*tmpNieto = tmpHijo->persona->hijos->primerNodo;
                    while (tmpNieto!=NULL){

                        tmpNieto->persona->buenasAcciones[0]+=(tmp->persona->buenasAcciones[0]*0.25);
                        tmpNieto->persona->buenasAcciones[1]+=(tmp->persona->buenasAcciones[1]*0.25);
                        tmpNieto->persona->buenasAcciones[2]+=(tmp->persona->buenasAcciones[2]*0.25);
                        tmpNieto->persona->buenasAcciones[3]+=(tmp->persona->buenasAcciones[3]*0.25);
                        tmpNieto->persona->buenasAcciones[4]+=(tmp->persona->buenasAcciones[4]*0.25);
                        tmpNieto->persona->buenasAcciones[5]+=(tmp->persona->buenasAcciones[5]*0.25);
                        tmpNieto->persona->buenasAcciones[6]+=(tmp->persona->buenasAcciones[6]*0.25);

                        tmpNieto=tmpNieto->siguiente;
                    }
                }
                tmpHijo=tmpHijo->siguiente;
            }
        }
        tmp=tmp->siguiente;
    }

}
