#-------------------------------------------------
#
# Project created by QtCreator 2019-08-24T21:53:52
#
#-------------------------------------------------

QT       += core gui serialport
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AttackUniversity
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    multijugador2.cpp \
    nivel2.cpp \
    personaje.cpp \
    nivel1.cpp \
    menu.cpp \
    bala.cpp \
    soldado.cpp \
    arabe.cpp \
    boss1.cpp \
    obstaculos.cpp \
    ganar.cpp \
    multijugador1.cpp

HEADERS += \
    multijugador2.h \
    nivel2.h \
    personaje.h \
    nivel1.h \
    menu.h \
    bala.h \
    soldado.h \
    arabe.h \
    boss1.h \
    obstaculos.h \
    ganar.h \
    multijugador1.h

FORMS += \
    multijugador2.ui \
    nivel1.ui \
    menu.ui \
    ganar.ui \
    multijugador1.ui \
    nivel2.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    imagenes/agujero.png

RESOURCES += \
    archivos.qrc \
    archivos2.qrc


RC_ICONS = icono.ico

