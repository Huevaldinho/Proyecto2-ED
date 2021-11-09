#include "consultasporacciones.h"

ConsultasPorAcciones::ConsultasPorAcciones(){
    this->listaPersonas=NULL;
    this->IDBuscado=-1;
}
ConsultasPorAcciones::ConsultasPorAcciones(ListaPersonas * lista){
    this->listaPersonas=lista;
    this->IDBuscado=-1;
}
void ConsultasPorAcciones::AccionesFamilia(int IDaBuscar, QTextBrowser * cuadroTexto,QTextBrowser * cuadroTextoBuenasAcciones){//Recibe a la persona que buscamos por ID
    Nodo * buscado = this->listaPersonas->buscarPorID(IDaBuscar);
    if (buscado!=NULL){
        cuadroTexto->setText(cuadroTexto->toPlainText()+" - Pecados, aqui va toda la info");
        cuadroTextoBuenasAcciones->setText(cuadroTexto->toPlainText()+" - Benas Acciones, aqui va toda la info");
        //Empezar a meter la informacion de pecados y buenas acciones

    }else{
        qDebug()<<"NO EXISTE ESE ID EN EL MUNDO";
        qDebug()<<"TERMINA ACCIONESFAMILIA";
        QMessageBox* reply=new QMessageBox();
        reply->setText("No se encontro ningún humano con esa ID");
        reply->show();
    }
}
void ConsultasPorAcciones::TopTenAccionesPaises(){
}
void ConsultasPorAcciones::TopFiveAccionesPaises(){

}
