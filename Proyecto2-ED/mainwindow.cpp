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
    this->mundo->listaPersonas->imprimir();
    qDebug()<<"Humanos En mundo: "<<this->mundo->listaPersonas->largo;
}
void MainWindow::on_btn_Pecar_clicked(){
    this->mundo->generarPecados();
}
void MainWindow::on_btn_BuenasAcciones_clicked(){
    this->mundo->generarBuenasAcciones();
}


void MainWindow::on_btn_BuscarHumano_clicked(){
    bool ok = true;
    int buscadoInt=this->ui->txt_HumanoBuscado->text().toInt(&ok);

    this->consultas->AccionesFamilia(buscadoInt,this->ui->txt_PecadosFamiliaHumanoBuscado,this->ui->txt_BuenasAccionesFamiliaHumanoBuscado);
}

