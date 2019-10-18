/********************************************************************************
** Form generated from reading UI file 'nivel1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL1_H
#define UI_NIVEL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
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
            nivel1->setObjectName(QStringLiteral("nivel1"));
        nivel1->resize(800, 600);
        nivel1->setMinimumSize(QSize(800, 600));
        nivel1->setMaximumSize(QSize(800, 600));
        graphicsView = new QGraphicsView(nivel1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        graphicsView->setStyleSheet(QStringLiteral(""));
        vidaJugador = new QProgressBar(nivel1);
        vidaJugador->setObjectName(QStringLiteral("vidaJugador"));
        vidaJugador->setEnabled(true);
        vidaJugador->setGeometry(QRect(0, 0, 171, 31));
        vidaJugador->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        vidaJugador->setTextVisible(false);
        lcdNumber_3 = new QLCDNumber(nivel1);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(500, 0, 64, 23));
        vida_boss = new QProgressBar(nivel1);
        vida_boss->setObjectName(QStringLiteral("vida_boss"));
        vida_boss->setGeometry(QRect(630, 0, 171, 31));
        vida_boss->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(500);
        vida_boss->setValue(500);
        vida_boss->setTextVisible(false);
        label = new QLabel(nivel1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        label_2 = new QLabel(nivel1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(650, 10, 47, 13));
        splitter = new QSplitter(nivel1);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(300, 150, 211, 211));
        splitter->setOrientation(Qt::Vertical);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        GUARDAPARTIDA = new QPushButton(splitter);
        GUARDAPARTIDA->setObjectName(QStringLiteral("GUARDAPARTIDA"));
        GUARDAPARTIDA->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/GUARDAR.png);"));
        splitter->addWidget(GUARDAPARTIDA);
        ARDUINO = new QPushButton(splitter);
        ARDUINO->setObjectName(QStringLiteral("ARDUINO"));
        ARDUINO->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/ARDUINO.png);"));
        splitter->addWidget(ARDUINO);
        SALIR = new QPushButton(splitter);
        SALIR->setObjectName(QStringLiteral("SALIR"));
        SALIR->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/SALIR.png);"));
        splitter->addWidget(SALIR);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/SALIR DEL JUEGO.png);"));
        splitter->addWidget(pushButton);

        retranslateUi(nivel1);

        QMetaObject::connectSlotsByName(nivel1);
    } // setupUi

    void retranslateUi(QWidget *nivel1)
    {
        nivel1->setWindowTitle(QApplication::translate("nivel1", "ATTACK UNIVERSITY", Q_NULLPTR));
        vidaJugador->setFormat(QApplication::translate("nivel1", "%p", Q_NULLPTR));
        vida_boss->setFormat(QApplication::translate("nivel1", "%p", Q_NULLPTR));
        label->setText(QApplication::translate("nivel1", "VIDA", Q_NULLPTR));
        label_2->setText(QApplication::translate("nivel1", "VIDA BOSS", Q_NULLPTR));
        GUARDAPARTIDA->setText(QString());
        ARDUINO->setText(QString());
        SALIR->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class nivel1: public Ui_nivel1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL1_H
