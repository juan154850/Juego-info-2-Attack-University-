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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nivel1
{
public:
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber_3;
    QPushButton *GUARDAPARTIDA;
    QPushButton *ARDUINO;
    QPushButton *SALIR;

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
        lcdNumber = new QLCDNumber(nivel1);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(700, 0, 101, 41));
        lcdNumber->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 0);\n"
"font: 28pt \"MS Shell Dlg 2\";"));
        lcdNumber_2 = new QLCDNumber(nivel1);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(700, 40, 101, 41));
        lcdNumber_2->setStyleSheet(QLatin1String("background-color: rgb(85, 255, 0);\n"
"font: 36pt \"MS Shell Dlg 2\";"));
        progressBar = new QProgressBar(nivel1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(350, 0, 118, 23));
        progressBar->setMaximum(100);
        progressBar->setValue(100);
        lcdNumber_3 = new QLCDNumber(nivel1);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(500, 0, 64, 23));
        GUARDAPARTIDA = new QPushButton(nivel1);
        GUARDAPARTIDA->setObjectName(QStringLiteral("GUARDAPARTIDA"));
        GUARDAPARTIDA->setGeometry(QRect(240, 270, 121, 41));
        ARDUINO = new QPushButton(nivel1);
        ARDUINO->setObjectName(QStringLiteral("ARDUINO"));
        ARDUINO->setGeometry(QRect(240, 320, 121, 41));
        SALIR = new QPushButton(nivel1);
        SALIR->setObjectName(QStringLiteral("SALIR"));
        SALIR->setGeometry(QRect(230, 370, 131, 41));

        retranslateUi(nivel1);

        QMetaObject::connectSlotsByName(nivel1);
    } // setupUi

    void retranslateUi(QWidget *nivel1)
    {
        nivel1->setWindowTitle(QApplication::translate("nivel1", "ATTACK UNIVERSITY", Q_NULLPTR));
        progressBar->setFormat(QApplication::translate("nivel1", "%p", Q_NULLPTR));
        GUARDAPARTIDA->setText(QApplication::translate("nivel1", "GUARDAR PARTIDA", Q_NULLPTR));
        ARDUINO->setText(QApplication::translate("nivel1", "CONECTAR ARDUINO", Q_NULLPTR));
        SALIR->setText(QApplication::translate("nivel1", "SALIR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nivel1: public Ui_nivel1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL1_H
