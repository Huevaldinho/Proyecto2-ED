/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_GenerarHumanos;
    QLineEdit *txt_CantidadHumanosGenerar;
    QLabel *lbl_IngreseCantidadHumanos;
    QPushButton *btn_Pecar;
    QPushButton *btn_BuenasAcciones;
    QLabel *lbl_IDHumanosBuscado;
    QPushButton *btn_BuscarHumano;
    QLineEdit *txt_HumanoBuscado;
    QTextBrowser *txt_PecadosFamiliaHumanoBuscado;
    QLabel *lbl_PecadosFamilia;
    QLabel *lbl_BuenasAcciones;
    QTextBrowser *txt_BuenasAccionesFamiliaHumanoBuscado;
    QGroupBox *groupBox;
    QPushButton *btn_Top10PaisesMasPecadores;
    QPushButton *btn_Top5PaisesMenosPecadores;
    QPushButton *btn_Top10PaisesConMasBuenasAcciones;
    QPushButton *btn_Top5PaisesMenosBuenos;
    QTextBrowser *txt_ConsultasPorPaises;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1278, 637);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_GenerarHumanos = new QPushButton(centralwidget);
        btn_GenerarHumanos->setObjectName(QString::fromUtf8("btn_GenerarHumanos"));
        btn_GenerarHumanos->setGeometry(QRect(500, 120, 161, 41));
        QFont font;
        font.setItalic(false);
        font.setUnderline(false);
        btn_GenerarHumanos->setFont(font);
        txt_CantidadHumanosGenerar = new QLineEdit(centralwidget);
        txt_CantidadHumanosGenerar->setObjectName(QString::fromUtf8("txt_CantidadHumanosGenerar"));
        txt_CantidadHumanosGenerar->setGeometry(QRect(520, 70, 131, 31));
        lbl_IngreseCantidadHumanos = new QLabel(centralwidget);
        lbl_IngreseCantidadHumanos->setObjectName(QString::fromUtf8("lbl_IngreseCantidadHumanos"));
        lbl_IngreseCantidadHumanos->setGeometry(QRect(450, 40, 271, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        lbl_IngreseCantidadHumanos->setFont(font1);
        btn_Pecar = new QPushButton(centralwidget);
        btn_Pecar->setObjectName(QString::fromUtf8("btn_Pecar"));
        btn_Pecar->setGeometry(QRect(80, 70, 131, 51));
        btn_BuenasAcciones = new QPushButton(centralwidget);
        btn_BuenasAcciones->setObjectName(QString::fromUtf8("btn_BuenasAcciones"));
        btn_BuenasAcciones->setGeometry(QRect(80, 130, 131, 51));
        lbl_IDHumanosBuscado = new QLabel(centralwidget);
        lbl_IDHumanosBuscado->setObjectName(QString::fromUtf8("lbl_IDHumanosBuscado"));
        lbl_IDHumanosBuscado->setGeometry(QRect(50, 230, 241, 31));
        QFont font2;
        font2.setBold(true);
        lbl_IDHumanosBuscado->setFont(font2);
        btn_BuscarHumano = new QPushButton(centralwidget);
        btn_BuscarHumano->setObjectName(QString::fromUtf8("btn_BuscarHumano"));
        btn_BuscarHumano->setGeometry(QRect(90, 310, 111, 41));
        txt_HumanoBuscado = new QLineEdit(centralwidget);
        txt_HumanoBuscado->setObjectName(QString::fromUtf8("txt_HumanoBuscado"));
        txt_HumanoBuscado->setGeometry(QRect(90, 270, 113, 24));
        txt_PecadosFamiliaHumanoBuscado = new QTextBrowser(centralwidget);
        txt_PecadosFamiliaHumanoBuscado->setObjectName(QString::fromUtf8("txt_PecadosFamiliaHumanoBuscado"));
        txt_PecadosFamiliaHumanoBuscado->setGeometry(QRect(30, 390, 261, 192));
        lbl_PecadosFamilia = new QLabel(centralwidget);
        lbl_PecadosFamilia->setObjectName(QString::fromUtf8("lbl_PecadosFamilia"));
        lbl_PecadosFamilia->setGeometry(QRect(40, 360, 121, 16));
        lbl_PecadosFamilia->setFont(font2);
        lbl_BuenasAcciones = new QLabel(centralwidget);
        lbl_BuenasAcciones->setObjectName(QString::fromUtf8("lbl_BuenasAcciones"));
        lbl_BuenasAcciones->setGeometry(QRect(320, 370, 181, 16));
        lbl_BuenasAcciones->setFont(font2);
        txt_BuenasAccionesFamiliaHumanoBuscado = new QTextBrowser(centralwidget);
        txt_BuenasAccionesFamiliaHumanoBuscado->setObjectName(QString::fromUtf8("txt_BuenasAccionesFamiliaHumanoBuscado"));
        txt_BuenasAccionesFamiliaHumanoBuscado->setGeometry(QRect(320, 390, 261, 191));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(590, 230, 491, 351));
        btn_Top10PaisesMasPecadores = new QPushButton(groupBox);
        btn_Top10PaisesMasPecadores->setObjectName(QString::fromUtf8("btn_Top10PaisesMasPecadores"));
        btn_Top10PaisesMasPecadores->setGeometry(QRect(0, 20, 191, 25));
        btn_Top5PaisesMenosPecadores = new QPushButton(groupBox);
        btn_Top5PaisesMenosPecadores->setObjectName(QString::fromUtf8("btn_Top5PaisesMenosPecadores"));
        btn_Top5PaisesMenosPecadores->setGeometry(QRect(210, 20, 191, 25));
        btn_Top10PaisesConMasBuenasAcciones = new QPushButton(groupBox);
        btn_Top10PaisesConMasBuenasAcciones->setObjectName(QString::fromUtf8("btn_Top10PaisesConMasBuenasAcciones"));
        btn_Top10PaisesConMasBuenasAcciones->setGeometry(QRect(0, 50, 251, 25));
        btn_Top5PaisesMenosBuenos = new QPushButton(groupBox);
        btn_Top5PaisesMenosBuenos->setObjectName(QString::fromUtf8("btn_Top5PaisesMenosBuenos"));
        btn_Top5PaisesMenosBuenos->setGeometry(QRect(270, 50, 191, 25));
        txt_ConsultasPorPaises = new QTextBrowser(groupBox);
        txt_ConsultasPorPaises->setObjectName(QString::fromUtf8("txt_ConsultasPorPaises"));
        txt_ConsultasPorPaises->setGeometry(QRect(20, 90, 451, 231));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1278, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_GenerarHumanos->setText(QCoreApplication::translate("MainWindow", "Generar Humanos", nullptr));
        lbl_IngreseCantidadHumanos->setText(QCoreApplication::translate("MainWindow", "Ingrese Cantidad de Humanos:", nullptr));
        btn_Pecar->setText(QCoreApplication::translate("MainWindow", "Pecar", nullptr));
        btn_BuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Buenas Acciones", nullptr));
        lbl_IDHumanosBuscado->setText(QCoreApplication::translate("MainWindow", "Ingrese ID del Humano a buscar:", nullptr));
        btn_BuscarHumano->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        lbl_PecadosFamilia->setText(QCoreApplication::translate("MainWindow", "Pecados de Familia", nullptr));
        lbl_BuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Buenas Acciones de Familia", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Consultas Por Paises", nullptr));
        btn_Top10PaisesMasPecadores->setText(QCoreApplication::translate("MainWindow", "Top 10 Paises M\303\241s Pecadores", nullptr));
        btn_Top5PaisesMenosPecadores->setText(QCoreApplication::translate("MainWindow", "Top 5 Paises Menos Pecadores", nullptr));
        btn_Top10PaisesConMasBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Top 10 Paises Con M\303\241s Buenas Acciones", nullptr));
        btn_Top5PaisesMenosBuenos->setText(QCoreApplication::translate("MainWindow", "Top 5 Paises Menos Buenos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
