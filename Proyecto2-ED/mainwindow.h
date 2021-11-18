#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Mundo * mundo;
    Infierno * infierno;
    Cielo * cielo;
    ConsultasPorAcciones * consultas;
    bool corriendo;
    bool pausa;
    QStringList files;
    ~MainWindow();

private slots:
    void on_btn_GenerarHumanos_clicked();

    void on_btn_Pecar_clicked();

    void on_btn_BuenasAcciones_clicked();

    void on_btn_BuscarHumano_clicked();

    void on_btn_Top10PaisesMasPecadores_clicked();

    void on_btn_Top10PaisesConMasBuenasAcciones_clicked();

    void on_btn_Top5PaisesMenosPecadores_clicked();

    void on_btn_Top5PaisesMenosBuenos_clicked();

    void on_btnCondenacionLucifer_clicked();

    void on_btnCondenacionBelcebu_clicked();

    void on_btnCondenacionSatan_clicked();

    void on_btnCondenacionAbadon_clicked();

    void on_btnCondenacionMammon_clicked();

    void on_btnCondenacionBelfegor_clicked();

    void on_btnCondenacionAsmodeo_clicked();

    void on_btnConsultaInfierno_clicked();

    void on_btnSalvar_clicked();

    void on_btnGanador_clicked();

    void on_btnConsultaPor_clicked();
    void ConsultarPorApellido();
    void ConsultarPorContinente();
    void ConsultarPorPais();
    void ConsultarPorCreencia();
    void ConsultarPorProfesion();

    void on_btnBuscarFamiliaVer_clicked();

    void on_btnBuscarFamilia_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
