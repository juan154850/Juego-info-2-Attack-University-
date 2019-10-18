/********************************************************************************
** Form generated from reading UI file 'ganar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANAR_H
#define UI_GANAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
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
            Ganar->setObjectName(QStringLiteral("Ganar"));
        Ganar->resize(600, 600);
        graphicsView = new QGraphicsView(Ganar);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        splitter = new QSplitter(Ganar);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(130, 540, 331, 51));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        volver_a_jugar = new QPushButton(splitter);
        volver_a_jugar->setObjectName(QStringLiteral("volver_a_jugar"));
        volver_a_jugar->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/VOLVER A JUGAR.png);"));
        splitter->addWidget(volver_a_jugar);
        siguiente_nivel = new QPushButton(splitter);
        siguiente_nivel->setObjectName(QStringLiteral("siguiente_nivel"));
        siguiente_nivel->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/NEXT LVL.png);"));
        splitter->addWidget(siguiente_nivel);
        salir_del_juego = new QPushButton(splitter);
        salir_del_juego->setObjectName(QStringLiteral("salir_del_juego"));
        salir_del_juego->setEnabled(true);
        QFont font;
        font.setKerning(true);
        salir_del_juego->setFont(font);
        salir_del_juego->setStyleSheet(QStringLiteral("border-image: url(:/imagenes2/SALIR DEL JUEGO.png);"));
        splitter->addWidget(salir_del_juego);

        retranslateUi(Ganar);

        QMetaObject::connectSlotsByName(Ganar);
    } // setupUi

    void retranslateUi(QDialog *Ganar)
    {
        Ganar->setWindowTitle(QApplication::translate("Ganar", "Dialog", Q_NULLPTR));
        volver_a_jugar->setText(QString());
        siguiente_nivel->setText(QString());
        salir_del_juego->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ganar: public Ui_Ganar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANAR_H
