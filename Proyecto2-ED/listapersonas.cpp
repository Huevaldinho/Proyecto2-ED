#include "listapersonas.h"

ListaPersonas::ListaPersonas(){
    this->primerNodo=NULL;
    this->ultimoNodo=NULL;
    this->largo=0;//Cantidad de personas en el mundo
}

bool ListaPersonas::estaVacia(){
    return this->primerNodo == NULL;
}
void ListaPersonas::insertarAlInicio(Persona * _persona){
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(_persona);
    else{
        this->primerNodo->anterior = new Nodo(_persona);
        this->primerNodo->anterior->siguiente = this->primerNodo;
        this->primerNodo = this->primerNodo->anterior;
    }
    qDebug()<<"Se inserto persona con ID: "<<this->primerNodo->persona->ID;
    this->largo++;
}
void ListaPersonas::insertarAlFinal(Persona * _persona){
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(_persona);
    else{
        this->ultimoNodo->siguiente = new Nodo(_persona);
        this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
        this->ultimoNodo = this->ultimoNodo->siguiente;
    }
    largo++;
}
void ListaPersonas::insertadoEspecialOrdenadoMenorAMayor(Persona * persona){
    //Se utiliza para crear los primeros humanos porque aun no tenemos arbol.
    //Toma las personas y las ordena de menor a mayor (ID)
    //Es el metodo que utiliza mundo->GenerarNpersonas(n), es lento y por eso necesitamos el arbol
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(persona);
    else{
        Nodo * nuevo = new Nodo(persona);
        Nodo * tmp = this->primerNodo;
        while (tmp!=NULL){
            //qDebug()<<"persona: "<<persona->ID<<" - tmp: "<<tmp->persona->ID;//para ver como avanza el insertado
            if (persona->ID==tmp->persona->ID){
                //qDebug()<<"REPETIDOO";
                largo--;//es porque abajo se le suma 1
                break;
            }
            if (persona->ID>=this->ultimoNodo->persona->ID){//Si es mayor que el ultimo inserta al final
                this->ultimoNodo->siguiente = nuevo;
                this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
                this->ultimoNodo = this->ultimoNodo->siguiente;
                break;
            }else if(persona->ID<=this->primerNodo->persona->ID){
                this->primerNodo->anterior = nuevo;
                this->primerNodo->anterior->siguiente = this->primerNodo;
                this->primerNodo = this->primerNodo->anterior;
                break;
            }else{//Buscarlo en medio de la lista
                //nuevo>tmp and nuevo<tmpSiguiente
                //Inserta entre tmp y tmp siguiente
                if (persona->ID>=tmp->persona->ID && persona->ID<=tmp->siguiente->persona->ID){
                    //tmp - nuevo - tmpsiguiente
                    nuevo->siguiente=tmp->siguiente;//Pega nuevo con siguiente
                    nuevo->anterior=tmp;//pega nuevo con tmp
                    tmp->siguiente->anterior=nuevo;//pega siguiente con nuevo
                    tmp->siguiente=nuevo;//tmp con nuevo
                    //qDebug()<<"tmp: "<<tmp->persona->ID<<" nuevo: "<<nuevo->persona->ID<<" nuevo siguiente: "<<nuevo->siguiente->persona->ID;
                    break;
                }else if (persona->ID<=tmp->persona->ID && persona->ID>=tmp->anterior->persona->ID){
                    //tmpAnterior - nuevo - tmp
                    //qDebug()<<"tmpAnterior: "<<tmp->anterior->persona->ID<<" nuevo: "<<nuevo->persona->ID<<" nuevo siguiente: "<<nuevo->siguiente->persona->ID;
                    nuevo->siguiente=tmp;
                    nuevo->anterior=tmp->anterior;
                    nuevo->siguiente->anterior=nuevo;
                    tmp->anterior=nuevo;
                    break;
                }
            }
            tmp=tmp->siguiente;
        }
    }
    largo++;
}
void ListaPersonas::insertarDesdeArbol(Nodo * _tmp,Persona * persona){
    //tmp es un nodo de la lista de personas del mundo (se toma el nodo del arbol para caer a la lista)
    //tmp es el que me permite determinar si tengo que insertar hacia delante de la lista
    //o hacia atras.
    if (estaVacia())
        this->primerNodo = this->ultimoNodo = new Nodo(persona);
    else{
        Nodo * nuevo = new Nodo(persona);
        Nodo * tmp = _tmp;
        while (tmp!=NULL){
            //qDebug()<<"persona: "<<persona->ID<<" - tmp: "<<tmp->persona->ID;
            if (persona->ID==tmp->persona->ID){
                //qDebug()<<"REPETIDOO";
                largo--;//es porque abajo se le suma 1
                break;
            }
            if (persona->ID>this->ultimoNodo->persona->ID){
                //qDebug()<<"Inserta en mayor que ultimo nodo"<<"- ultimo: "<<this->ultimoNodo->persona->ID<<" -nuevo: "<<nuevo->persona->ID;

                this->ultimoNodo->siguiente = nuevo;
                this->ultimoNodo->siguiente->anterior = this->ultimoNodo;
                this->ultimoNodo = this->ultimoNodo->siguiente;
                break;
            }else if(persona->ID<this->primerNodo->persona->ID){
                //qDebug()<<"Inserta en menor que ultimo nodo"<<" -nuevo: "<<nuevo->persona->ID<<" - primero: "<<this->primerNodo->persona->ID;
                this->primerNodo->anterior = nuevo;
                this->primerNodo->anterior->siguiente = this->primerNodo;
                this->primerNodo = this->primerNodo->anterior;
                break;
            }else{//Buscarlo en medio de la lista
                if ((persona->ID>tmp->persona->ID) &&(persona->ID<tmp->siguiente->persona->ID)){
                    //qDebug()<<"Inserta en tmp siguiente - tmp: "<<tmp->persona->ID<<"-nuevo:"<<nuevo->persona->ID<<"-tmp siguiente: "<<tmp->siguiente->persona->ID;
                    nuevo->siguiente=tmp->siguiente;
                    nuevo->anterior=tmp;
                    tmp->siguiente->anterior=nuevo;
                    tmp->siguiente=nuevo;
                    break;
                }else if ((persona->ID<tmp->persona->ID) &&( persona->ID>tmp->anterior->persona->ID)){
                    //tmp anterior < nuevo < tmp y nuevo
                    //qDebug()<<"Inserta en tmp anterior"<<" -anterior: "<<tmp->anterior->persona->ID<<" -nuevo: "<<nuevo->persona->ID<<" -tmp: "<<tmp->persona->ID;

                    nuevo->siguiente=tmp;//Pega nuevo con tmp nuevo->tmp
                    nuevo->anterior=tmp->anterior;//Pega nuevo con tmpAnterior tmpAnterior->nuevo
                    tmp->anterior->siguiente=nuevo;//Pega tmpAnteriorSiguiente con nuevo tmpAnteriorSiguiente->nuevo
                    tmp->anterior=nuevo;//Pega tmpAnterior con nuevo tmpAnterior con nuevo nuevo->tmp

                    break;
                }
            }
            if (tmp->persona->ID>persona->ID)
                tmp=tmp->anterior;
            else
                tmp=tmp->siguiente;
        }
    }
    largo++;
}
void ListaPersonas::imprimir(){
    Nodo * tmp = this->primerNodo;
    while (tmp != NULL){
        tmp->imprimir();
        tmp = tmp->siguiente;
    }
    qDebug()<<"Termina imprimir";
}
void ListaPersonas::imprimirDesdeElFinal(){
    Nodo * tmp = this->ultimoNodo;
    while (tmp != NULL){
        tmp->imprimir();
        tmp = tmp->anterior;
    }
    qDebug();
}
Nodo * ListaPersonas::borrarAlInicio(){
    Nodo * borrado = primerNodo;
    if (!estaVacia()){
        if (this->primerNodo == this->ultimoNodo)
            this->primerNodo = this->ultimoNodo = NULL;
        else{
            this->primerNodo = primerNodo->siguiente;
            this->primerNodo->anterior = NULL;
            borrado->siguiente = NULL;
        }
        return borrado;
    }
    return borrado;
}
Nodo * ListaPersonas::borrarAlFinal(){
    Nodo * borrado = ultimoNodo;
    if (!estaVacia()){
        if (this->primerNodo == this->ultimoNodo)
            this->primerNodo = this->ultimoNodo = NULL;
        else{
            this->ultimoNodo = this->ultimoNodo->anterior;
            this->ultimoNodo->siguiente = NULL;
            borrado->anterior = NULL;
        }
        return borrado;
    }
    return borrado;
}
Nodo * ListaPersonas::buscar(Persona * _persona){
    Nodo * tmp = primerNodo;
    while (tmp != NULL){
        if (tmp->persona->ID == _persona->ID)
            return tmp;
        tmp = tmp->siguiente;
    }
    return NULL;
}
Nodo * ListaPersonas::buscarMitad(){
    if (this->primerNodo==NULL)
        return NULL;
    if (this->primerNodo==this->ultimoNodo)
        return this->primerNodo;
    Nodo * tmp = this->primerNodo;
    int mitad=(this->largo/2);//Este es el modo que se va a utilizar como raiz para generar el arbol
    int contadorAvanzaLista=0;//Para saber cuando llego a la mitad
    while (tmp!=NULL){
        if (mitad==contadorAvanzaLista)
            return tmp;
        contadorAvanzaLista++;
        tmp=tmp->siguiente;
    }
    return NULL;
}
