/********************************************************************************
** Form generated from reading UI file 'nivel2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL2_H
#define UI_NIVEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
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
            nivel2->setObjectName(QStringLiteral("nivel2"));
        nivel2->resize(800, 600);
        graphicsView = new QGraphicsView(nivel2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        label = new QLabel(nivel2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 47, 13));
        label_2 = new QLabel(nivel2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1400, 100, 47, 13));
        vidaJugador = new QProgressBar(nivel2);
        vidaJugador->setObjectName(QStringLiteral("vidaJugador"));
        vidaJugador->setGeometry(QRect(10, 20, 171, 31));
        vidaJugador->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vidaJugador->setMaximum(100);
        vidaJugador->setValue(100);
        vida_boss = new QProgressBar(nivel2);
        vida_boss->setObjectName(QStringLiteral("vida_boss"));
        vida_boss->setGeometry(QRect(1380, 90, 171, 31));
        vida_boss->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(170, 0, 0);"));
        vida_boss->setMaximum(500);
        vida_boss->setValue(500);
        splitter = new QSplitter(nivel2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(990, 360, 151, 111));
        splitter->setOrientation(Qt::Vertical);
        GUARDAPARTIDA = new QPushButton(splitter);
        GUARDAPARTIDA->setObjectName(QStringLiteral("GUARDAPARTIDA"));
        splitter->addWidget(GUARDAPARTIDA);
        ARDUINO = new QPushButton(splitter);
        ARDUINO->setObjectName(QStringLiteral("ARDUINO"));
        splitter->addWidget(ARDUINO);
        SALIR = new QPushButton(splitter);
        SALIR->setObjectName(QStringLiteral("SALIR"));
        splitter->addWidget(SALIR);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        lcdNumber_3 = new QLCDNumber(nivel2);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(1250, 90, 64, 23));

        retranslateUi(nivel2);

        QMetaObject::connectSlotsByName(nivel2);
    } // setupUi

    void retranslateUi(QDialog *nivel2)
    {
        nivel2->setWindowTitle(QApplication::translate("nivel2", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("nivel2", "PLAYER", Q_NULLPTR));
        label_2->setText(QApplication::translate("nivel2", "BOSS", Q_NULLPTR));
        vidaJugador->setFormat(QApplication::translate("nivel2", "%p", Q_NULLPTR));
        vida_boss->setFormat(QApplication::translate("nivel2", "%p", Q_NULLPTR));
        GUARDAPARTIDA->setText(QApplication::translate("nivel2", "GUARDAR PARTIDA", Q_NULLPTR));
        ARDUINO->setText(QApplication::translate("nivel2", "CONECTAR ARDUINO", Q_NULLPTR));
        SALIR->setText(QApplication::translate("nivel2", "SALIR", Q_NULLPTR));
        pushButton->setText(QApplication::translate("nivel2", "SALIR DEL JUEGO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nivel2: public Ui_nivel2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL2_H