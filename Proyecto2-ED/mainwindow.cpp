#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->mundo=NULL;
    this->consultas=NULL;
    this->infierno=NULL;
    this->cielo=NULL;
    this->corriendo=false;
    this->pausa=false;
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_btn_GenerarHumanos_clicked(){//GENERAR HUMANOS
    bool ok = true;
    int nGenerar=this->ui->txt_CantidadHumanosGenerar->text().toDouble(&ok);
    this->mundo->GenerarNpersonas(nGenerar);
    this->consultas->consulta=true;
    this->ui->lbl_CantidaNivelesArbol->setText(QString::number(this->mundo->arbolMundo->height(this->mundo->arbolMundo->raiz)));
    this->ui->lbl_CantidadDeNodos->setText(QString::number(this->mundo->arbolMundo->contadorNodos(this->mundo->arbolMundo->raiz)));
    this->ui->lbl_CantidadTotalHumanos->setText(QString::number(this->mundo->listaPersonas->largo));
    this->ui->txt_InformacionUltimoNivelArbol->clear();
    this->mundo->arbolMundo->InformacionUltimoNivel(this->mundo->arbolMundo->raiz,this->ui->txt_InformacionUltimoNivelArbol);
    //Infierno
    this->infierno->MeterFamiliaALosHeap();
    //this->infierno->imprimirFamiliasDeminios();
    this->infierno->OrdenarHeapsDemonios();
}
void MainWindow::on_btn_Pecar_clicked(){//PECAR
    this->mundo->generarPecados();
    this->consultas->consulta=true;
}
void MainWindow::on_btn_BuenasAcciones_clicked(){//BUENAS ACCIONES
    this->mundo->generarBuenasAcciones();
    this->consultas->consulta=true;
}
//TOPS
void MainWindow::on_btn_BuscarHumano_clicked(){
    bool ok = true;
    int buscadoInt=this->ui->txt_HumanoBuscado->text().toInt(&ok);
    this->consultas->AccionesFamilia(buscadoInt,this->ui->txt_PecadosFamiliaHumanoBuscado,this->ui->txt_BuenasAccionesFamiliaHumanoBuscado);
}
void MainWindow::on_btn_Top10PaisesMasPecadores_clicked(){
    this->consultas->TopTenAccionesPaises(1,this->ui->txt_ConsultasPorPaises);
}
void MainWindow::on_btn_Top10PaisesConMasBuenasAcciones_clicked(){
    this->consultas->TopTenAccionesPaises(2,this->ui->txt_ConsultasPorPaises);
}
void MainWindow::on_btn_Top5PaisesMenosPecadores_clicked(){
    this->consultas->TopFiveAccionesPaises(1,this->ui->txt_ConsultasPorPaises);
}
void MainWindow::on_btn_Top5PaisesMenosBuenos_clicked(){
     this->consultas->TopFiveAccionesPaises(2,this->ui->txt_ConsultasPorPaises);
}
//CONDENACION
void MainWindow::on_btnCondenacionLucifer_clicked(){//LUCIFER
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Lucifer"));



    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Lucifer","\nAdjunto encuentra la información de la condenación de Lucifer.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Lucifer","\nAdjunto encuentra la información de la condenación de Lucifer.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Lucifer creado");
}
void MainWindow::on_btnCondenacionBelcebu_clicked(){//BELCEBU
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";


    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Belcebú"));


    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Belcebú","\nAdjunto encuentra la información de la condenación de Belcebú.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Belcebú","\nAdjunto encuentra la información de la condenación de Belcebú.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Belcebú creado");
}
void MainWindow::on_btnCondenacionSatan_clicked(){//SATAN
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Satán"));

    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Satán","\nAdjunto encuentra la información de la condenación de Satán.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Satán","\nAdjunto encuentra la información de la condenación de Satán.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Satán creado");
}
void MainWindow::on_btnCondenacionAbadon_clicked(){//ABADON
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Abadón"));


    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Abadón","\nAdjunto encuentra la información de la condenación de Abadón.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Abadón","\nAdjunto encuentra la información de la condenación de Abadón.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Abadón creado");
}
void MainWindow::on_btnCondenacionMammon_clicked(){//MAMMON
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Mammón"));


    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Mammón","\nAdjunto encuentra la información de la condenación de Mammón.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Mammón","\nAdjunto encuentra la información de la condenación de Mammón.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Mammón creado");
}
void MainWindow::on_btnCondenacionBelfegor_clicked(){//BELFEGOR
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Belfegor"));


    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Belfegor","\nAdjunto encuentra la información de la condenación de Belfegor.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Belfegor","\nAdjunto encuentra la información de la condenación de Belfegor.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Belfegor creado");
}
void MainWindow::on_btnCondenacionAsmodeo_clicked(){//ASMODEO
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoCondenacion=pathInfiernoCondenacionH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Asmodeo"));


    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com" , "Reporte de condenación de Asmodeo","\nAdjunto encuentra la información de la condenación de Asmodeo.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "correoFinDelMundo@gmail.com", "Reporte de condenación de Asmodeo","\nAdjunto encuentra la información de la condenación de Asmodeo.");
    this->files.clear();
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Asmodeo creado");
}
void MainWindow::on_btnConsultaInfierno_clicked(){
    QDateTime actual = QDateTime::currentDateTime();
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";
    this->infierno->archivoConsulta=pathInfiernoConsultaH+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->consulta();
    QMessageBox::information(this,"Archivo Generado","\nSe ha creado el archivo de consulta del infierno");

}
void MainWindow::on_btnSalvar_clicked(){//Salvacion
    qDebug()<<"SALVACION";

}


