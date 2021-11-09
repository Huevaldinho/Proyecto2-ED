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
    ConsultasPorAcciones * consultas;
    bool corriendo;
    bool pausa;
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
