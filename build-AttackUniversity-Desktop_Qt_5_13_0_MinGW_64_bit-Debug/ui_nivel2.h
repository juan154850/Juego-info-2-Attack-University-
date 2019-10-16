/********************************************************************************
** Form generated from reading UI file 'nivel2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL2_H
#define UI_NIVEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_nivel2
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *vidaJugador;
    QProgressBar *vida_boss;
    QSplitter *splitter;
    QPushButton *GUARDAPARTIDA;
    QPushButton *ARDUINO;
    QPushButton *SALIR;
    QPushButton *pushButton;
    QLCDNumber *lcdNumber_3;

    void setupUi(QDialog *nivel2)
    {
        if (nivel2->objectName().isEmpty())
            nivel2->setObjectName(QString::fromUtf8("nivel2"));
        nivel2->resize(800, 600);
        graphicsView = new QGraphicsView(nivel2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        label = new QLabel(nivel2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(770, 100, 47, 13));
        label_2 = new QLabel(nivel2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1400, 100, 47, 13));
        vidaJugador = new QProgressBar(nivel2);
        vidaJugador->setObjectName(QString::fromUtf8("vidaJugador"));
        vidaJugador->setGeometry(QRect(750, 90, 171, 31));
        vidaJugador->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        vida_boss = new QProgressBar(nivel2);
        vida_boss->setObjectName(QString::fromUtf8("vida_boss"));
        vida_boss->setGeometry(QRect(1380, 90, 171, 31));
        vida_boss->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(500);
        vida_boss->setValue(500);
        splitter = new QSplitter(nivel2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(990, 360, 151, 111));
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
        lcdNumber_3 = new QLCDNumber(nivel2);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(1250, 90, 64, 23));

        retranslateUi(nivel2);

        QMetaObject::connectSlotsByName(nivel2);
    } // setupUi

    void retranslateUi(QDialog *nivel2)
    {
        nivel2->setWindowTitle(QCoreApplication::translate("nivel2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("nivel2", "PLAYER", nullptr));
        label_2->setText(QCoreApplication::translate("nivel2", "BOSS", nullptr));
        vidaJugador->setFormat(QCoreApplication::translate("nivel2", "%p", nullptr));
        vida_boss->setFormat(QCoreApplication::translate("nivel2", "%p", nullptr));
        GUARDAPARTIDA->setText(QCoreApplication::translate("nivel2", "GUARDAR PARTIDA", nullptr));
        ARDUINO->setText(QCoreApplication::translate("nivel2", "CONECTAR ARDUINO", nullptr));
        SALIR->setText(QCoreApplication::translate("nivel2", "SALIR", nullptr));
        pushButton->setText(QCoreApplication::translate("nivel2", "SALIR DEL JUEGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nivel2: public Ui_nivel2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL2_H