void MainWindow::on_btnGanador_clicked(){
    this->consultas->DeterminarGanado(this->ui->lbl_txtGanadorInfnerno,this->ui->lbl_txtGanadorCielo,
                                      this->ui->lbl_GanadorFinal);

}

//Si tira error porque falta funcion, ir al archivo donde marca el error y comentar la linea que marca
void MainWindow::on_btnConsultaPor_clicked(){
    switch(this->ui->comboBox_Consulta->currentIndex()){//Lenar la lista segun el indice seleccionado disponibles
        case 0:{//Apellido
            ConsultarPorApellido();
            break;
        }
        case 1:{//Continente - NO EXISTE CONTINENTE
            ConsultarPorContinente();
            break;
        }
        case 2:{//Paises
            ConsultarPorPais();
            break;
        }
        case 3:{//Creencias
            ConsultarPorCreencia();
            break;
        }
        case 4:{//Profesiones
            ConsultarPorProfesion();
            break;
        }
    }
}
//Consultar por...

//Consultas
void MainWindow::ConsultarPorApellido(){//Por apellido

    /*
        Ordena de mayor a menor
        Muestra: Total- Porcentaje de todos los pecados/ba del mundo
    */
    //(pecadosFamilia/pecadosTotales)*100=porcentaje de pecados de esa familia con respecto al total
    //igual para las ba

    ListaPaises * apellidosTmp = new ListaPaises();
    //void ListaPaises::insertarAPais(QString _nombre,long long  pecados,long long  ba)
    for (int i=0;i<this->mundo->cantidadApellidos;i++){//Mete todos los apellidos
            apellidosTmp->insertarAPais(this->mundo->apellidos[i],0,0);
    }
    Pais * tmp;
    Nodo * tmpPersona = this->mundo->listaPersonas->primerNodo;
    int pecados =0;
    int ba =0;
    while (tmpPersona!=NULL){
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];

        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];

        tmp = apellidosTmp->buscarPorNombre(tmpPersona->persona->apellido);
        tmp->cantidadPecados+=pecados;
        tmp->cantidadBuenasAcciones+=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    apellidosTmp->OrdenarPaisesPorMasPecados();

    this->ui->lbl_txtConsultaPorResultado->clear();
    tmp = apellidosTmp->primerPais;
    qDebug()<<"Total pecados mundo: "<<this->mundo->totalPecados;
    double cien=100;
    double resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"Total pecados mundo: "+QString::number(this->mundo->totalPecados)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadPecados)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadPecados)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
    //METER BUENAS ACCIONES
    apellidosTmp->OrdenarPaisesPorMasBN();
    tmp = apellidosTmp->primerPais;
    cien=100;
    resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"\nTotal buenas acciones mundo: "+QString::number(this->mundo->totalba)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadBuenasAcciones)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadBuenasAcciones)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }



}
void MainWindow::ConsultarPorContinente(){//Por continente



}
void MainWindow::ConsultarPorPais(){//Por pais
    ListaPaises * paisesTmp = new ListaPaises();
    for (int i=0;i<this->mundo->cantidadPaises;i++){//Mete todos los paises
            paisesTmp->insertarAPais(this->mundo->paises[i],0,0);
    }
    Pais * tmp;
    Nodo * tmpPersona = this->mundo->listaPersonas->primerNodo;
    int pecados =0;
    int ba =0;
    while (tmpPersona!=NULL){
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];
        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];
        tmp = paisesTmp->buscarPorNombre(tmpPersona->persona->pais);
        tmp->cantidadPecados+=pecados;
        tmp->cantidadBuenasAcciones+=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    paisesTmp->OrdenarPaisesPorMasPecados();

    this->ui->lbl_txtConsultaPorResultado->clear();
    tmp = paisesTmp->primerPais;
    double cien=100;
    double resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"Total pecados mundo: "+QString::number(this->mundo->totalPecados)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadPecados)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadPecados)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
    paisesTmp->OrdenarPaisesPorMasBN();
    tmp = paisesTmp->primerPais;
    cien=100;
    resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"\nTotal buenas acciones mundo: "+QString::number(this->mundo->totalba)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadBuenasAcciones)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadBuenasAcciones)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }



}
void MainWindow::ConsultarPorCreencia(){//Por creencia
    ListaPaises * creenciaTmp = new ListaPaises();
    for (int i=0;i<this->mundo->cantidadCreencias;i++){//Mete todos las creencias
            creenciaTmp->insertarAPais(this->mundo->creencias[i],0,0);
    }
    Pais * tmp;
    Nodo * tmpPersona = this->mundo->listaPersonas->primerNodo;
    int pecados =0;
    int ba =0;
    while (tmpPersona!=NULL){
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];
        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];
        tmp = creenciaTmp->buscarPorNombre(tmpPersona->persona->creencia);
        tmp->cantidadPecados+=pecados;
        tmp->cantidadBuenasAcciones+=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    creenciaTmp->OrdenarPaisesPorMasPecados();

    this->ui->lbl_txtConsultaPorResultado->clear();
    tmp = creenciaTmp->primerPais;
    double cien=100;
    double resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"Total pecados mundo: "+QString::number(this->mundo->totalPecados)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadPecados)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadPecados)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
    creenciaTmp->OrdenarPaisesPorMasBN();
    tmp = creenciaTmp->primerPais;
    cien=100;
    resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"\nTotal buenas acciones mundo: "+QString::number(this->mundo->totalba)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadBuenasAcciones)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadBuenasAcciones)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
}
void MainWindow::ConsultarPorProfesion(){//Por profesion
    ListaPaises * profesionTmp = new ListaPaises();
    for (int i=0;i<this->mundo->cantidadProfesiones;i++){//Mete todos las creencias
            profesionTmp->insertarAPais(this->mundo->profesiones[i],0,0);
    }
    Pais * tmp;
    Nodo * tmpPersona = this->mundo->listaPersonas->primerNodo;
    int pecados =0;
    int ba =0;
    while (tmpPersona!=NULL){
        pecados+=tmpPersona->persona->pecados[0]+tmpPersona->persona->pecados[1]+tmpPersona->persona->pecados[2]+
                tmpPersona->persona->pecados[3]+tmpPersona->persona->pecados[4]+tmpPersona->persona->pecados[5]+
                tmpPersona->persona->pecados[6];
        ba+=tmpPersona->persona->buenasAcciones[0]+tmpPersona->persona->buenasAcciones[1]+
                tmpPersona->persona->buenasAcciones[2]+tmpPersona->persona->buenasAcciones[3]+
                tmpPersona->persona->buenasAcciones[4]+tmpPersona->persona->buenasAcciones[5]+
                tmpPersona->persona->buenasAcciones[6];
        tmp = profesionTmp->buscarPorNombre(tmpPersona->persona->profesion);
        tmp->cantidadPecados+=pecados;
        tmp->cantidadBuenasAcciones+=ba;

        ba=0;
        pecados=0;
        tmpPersona=tmpPersona->siguiente;
    }
    profesionTmp->OrdenarPaisesPorMasPecados();

    this->ui->lbl_txtConsultaPorResultado->clear();
    tmp = profesionTmp->primerPais;
    double cien=100;
    double resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"Total pecados mundo: "+QString::number(this->mundo->totalPecados)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadPecados)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadPecados)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
    profesionTmp->OrdenarPaisesPorMasBN();
    tmp = profesionTmp->primerPais;
    cien=100;
    resultado=0;
    this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+"\nTotal buenas acciones mundo: "+QString::number(this->mundo->totalba)+'\n');
    while (tmp!=NULL){
        resultado=(cien*tmp->cantidadBuenasAcciones)/this->mundo->totalPecados;

        this->ui->lbl_txtConsultaPorResultado->setText(this->ui->lbl_txtConsultaPorResultado->toPlainText()+
                tmp->nombre+"\t"+QString::number(tmp->cantidadBuenasAcciones)+" - "+
                QString::number(resultado)+"% de los totales del mundo\n");
        tmp=tmp->siguiente;
    }
}
