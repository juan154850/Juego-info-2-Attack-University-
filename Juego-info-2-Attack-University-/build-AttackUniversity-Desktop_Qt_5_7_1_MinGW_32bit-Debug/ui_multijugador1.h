/********************************************************************************
** Form generated from reading UI file 'multijugador1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIJUGADOR1_H
#define UI_MULTIJUGADOR1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_multijugador1
{
public:
    QGraphicsView *graphicsView;
    QProgressBar *vidaJugador;
    QProgressBar *vidaJugador2;
    QProgressBar *vida_boss;
    QPushButton *SALIR;
    QPushButton *pushButton;

    void setupUi(QDialog *multijugador1)
    {
        if (multijugador1->objectName().isEmpty())
            multijugador1->setObjectName(QStringLiteral("multijugador1"));
        multijugador1->resize(800, 600);
        graphicsView = new QGraphicsView(multijugador1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        vidaJugador = new QProgressBar(multijugador1);
        vidaJugador->setObjectName(QStringLiteral("vidaJugador"));
        vidaJugador->setGeometry(QRect(0, 0, 171, 31));
        vidaJugador->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        vidaJugador2 = new QProgressBar(multijugador1);
        vidaJugador2->setObjectName(QStringLiteral("vidaJugador2"));
        vidaJugador2->setGeometry(QRect(260, 0, 171, 31));
        vidaJugador2->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador2->setMaximum(100);
        vidaJugador2->setValue(100);
        vida_boss = new QProgressBar(multijugador1);
        vida_boss->setObjectName(QStringLiteral("vida_boss"));
        vida_boss->setGeometry(QRect(600, 0, 171, 31));
        vida_boss->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(100);
        vida_boss->setValue(100);
        SALIR = new QPushButton(multijugador1);
        SALIR->setObjectName(QStringLiteral("SALIR"));
        SALIR->setGeometry(QRect(360, 440, 151, 24));
        pushButton = new QPushButton(multijugador1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 469, 151, 24));

        retranslateUi(multijugador1);

        QMetaObject::connectSlotsByName(multijugador1);
    } // setupUi

    void retranslateUi(QDialog *multijugador1)
    {
        multijugador1->setWindowTitle(QApplication::translate("multijugador1", "Dialog", Q_NULLPTR));
        vidaJugador->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        vidaJugador2->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        vida_boss->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        SALIR->setText(QApplication::translate("multijugador1", "SALIR", Q_NULLPTR));
        pushButton->setText(QApplication::translate("multijugador1", "SALIR DEL JUEGO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class multijugador1: public Ui_multijugador1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR1_H
