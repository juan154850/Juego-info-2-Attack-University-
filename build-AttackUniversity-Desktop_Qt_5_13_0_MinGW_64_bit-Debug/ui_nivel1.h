/********************************************************************************
** Form generated from reading UI file 'nivel1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL1_H
#define UI_NIVEL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nivel1
{
public:
    QGraphicsView *graphicsView;
    QProgressBar *vidaJugador;
    QLCDNumber *lcdNumber_3;
    QProgressBar *vida_boss;
    QLabel *label;
    QLabel *label_2;
    QSplitter *splitter;
    QPushButton *GUARDAPARTIDA;
    QPushButton *ARDUINO;
    QPushButton *SALIR;
    QPushButton *pushButton;

    void setupUi(QWidget *nivel1)
    {
        if (nivel1->objectName().isEmpty())
            nivel1->setObjectName(QString::fromUtf8("nivel1"));
        nivel1->resize(800, 600);
        nivel1->setMinimumSize(QSize(800, 600));
        nivel1->setMaximumSize(QSize(800, 600));
        graphicsView = new QGraphicsView(nivel1);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        vidaJugador = new QProgressBar(nivel1);
        vidaJugador->setObjectName(QString::fromUtf8("vidaJugador"));
        vidaJugador->setGeometry(QRect(0, 0, 171, 31));
        vidaJugador->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        lcdNumber_3 = new QLCDNumber(nivel1);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(500, 0, 64, 23));
        vida_boss = new QProgressBar(nivel1);
        vida_boss->setObjectName(QString::fromUtf8("vida_boss"));
        vida_boss->setGeometry(QRect(630, 0, 171, 31));
        vida_boss->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(500);
        vida_boss->setValue(500);
        label = new QLabel(nivel1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        label_2 = new QLabel(nivel1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 10, 47, 13));
        splitter = new QSplitter(nivel1);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(240, 270, 151, 111));
        splitter->setOrientation(Qt::Vertical);
        GUARDAPARTIDA = new QPushButton(splitter);
        GUARDAPARTIDA->setObjectName(QString::fromUtf8("GUARDAPARTIDA"));
        splitter->addWidget(GUARDAPARTIDA);
        ARDUINO = new QPushButton(splitter);
        ARDUINO->setObjectName(QString::fromUtf8("ARDUINO"));
        splitter->addWidget(ARDUINO);
        SALIR = new QPushButton(splitter);
        SALIR->setObjectName(QString::fromUtf8("SALIR"));
        splitter->addWidget(SALIR);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);

        retranslateUi(nivel1);

        QMetaObject::connectSlotsByName(nivel1);
    } // setupUi

    void retranslateUi(QWidget *nivel1)
    {
        nivel1->setWindowTitle(QCoreApplication::translate("nivel1", "ATTACK UNIVERSITY", nullptr));
        vidaJugador->setFormat(QCoreApplication::translate("nivel1", "%p", nullptr));
        vida_boss->setFormat(QCoreApplication::translate("nivel1", "%p", nullptr));
        label->setText(QCoreApplication::translate("nivel1", "PLAYER", nullptr));
        label_2->setText(QCoreApplication::translate("nivel1", "BOSS", nullptr));
        GUARDAPARTIDA->setText(QCoreApplication::translate("nivel1", "GUARDAR PARTIDA", nullptr));
        ARDUINO->setText(QCoreApplication::translate("nivel1", "CONECTAR ARDUINO", nullptr));
        SALIR->setText(QCoreApplication::translate("nivel1", "SALIR", nullptr));
        pushButton->setText(QCoreApplication::translate("nivel1", "SALIR DEL JUEGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nivel1: public Ui_nivel1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL1_H
