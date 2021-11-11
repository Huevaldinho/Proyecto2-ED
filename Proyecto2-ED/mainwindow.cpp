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


void MainWindow::on_btn_GenerarHumanos_clicked(){
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
void MainWindow::on_btn_Pecar_clicked(){
    this->mundo->generarPecados();
    this->consultas->consulta=true;
}
void MainWindow::on_btn_BuenasAcciones_clicked(){
    this->mundo->generarBuenasAcciones();
    this->consultas->consulta=true;
}
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

