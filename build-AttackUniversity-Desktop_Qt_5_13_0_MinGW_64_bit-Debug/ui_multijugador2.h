/********************************************************************************
** Form generated from reading UI file 'multijugador2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIJUGADOR2_H
#define UI_MULTIJUGADOR2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_multijugador2
{
public:
    QGraphicsView *graphicsView;
    QProgressBar *vidaJugador;
    QProgressBar *vidaJugador2;
    QProgressBar *vida_boss;
    QPushButton *SALIR;
    QPushButton *pushButton;

    void setupUi(QDialog *multijugador2)
    {
        if (multijugador2->objectName().isEmpty())
            multijugador2->setObjectName(QString::fromUtf8("multijugador2"));
        multijugador2->resize(800, 600);
        graphicsView = new QGraphicsView(multijugador2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        vidaJugador = new QProgressBar(multijugador2);
        vidaJugador->setObjectName(QString::fromUtf8("vidaJugador"));
        vidaJugador->setGeometry(QRect(0, 0, 171, 31));
        vidaJugador->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        vidaJugador2 = new QProgressBar(multijugador2);
        vidaJugador2->setObjectName(QString::fromUtf8("vidaJugador2"));
        vidaJugador2->setGeometry(QRect(260, 0, 171, 31));
        vidaJugador2->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador2->setMaximum(100);
        vidaJugador2->setValue(100);
        vida_boss = new QProgressBar(multijugador2);
        vida_boss->setObjectName(QString::fromUtf8("vida_boss"));
        vida_boss->setGeometry(QRect(600, 0, 171, 31));
        vida_boss->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(100);
        vida_boss->setValue(100);
        SALIR = new QPushButton(multijugador2);
        SALIR->setObjectName(QString::fromUtf8("SALIR"));
        SALIR->setGeometry(QRect(360, 440, 151, 24));
        pushButton = new QPushButton(multijugador2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 469, 151, 24));

        retranslateUi(multijugador2);

        QMetaObject::connectSlotsByName(multijugador2);
    } // setupUi

    void retranslateUi(QDialog *multijugador2)
    {
        multijugador2->setWindowTitle(QCoreApplication::translate("multijugador2", "Dialog", nullptr));
        vidaJugador->setFormat(QCoreApplication::translate("multijugador2", "%p", nullptr));
        vidaJugador2->setFormat(QCoreApplication::translate("multijugador2", "%p", nullptr));
        vida_boss->setFormat(QCoreApplication::translate("multijugador2", "%p", nullptr));
        SALIR->setText(QCoreApplication::translate("multijugador2", "SALIR", nullptr));
        pushButton->setText(QCoreApplication::translate("multijugador2", "SALIR DEL JUEGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class multijugador2: public Ui_multijugador2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR2_H
