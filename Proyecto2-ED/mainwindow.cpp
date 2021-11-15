#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->mundo=NULL;
    this->consultas=NULL;
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
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Lucifer"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Lucifer creado");
}
void MainWindow::on_btnCondenacionBelcebu_clicked(){//BELCEBU
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";


    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Belcebú"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Belcebú creado");
}
void MainWindow::on_btnCondenacionSatan_clicked(){//SATAN
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Satán"));
    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Satán creado");
}
void MainWindow::on_btnCondenacionAbadon_clicked(){//ABADON
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Abadón"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Abadón creado");
}
void MainWindow::on_btnCondenacionMammon_clicked(){//MAMMON
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Mammón"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Mammón creado");
}
void MainWindow::on_btnCondenacionBelfegor_clicked(){//BELFEGOR
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Belfegor"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Belfegor creado");
    Smtp* smtp = new Smtp("correoFinDelMundo@gmail.com", "A123456789z!", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    files.append(this->infierno->archivoCondenacion);
    if( !files.isEmpty() )
        smtp->sendMail("correoFinDelMundo@gmail.com", "sebasberacu@gmail.com" , "Reporte de condenación de Belfegor","\nAdjunto encuentra la información de la condenación de Belfegor.", files );
    else
        smtp->sendMail("correoFinDelMundo@gmail.com", "sebasberacu@gmail.com", "Reporte de condenación de Belfegor","\nAdjunto encuentra la información de la condenación de Belfegor.");

}
void MainWindow::on_btnCondenacionAsmodeo_clicked(){//ASMODEO
    QString pathInfiernoCondenacionB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaB="/Users/sebastianbermudez/Documents/CodesS2/Github/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QString pathInfiernoCondenacionH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/Condenacion-Log/";
    QString pathInfiernoConsultaH="D:/OneDrive - Estudiantes ITCR/Documentos/GitHub/ED/Proyecto2-ED/Proyecto2-ED/infoB/ConsultaInfierno/";

    QDateTime actual = QDateTime::currentDateTime();
    this->infierno->archivoConsulta=pathInfiernoConsultaH+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";
    this->infierno->archivoConsulta=pathInfiernoConsultaB+"consulta"+actual.date().toString("yyyyMMdd")+"_"+actual.time().toString("hhmmss")+".txt";

    this->infierno->MeterFamiliaALosHeap();
    this->infierno->OrdenarHeapsDemonios();

    this->infierno->Condenar(this->infierno->buscarDemonio("Asmodeo"));

    QMessageBox::information(this,"Archivo Generado","\nReporte de condenación de Asmodeo creado");
}
void MainWindow::on_btnConsultaInfierno_clicked()
{
    this->infierno->consulta();
    QMessageBox::information(this,"Archivo Generado","\nSe ha creado el archivo de consulta del infierno");
}

