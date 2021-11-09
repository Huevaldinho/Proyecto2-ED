QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbolfamilia.cpp \
    arbolmundo.cpp \
    archivos.cpp \
    consultasporacciones.cpp \
    listafamilias.cpp \
    listapaises.cpp \
    listapersonas.cpp \
    main.cpp \
    mainwindow.cpp \
    mundo.cpp \
    nodo.cpp \
    nodoarbol.cpp \
    nodolistafalimias.cpp \
    persona.cpp

HEADERS += \
    Estructuras.h \
    arbolfamilia.h \
    arbolmundo.h \
    archivos.h \
    consultasporacciones.h \
    listafamilias.h \
    listapaises.h \
    listapersonas.h \
    mainwindow.h \
    mundo.h \
    nodo.h \
    nodoarbol.h \
    nodolistafalimias.h \
    pais.h \
    persona.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc
