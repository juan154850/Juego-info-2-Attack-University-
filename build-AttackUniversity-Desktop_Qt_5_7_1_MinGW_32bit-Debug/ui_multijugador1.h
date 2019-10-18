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
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_multijugador1
{
public:
    QGraphicsView *graphicsView;
    QProgressBar *vidaJugador;
    QProgressBar *vidaJugador2;
    QProgressBar *vida_boss;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSplitter *splitter;
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
        vidaJugador->setTextVisible(false);
        vidaJugador->setTextDirection(QProgressBar::TopToBottom);
        vidaJugador2 = new QProgressBar(multijugador1);
        vidaJugador2->setObjectName(QStringLiteral("vidaJugador2"));
        vidaJugador2->setGeometry(QRect(260, 0, 171, 31));
        vidaJugador2->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador2->setMaximum(100);
        vidaJugador2->setValue(100);
        vidaJugador2->setTextVisible(false);
        vida_boss = new QProgressBar(multijugador1);
        vida_boss->setObjectName(QStringLiteral("vida_boss"));
        vida_boss->setGeometry(QRect(600, 0, 171, 31));
        vida_boss->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(100);
        vida_boss->setValue(100);
        vida_boss->setTextVisible(false);
        label = new QLabel(multijugador1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 71, 16));
        label_2 = new QLabel(multijugador1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 10, 81, 16));
        label_3 = new QLabel(multijugador1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 10, 141, 16));
        splitter = new QSplitter(multijugador1);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(330, 200, 171, 171));
        splitter->setOrientation(Qt::Vertical);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        SALIR = new QPushButton(splitter);
        SALIR->setObjectName(QStringLiteral("SALIR"));
        SALIR->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/SALIR.png);"));
        splitter->addWidget(SALIR);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/SALIR DEL JUEGO.png);"));
        splitter->addWidget(pushButton);

        retranslateUi(multijugador1);

        QMetaObject::connectSlotsByName(multijugador1);
    } // setupUi

    void retranslateUi(QDialog *multijugador1)
    {
        multijugador1->setWindowTitle(QApplication::translate("multijugador1", "Dialog", Q_NULLPTR));
        vidaJugador->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        vidaJugador2->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        vida_boss->setFormat(QApplication::translate("multijugador1", "%p", Q_NULLPTR));
        label->setText(QApplication::translate("multijugador1", "JUGADOR 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("multijugador1", "JUGADOR 2", Q_NULLPTR));
        label_3->setText(QApplication::translate("multijugador1", "JEFE NIVEL FINAL", Q_NULLPTR));
        SALIR->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class multijugador1: public Ui_multijugador1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR1_H
