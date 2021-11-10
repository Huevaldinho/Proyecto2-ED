#include "consultasporacciones.h"

ConsultasPorAcciones::ConsultasPorAcciones(){
    this->listaPersonas=NULL;
    this->IDBuscado=-1;
    this->consulta=false;
    this->listaPaises=new ListaPaises;
}
ConsultasPorAcciones::ConsultasPorAcciones(ListaPersonas * lista){
    this->listaPersonas=lista;
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
    Nodo * tmp = this->listaPersonas->primerNodo;
    int pecados=0;
    int ba=0;
    if (this->consulta){
        while (tmp!=NULL){
            pecados+=tmp->persona->pecados[0];
            pecados+=tmp->persona->pecados[1];
            pecados+=tmp->persona->pecados[2];
            pecados+=tmp->persona->pecados[3];
            pecados+=tmp->persona->pecados[4];
            pecados+=tmp->persona->pecados[5];
            pecados+=tmp->persona->pecados[6];
            ba+=tmp->persona->buenasAcciones[0];
            ba+=tmp->persona->buenasAcciones[1];
            ba+=tmp->persona->buenasAcciones[2];
            ba+=tmp->persona->buenasAcciones[3];
            ba+=tmp->persona->buenasAcciones[4];
            ba+=tmp->persona->buenasAcciones[5];
            ba+=tmp->persona->buenasAcciones[6];
            this->listaPaises->insertarAPais(tmp->persona->pais,pecados,ba);
            tmp=tmp->siguiente;
        }
            this->consulta=false;
    }
    cuadroTexto->clear();
    if (opcion==1){ //Opcion 1: Top paises mas pecadores
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 10 Paises más pecadores");
        this->listaPaises->OrdenarPaisesPorMasPecados();
        Pais * tmp=this->listaPaises->primerPais;
        for (int i=0;i<10;i++){//Mete los primeros 10 paises mas pecadores
            if (tmp!=NULL){//solo por aquello jj
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Pecados: "+QString::number(tmp->cantidadPecados));
                tmp=tmp->siguiente;
            }
        }
    }else{//Opcion 2: Top paises con mas buenas acciones
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 10 Paises Con Más Buenas Acciones");
        this->listaPaises->OrdenarPaisesPorMasBN();
        Pais * tmp=this->listaPaises->primerPais;
        for (int i=0;i<10;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Buenas Acciones: "+QString::number(tmp->cantidadBuenasAcciones));
                tmp=tmp->siguiente;
            }
        }
    }
}
void ConsultasPorAcciones::TopFiveAccionesPaises(int opcion,QTextBrowser * cuadroTexto){
    Nodo * tmp = this->listaPersonas->primerNodo;
    int pecados=0;
    int ba=0;
    if (this->consulta){
        while (tmp!=NULL){
            pecados+=tmp->persona->pecados[0];
            pecados+=tmp->persona->pecados[1];
            pecados+=tmp->persona->pecados[2];
            pecados+=tmp->persona->pecados[3];
            pecados+=tmp->persona->pecados[4];
            pecados+=tmp->persona->pecados[5];
            pecados+=tmp->persona->pecados[6];
            ba+=tmp->persona->buenasAcciones[0];
            ba+=tmp->persona->buenasAcciones[1];
            ba+=tmp->persona->buenasAcciones[2];
            ba+=tmp->persona->buenasAcciones[3];
            ba+=tmp->persona->buenasAcciones[4];
            ba+=tmp->persona->buenasAcciones[5];
            ba+=tmp->persona->buenasAcciones[6];
            this->listaPaises->insertarAPais(tmp->persona->pais,pecados,ba);
            tmp=tmp->siguiente;
        }
        this->consulta=false;
    }
    cuadroTexto->clear();
    if (opcion==1){
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 5 Paises Menos Pecadores");
        this->listaPaises->OrdenarPaisesPorMasPecados();
        Pais * tmp=this->listaPaises->ultimoPais;
        for (int i=0;i<5;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Pecados: "+QString::number(tmp->cantidadPecados));
                tmp=tmp->anterior;
            }
        }
    }else{
        cuadroTexto->setText(cuadroTexto->toPlainText()+"Top 5 Paises Con Menos Buenas Acciones");
        this->listaPaises->OrdenarPaisesPorMasBN();
        Pais * tmp=this->listaPaises->ultimoPais;
        for (int i=0;i<5;i++){
            if (tmp!=NULL){
                cuadroTexto->setText(cuadroTexto->toPlainText()+"\n Pais: "+tmp->nombre+" - Buenas Acciones: "+QString::number(tmp->cantidadBuenasAcciones));
                tmp=tmp->anterior;
            }
        }
    }
}
