#include "infierno.h"


Infierno::Infierno(int cantidadFamilias, ListaPersonas * personas){
    //Crea los demonios
    this->humanosMundo = personas;
    this->demonios[0]= new Demonio("Asmodeo",cantidadFamilias);//Lujuria
    this->demonios[0]->posicionPecadoEnArreglo=0;
    this->demonios[1]= new Demonio("Belfegor",cantidadFamilias);//Gula
    this->demonios[1]->posicionPecadoEnArreglo=1;
    this->demonios[2]= new Demonio("Mammón",cantidadFamilias);//Avaricia
    this->demonios[2]->posicionPecadoEnArreglo=2;
    this->demonios[3]= new Demonio("Abadón",cantidadFamilias);//Pereza
    this->demonios[3]->posicionPecadoEnArreglo=3;
    this->demonios[4]= new Demonio("Satán",cantidadFamilias);//Ira
    this->demonios[4]->posicionPecadoEnArreglo=4;
    this->demonios[5]= new Demonio("Belcebú",cantidadFamilias);//Envidia
    this->demonios[5]->posicionPecadoEnArreglo=5;
    this->demonios[6]= new Demonio("Lucifer",cantidadFamilias);//Soberbia
    this->demonios[6]->posicionPecadoEnArreglo=6;
}
void Infierno::MeterFamiliaALosHeap(){
    Nodo * tmp = humanosMundo->primerNodo;
    int demonio=0;
    while (tmp!=NULL){
        //Mete a todas las familias en todos los demonios
        while (demonio<7){
            this->demonios[demonio]->InsertarEnHeap(tmp->persona->apellido,tmp->persona->pais);
            demonio++;
        }
        demonio=0;
        tmp=tmp->siguiente;
    }
    qDebug()<<"Termina meter familia a los heap de demonios";
}
void Infierno::imprimirFamiliasDeminios(){
    int demonio=0;
    while(demonio<7){//Avanza en todos los demonios
        this->demonios[demonio]->imprimirFamilia();
        demonio++;
    }
    qDebug()<<"Termina imprimir familia deminioos infierno";
}
void Infierno::OrdenarHeapsDemonios(){
    int demonio=0;
    while(demonio<7){//Avanza en todos los demonios
        this->demonios[demonio]->OrdenarHeap();
        demonio++;
    }
    qDebug()<<"Termina ordenar heaps demonios infierno";
}
Demonio* Infierno::buscarDemonio(QString nombre){
    for (int i = 0 ; i<7 ; i++){
        if (nombre==this->demonios[i]->nombre)
            return demonios[i];
    }
    return NULL;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(Persona * data[], int length,int pecado) {
  for (int step = 0; step < length - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < length; i++) {
      if ((data[i]->pecados[pecado]-data[i]->buenasAcciones[pecado]) < (data[min_idx]->pecados[pecado]-data[i]->buenasAcciones[pecado]))
        min_idx = i;//se resta el antagónico para evaluar nada más, nunca cambia el dato
    }
    swap(data[min_idx], data[step]);
  }
}
void Infierno::escribirArchivo(Persona*persona,Demonio*demonio){
    QDateTime actual = QDateTime::currentDateTime();

    QFile file(this->archivoCondenacion);
    //if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream w(&file);

        w << actual.date().toString("yyyy-MM-dd")<<" "<<actual.time().toString("hh:mm:ss") << "\t Humano "<<
             QString::number(persona->ID) <<". "<<persona->nombre<<" "<<persona->apellido<<", de "<<persona->pais<<". Murió el "<<
             actual.date().toString("yyyy-MM-dd")<<" condenado(a) por "<<persona->pecados[demonio->posicionPecadoEnArreglo]<<
             " pecados de "<<demonio->nombrePecado()<<" y "<<persona->buenasAcciones[demonio->posicionPecadoEnArreglo]<<
             " acciones de "<<demonio->nombreAntagonico()<<" por el demonio "<<demonio->nombre<<".\n";
        file.close();
    }
}
void Infierno::Condenar(Demonio*demonio){
    int pecado = demonio->posicionPecadoEnArreglo;
    Nodo * tmp = this->humanosMundo->primerNodo;
    int porcentaje = (this->humanosMundo->largo*5)/100;
    Persona * personas[this->humanosMundo->largo];

    for (int i = 0 ; i<this->humanosMundo->largo ; i++){//meter esos pecados en el arreglo
        if (tmp!=NULL){//por si acaso xd
            personas[i]=tmp->persona;
            personas[i]->pecados[pecado]-=personas[i]->buenasAcciones[pecado];
            tmp=tmp->siguiente;
        }
    }
    selectionSort(personas,this->humanosMundo->largo,pecado);//ordena las personas del mundo en orden según el demonio
    for (int i = this->humanosMundo->largo-1;i>(this->humanosMundo->largo-porcentaje);i--){
        if (personas[i]->estado!=-1){//si no está muerto
            personas[i]->estado = -1; //lo mata
            demonio->pecadosAcumulados+=personas[i]->pecados[pecado];
            demonio->personasTotales++;
            demonio->heapFamilias[demonio->BuscarFamilia(personas[i]->apellido,personas[i]->pais)]->listaPersonas->insertarAlFinal(personas[i]);//mete al muerto en el heap del demonio de su familia
            demonio->OrdenarHeap();
            escribirArchivo(personas[i],demonio);
            //aqui enviar al correo
        }
    }
}
void Infierno::consulta(){
    QFile file(this->archivoConsulta);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream w(&file);
        for (int i = 0 ; i<7 ; i++){
            int pa = this->demonios[i]->pecadosAcumulados;
            int pt = this->demonios[i]->personasTotales;
                qDebug()<<"PA: "<<pa;
            qDebug()<<"PT: "<<pt; //no sé porqué están en 0 si yo los sumo cuando condeno, como es división entre 0 se cae
            int promedio=0;
            if (pt!=0)
                promedio = pa/pt;//es pa/pt
            w <<
            this->demonios[i]->nombre << "\t" << "Pecado: " << this->demonios[i]->nombrePecado() << "\n" <<
            "Cantidad de Humanos: "<< QString::number(this->demonios[i]->personasTotales) <<"\tPromedio de pecados: "<<QString::number(promedio) <<"\n"<<
            "Máximo de pecados: "<<QString::number(this->demonios[i]->maxPecado())<<"\t Mínimo de pecados: "<<QString::number(this->demonios[i]->minPecado())<<"\n"<<
            this->demonios[i]->detallePecadores()<< "\n\n\n\n";

        }
        file.close();
    }else{
        qDebug()<<"ELSEEEEE";
    }
}

