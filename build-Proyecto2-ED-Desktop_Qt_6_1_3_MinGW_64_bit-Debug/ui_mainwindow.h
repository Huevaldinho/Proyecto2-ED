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
        txt_PecadosFamiliaHumanoBuscado->setGeometry(QRect(30, 390, 256, 192));
        lbl_PecadosFamilia = new QLabel(centralwidget);
        lbl_PecadosFamilia->setObjectName(QString::fromUtf8("lbl_PecadosFamilia"));
        lbl_PecadosFamilia->setGeometry(QRect(40, 360, 121, 16));
        lbl_PecadosFamilia->setFont(font2);
        lbl_BuenasAcciones = new QLabel(centralwidget);
        lbl_BuenasAcciones->setObjectName(QString::fromUtf8("lbl_BuenasAcciones"));
        lbl_BuenasAcciones->setGeometry(QRect(320, 360, 181, 16));
        lbl_BuenasAcciones->setFont(font2);
        txt_BuenasAccionesFamiliaHumanoBuscado = new QTextBrowser(centralwidget);
        txt_BuenasAccionesFamiliaHumanoBuscado->setObjectName(QString::fromUtf8("txt_BuenasAccionesFamiliaHumanoBuscado"));
        txt_BuenasAccionesFamiliaHumanoBuscado->setGeometry(QRect(310, 390, 256, 192));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
