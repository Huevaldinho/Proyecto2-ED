#include "consultasporacciones.h"

ConsultasPorAcciones::ConsultasPorAcciones(){
    this->listaPersonas=NULL;
    this->IDBuscado=-1;
    this->listaPaises=new ListaPaises;
    this->cielo=NULL;
    this->infierno=NULL;
    this->mundo=NULL;
}
ConsultasPorAcciones::ConsultasPorAcciones(ListaPersonas * lista, Cielo * cieloMain, Infierno * infiMain,Mundo * mundoMain){
    this->listaPersonas=lista;
    this->mundo=mundoMain;
    this->cielo=cieloMain;
    this->infierno=infiMain;
    this->IDBuscado=-1;
    this->listaPaises= new ListaPaises();
}
void ConsultasPorAcciones::AccionesHijos(Persona * hijo,QTextBrowser * cuadroTextoPecados,QTextBrowser * cuadroTextoBuenasAcciones){
    cuadroTextoPecados->setText(cuadroTextoPecados->toPlainText()+"\n Hijo de "+hijo->padre->nombre+" - "+hijo->nombre);
    cuadroTextoBuenasAcciones->setText(cuadroTextoBuenasAcciones->toPlainText()+"\n Hijos de "+hijo->padre->nombre+" - "+hijo->nombre);
    QString pecado1 = "Lujiria: "+QString::number(hijo->pecados[0]);
    QString pecado2 = " - Gula: "+QString::number(hijo->pecados[1]);
    QString pecado3 = " - Avaricia: " +QString::number(hijo->pecados[2]);
    QString pecado4 = " - Pereza: " +QString::number(hijo->pecados[3]);
    QString pecado5 = " - Ira: " +QString::number(hijo->pecados[4]);
    QString pecado6 = " - Envidia: " +QString::number(hijo->pecados[5]);
    QString pecado7 = " - Soberbia: " +QString::number(hijo->pecados[6]);
    cuadroTextoPecados->setText(cuadroTextoPecados->toPlainText()+pecado1+pecado2+pecado3+pecado4+pecado5+pecado6+pecado7);
    QString BA1 = "Castidad: "+QString::number(hijo->buenasAcciones[0]);
    QString BA2 = " - Ayuno: "+QString::number(hijo->buenasAcciones[1]);
    QString BA3 = " - Donación: " +QString::number(hijo->buenasAcciones[2]);
    QString BA4 = " - Diligencia: " +QString::number(hijo->buenasAcciones[3]);
    QString BA5 = " - Calma: " +QString::number(hijo->buenasAcciones[4]);
    QString BA6 = " - Solidaridad: " +QString::number(hijo->buenasAcciones[5]);
    QString BA7 = " - Humildad: " +QString::number(hijo->buenasAcciones[6]);
    cuadroTextoBuenasAcciones->setText(cuadroTextoBuenasAcciones->toPlainText()+BA1+BA2+BA3+BA4+BA5+BA6+BA7);

    Nodo * tmp = hijo->hijos->primerNodo;
    while(tmp!=NULL){
        AccionesHijos(tmp->persona,cuadroTextoPecados,cuadroTextoBuenasAcciones);
        tmp=tmp->siguiente;
    }
}
void ConsultasPorAcciones::AccionesFamilia(int IDaBuscar, QTextBrowser * cuadroTextoPecados,QTextBrowser * cuadroTextoBuenasAcciones){//Recibe a la persona que buscamos por ID
    cuadroTextoPecados->clear();
    cuadroTextoBuenasAcciones->clear();
    Persona * buscado=NULL;
    Nodo * buscadoNodo=this->listaPersonas->buscarPorID(IDaBuscar);
    if (buscadoNodo!=NULL)
        buscado = buscadoNodo->persona;
    Nodo * tmp;
    if (buscado!=NULL){
        cuadroTextoPecados->setText(cuadroTextoPecados->toPlainText() + QString::number(buscado->ID)+" - " + buscado->nombre +" "+ buscado->apellido);
        cuadroTextoBuenasAcciones->setText(cuadroTextoBuenasAcciones->toPlainText() + QString::number(buscado->ID)+" - " + buscado->nombre +" "+ buscado->apellido);

        QString pecado1 = "Lujiria: "+QString::number(buscado->pecados[0]);
        QString pecado2 = " - Gula: "+QString::number(buscado->pecados[1]);
        QString pecado3 = " - Avaricia: " +QString::number(buscado->pecados[2]);
        QString pecado4 = " - Pereza: " +QString::number(buscado->pecados[3]);
        QString pecado5 = " - Ira: " +QString::number(buscado->pecados[4]);
        QString pecado6 = " - Envidia: " +QString::number(buscado->pecados[5]);
        QString pecado7 = " - Soberbia: " +QString::number(buscado->pecados[6]);
        cuadroTextoPecados->setText(cuadroTextoPecados->toPlainText()+pecado1+pecado2+pecado3+pecado4+pecado5+pecado6+pecado7);
        QString BA1 = "Castidad: "+QString::number(buscado->buenasAcciones[0]);
        QString BA2 = " - Ayuno: "+QString::number(buscado->buenasAcciones[1]);
        QString BA3 = " - Donación: " +QString::number(buscado->buenasAcciones[2]);
        QString BA4 = " - Diligencia: " +QString::number(buscado->buenasAcciones[3]);
        QString BA5 = " - Calma: " +QString::number(buscado->buenasAcciones[4]);
        QString BA6 = " - Solidaridad: " +QString::number(buscado->buenasAcciones[5]);
        QString BA7 = " - Humildad: " +QString::number(buscado->buenasAcciones[6]);
        cuadroTextoBuenasAcciones->setText(cuadroTextoBuenasAcciones->toPlainText()+BA1+BA2+BA3+BA4+BA5+BA6+BA7);
        //Si tiene hijos manda a imprimir toda la familia (generaciones hacia abajo)
        if (buscado->hijos->primerNodo!=NULL){
            tmp=buscado->hijos->primerNodo;
            //Manda a meter a los hijos
            while(tmp!=NULL){
                AccionesHijos(tmp->persona,cuadroTextoPecados,cuadroTextoBuenasAcciones);
                tmp=tmp->siguiente;
            }
        }
    }else{
        QMessageBox* reply=new QMessageBox();
        reply->setText("No se encontro ningún humano con esa ID");
        reply->show();
    }
}
void ConsultasPorAcciones::TopTenAccionesPaises(int opcion,QTextBrowser * cuadroTexto){
//    Nodo * tmpPersona = this->listaPersonas->primerNodo;
//    if (this->listaPaises->primerPais==NULL){
//        qDebug()<<"METE PAISES A ARRAY TOP TEN";
//        for (int i=0;i<this->mundo->cantidadPaises;i++){//Mete todos los paises
//                this->listaPaises->insertarAPais(this->mundo->paises[i],0,0);
//        }
//    }
    ListaPaises * paisesTmp = new ListaPaises();
    for (int i=0;i<this->mundo->cantidadPaises;i++){//Mete todos los paises
            paisesTmp->insertarAPais(this->mundo->paises[i],0,0);
    }
    Nodo * tmpPersona = this->listaPersonas->primerNodo;
    Pais * tmpPais;
    int pecados=0;
    int ba=0;

    while (tmpPersona!=NULL){
        //Suma de pecados de cada pesona
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];
        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];
        tmpPais = paisesTmp->buscarPorNombre(tmpPersona->persona->pais);
        tmpPais->cantidadPecados +=pecados;
        tmpPais->cantidadBuenasAcciones +=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    cuadroTexto->clear();
    Pais * tmp=paisesTmp->primerPais;

    if (opcion==1){ //Opcion 1: Top paises mas pecadores
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 10 Paises más pecadores");
        paisesTmp->OrdenarPaisesPorMasPecados();
        tmp=paisesTmp->primerPais;
        for (int i=0;i<10;i++){//Mete los primeros 10 paises mas pecadores
            if (tmp!=NULL){//solo por aquello jj
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+
                                     " - Pecados: "+QString::number(tmp->cantidadPecados));
                tmp=tmp->siguiente;
            }
        }
    }else{//Opcion 2: Top paises con mas buenas acciones
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 10 Paises Con Más Buenas Acciones");
        paisesTmp->OrdenarPaisesPorMasBN();
        tmp=paisesTmp->primerPais;
        for (int i=0;i<10;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+
                                     " - Buenas Acciones: "+QString::number(tmp->cantidadBuenasAcciones));
                tmp=tmp->siguiente;
            }
        }
    }
}
void ConsultasPorAcciones::TopFiveAccionesPaises(int opcion,QTextBrowser * cuadroTexto){
    ListaPaises * paisesTmp = new ListaPaises();
    for (int i=0;i<this->mundo->cantidadPaises;i++){//Mete todos los paises
            paisesTmp->insertarAPais(this->mundo->paises[i],0,0);
    }
    Nodo * tmpPersona = this->listaPersonas->primerNodo;
    Pais * tmpPais;
    int pecados=0;
    int ba=0;
    while (tmpPersona!=NULL){
        //Suma de pecados de cada pesona
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];
        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];
        tmpPais = paisesTmp->buscarPorNombre(tmpPersona->persona->pais);
        tmpPais->cantidadPecados +=pecados;
        tmpPais->cantidadBuenasAcciones +=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    cuadroTexto->clear();
    if (opcion==1){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 5 Paises Menos Pecadores");
        paisesTmp->OrdenarPaisesPorMasPecados();
        Pais * tmp=paisesTmp->ultimoPais;
        for (int i=0;i<5;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Pecados: "+QString::number(tmp->cantidadPecados));
                tmp=tmp->anterior;
            }
        }
    }else{
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 5 Paises Con Menos Buenas Acciones");
       paisesTmp->OrdenarPaisesPorMasBN();
        Pais * tmp=paisesTmp->ultimoPais;
        for (int i=0;i<5;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Buenas Acciones: "+QString::number(tmp->cantidadBuenasAcciones));
                tmp=tmp->anterior;
            }
        }
    }
}
 long long ConsultasPorAcciones::ElGanadorInfierno(QTextBrowser * cuadroTexto){
    //Funcion para ver el resumen del infierno
    //Pecados
    QVector<int> pecado=this->infierno->CantidadPecadosInfierno();
    QVector<int> ba=this->infierno->CantidadBAInfierno();
    cuadroTexto->clear();
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\tPecados infierno: \n");
    for (int i=0;i<7;i++){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Cantidad pecado "+QString::number(i)+": "+QString::number(pecado[i])+"\n");
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Total pecados: "+QString::number(
pecado[0]+pecado[1]+pecado[2]+pecado[3]+pecado[4]+pecado[5]+pecado[6]));
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\n\tBuenas acciones infierno: \n");
    for (int i=0;i<7;i++){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Cantidad ba "+QString::number(i)+": "+QString::number(ba[i])+"\n");
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Total Buenas Acciones: "+QString::number(
ba[0]+ba[1]+ba[2]+ba[3]+ba[4]+ba[5]+ba[6]));
    long long neto=0;
    for (int i=0;i<7;i++){
        neto+=(pecado[i]-ba[i]);
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\n\t Neto infierno: "+QString::number(neto));
    return  neto;
}
long long ConsultasPorAcciones::ElGanadorCielo(QTextBrowser * cuadroTexto){
    //Hacer lo mismo que ElGanadorInfierno
    //Hacer funcion para contar pecados en el cielo/ba
    QVector<int> pecado=this->cielo->CantidadPecadosCielo();
    QVector<int> ba=this->cielo->CantidadBACielo();
    cuadroTexto->clear();
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\tPecados cielo: \n");
    for (int i=0;i<7;i++){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Cantidad pecado "+QString::number(i)+": "+QString::number(pecado[i])+"\n");
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Total pecados: "+QString::number(
pecado[0]+pecado[1]+pecado[2]+pecado[3]+pecado[4]+pecado[5]+pecado[6]));
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\n\tBuenas acciones cielo: \n");
    for (int i=0;i<7;i++){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Cantidad ba "+QString::number(i)+": "+QString::number(ba[i])+"\n");
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Total Buenas Acciones: "+QString::number(
ba[0]+ba[1]+ba[2]+ba[3]+ba[4]+ba[5]+ba[6]));
    long long neto=0;
    for (int i=0;i<7;i++){
        neto+=(ba[i]-pecado[i]);
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\n\t Neto cielo: "+QString::number(neto));
    return  neto;
}
void ConsultasPorAcciones::DeterminarGanado(QTextBrowser * cuadroTextoInfierno,QTextBrowser *  cuadroCielo ,
                                            QLabel *  ganador ){
    long long netoInfierno = ElGanadorInfierno(cuadroTextoInfierno);
    long long netoCielo = ElGanadorCielo(cuadroCielo);
    if (netoInfierno>netoCielo){
        ganador->setText("Gana el Infierno con: "+QString::number(netoInfierno)+" pts.");
    }else if(netoCielo>netoInfierno){
        ganador->setText("Gana el Cielo con: "+QString::number(netoCielo)+" pts.");
    }else{
        ganador->setText("Empate");
    }
}
void ConsultasPorAcciones::BuscarFamilia(QString apellidoBuscado, QString paisBuscado,QTextBrowser * cuadroTexto){
    //Encuentra la familia solicitada
    NodoListaFalimias * familiaBuscada=this->mundo->listaFamilias->buscarFamilia(apellidoBuscado,paisBuscado);
    if (familiaBuscada==NULL){
        qDebug()<<"Familia buscada no tiene miembros...";
        cuadroTexto->clear();
        cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\t Familia \n "+apellidoBuscado+" "
                     +paisBuscado+QString::number(0)+" personas.\n");
        return;
    }
    //Pasa el arbol de familia a una LD
    ListaPersonas * familiaLista=NULL;
    if (familiaBuscada!=NULL){
        familiaLista = familiaBuscada->familia->ArbolALista(familiaBuscada->familia->raiz,new ListaPersonas ());
        //Ordena la lista de mas pecadores a menos pecadores
        familiaLista->OrdenarPorMasPecado(familiaLista);
    }


    //Saca el porcentaje de humanos en mundo, infierno y cielo
    QVector <int> porcentajes = DeterminarPorcentajeDeFamilia(familiaLista);
    //FALTA Meter en GUI
    cuadroTexto->clear();
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\t Familia \n "+familiaBuscada->familia->apellidoFamilia+" "
                 +familiaBuscada->familia->paisFamilia+QString::number(familiaLista->largo)+" personas.\n");
    cuadroTexto->setText(cuadroTexto->toPlainText()+'\n');//Enter
    Nodo * tmp = familiaLista->primerNodo;
    Nodo * tmpHijo=NULL;
    int pecados=0;
    while (tmp!=NULL){
        pecados=tmp->persona->pecados[0]+tmp->persona->pecados[1]+tmp->persona->pecados[2]+tmp->persona->pecados[3]+
                tmp->persona->pecados[4]+tmp->persona->pecados[5]+tmp->persona->pecados[6];
        cuadroTexto->setText(cuadroTexto->toPlainText()+" - Pecados: "+QString::number(pecados)+
                             "\n - Nombre: "+tmp->persona->nombre+" - Apellido: "+tmp->persona->apellido+
                             " - Pais: "+tmp->persona->pais+" - ID: "+QString::number(tmp->persona->ID)+"\n");
        if (tmp->persona->estado==-1)
            cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Infierno\n");
        else if (tmp->persona->estado==0)
            cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Mundo\n");
        else
            cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Cielo\n");
        cuadroTexto->setText(cuadroTexto->toPlainText()+'\n');//Enter

        if (tmp->persona->hijos->primerNodo!=NULL){
            tmpHijo= tmp->persona->hijos->primerNodo;
            cuadroTexto->setText(cuadroTexto->toPlainText()+"\tHijos\n");
            while (tmpHijo!=NULL){
                pecados=tmpHijo->persona->pecados[0]+tmpHijo->persona->pecados[1]+tmpHijo->persona->pecados[2]+
                        tmpHijo->persona->pecados[3]+tmpHijo->persona->pecados[4]+tmpHijo->persona->pecados[5]+
                        tmpHijo->persona->pecados[6];

                cuadroTexto->setText(cuadroTexto->toPlainText()+" - Pecados: "+QString::number(pecados)+
                                     "\n - Nombre: "+tmpHijo->persona->nombre+" - Apellido: "+
                                     tmpHijo->persona->apellido+" - Pais: "+tmpHijo->persona->pais+
                                     " - ID: "+QString::number(tmpHijo->persona->ID)+"\n");
                if (tmpHijo->persona->estado==-1)
                    cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Infierno\n");
                else if (tmpHijo->persona->estado==0)
                    cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Mundo\n");
                else
                    cuadroTexto->setText(cuadroTexto->toPlainText()+" - Ubicacion: Cielo\n");
                cuadroTexto->setText(cuadroTexto->toPlainText()+'\n');//Enter

                tmpHijo=tmpHijo->siguiente;
            }
            cuadroTexto->setText(cuadroTexto->toPlainText()+"\tFin hijos \n");
        }else{
            cuadroTexto->setText(cuadroTexto->toPlainText()+"\t NO tiene hijos\n");
        }
        tmp=tmp->siguiente;
    }
    cuadroTexto->setText(cuadroTexto->toPlainText()+"\n\tPorcentajes\n"+" - Mundo: "+
                         QString::number(porcentajes[0])+"% - Infierno: "+QString::number(porcentajes[1])+
            "% - Cielo: "+QString::number(porcentajes[2])+'%');
}
QVector<int> ConsultasPorAcciones::DeterminarPorcentajeDeFamilia(ListaPersonas * lista){
    double mundo=0;double infierno=0;double cielo=0;

    if (lista!=NULL){
        Nodo * tmp= lista->primerNodo;
        while (tmp!=NULL){
            if (tmp->persona->estado==0)
                mundo++;
            else if (tmp->persona->estado==-1)
                infierno++;
            else
                cielo++;
            tmp=tmp->siguiente;
        }
        //Falta un 1%
        mundo = (mundo*100)/lista->largo;
        infierno = (infierno*100)/lista->largo;
        cielo = (cielo*100)/lista->largo;
    }
    QVector<int> porcentajes;
    porcentajes.resize(3);
    porcentajes[0]=mundo;
    porcentajes[1]=infierno;
    porcentajes[2]=cielo;
    return porcentajes;
}
