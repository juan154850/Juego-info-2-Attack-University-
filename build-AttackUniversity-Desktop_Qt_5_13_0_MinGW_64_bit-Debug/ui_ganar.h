/********************************************************************************
** Form generated from reading UI file 'ganar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANAR_H
#define UI_GANAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Ganar
{
public:
    QGraphicsView *graphicsView;
    QSplitter *splitter;
    QPushButton *volver_a_jugar;
    QPushButton *siguiente_nivel;
    QPushButton *salir_del_juego;

    void setupUi(QDialog *Ganar)
    {
        if (Ganar->objectName().isEmpty())
            Ganar->setObjectName(QString::fromUtf8("Ganar"));
        Ganar->resize(600, 600);
        graphicsView = new QGraphicsView(Ganar);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        splitter = new QSplitter(Ganar);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(130, 540, 331, 51));
        splitter->setOrientation(Qt::Horizontal);
        volver_a_jugar = new QPushButton(splitter);
        volver_a_jugar->setObjectName(QString::fromUtf8("volver_a_jugar"));
        splitter->addWidget(volver_a_jugar);
        siguiente_nivel = new QPushButton(splitter);
        siguiente_nivel->setObjectName(QString::fromUtf8("siguiente_nivel"));
        siguiente_nivel->setStyleSheet(QString::fromUtf8("image: url(:/imagenes/cooltext335629468732690.png);"));
        splitter->addWidget(siguiente_nivel);
        salir_del_juego = new QPushButton(splitter);
        salir_del_juego->setObjectName(QString::fromUtf8("salir_del_juego"));
        salir_del_juego->setStyleSheet(QString::fromUtf8(""));
        splitter->addWidget(salir_del_juego);

        retranslateUi(Ganar);

        QMetaObject::connectSlotsByName(Ganar);
    } // setupUi

    void retranslateUi(QDialog *Ganar)
    {
        Ganar->setWindowTitle(QCoreApplication::translate("Ganar", "Dialog", nullptr));
        volver_a_jugar->setText(QCoreApplication::translate("Ganar", "VOLVER A JUGAR", nullptr));
        siguiente_nivel->setText(QCoreApplication::translate("Ganar", "SIGUIENTE NIVEL", nullptr));
        salir_del_juego->setText(QCoreApplication::translate("Ganar", "SALIR DEL JUEGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ganar: public Ui_Ganar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANAR_H
