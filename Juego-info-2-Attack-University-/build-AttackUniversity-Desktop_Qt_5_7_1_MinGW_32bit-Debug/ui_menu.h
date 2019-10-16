/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *iniciar;
    QPushButton *registro;
    QLineEdit *uss;
    QLineEdit *pass;
    QPushButton *iniciar_2;
    QPushButton *registro_2;
    QPushButton *cargarPartida;
    QPushButton *multijugador;
    QPushButton *nuevaPartida;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(500, 280);
        menu->setStyleSheet(QStringLiteral(""));
        iniciar = new QPushButton(menu);
        iniciar->setObjectName(QStringLiteral("iniciar"));
        iniciar->setGeometry(QRect(110, 220, 151, 61));
        iniciar->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629482081336.png);"));
        registro = new QPushButton(menu);
        registro->setObjectName(QStringLiteral("registro"));
        registro->setGeometry(QRect(260, 220, 151, 61));
        registro->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629468732690.png);"));
        uss = new QLineEdit(menu);
        uss->setObjectName(QStringLiteral("uss"));
        uss->setGeometry(QRect(130, 140, 113, 20));
        pass = new QLineEdit(menu);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(280, 140, 113, 20));
        pass->setEchoMode(QLineEdit::Password);
        iniciar_2 = new QPushButton(menu);
        iniciar_2->setObjectName(QStringLiteral("iniciar_2"));
        iniciar_2->setGeometry(QRect(190, 220, 151, 61));
        iniciar_2->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629482081336.png);"));
        registro_2 = new QPushButton(menu);
        registro_2->setObjectName(QStringLiteral("registro_2"));
        registro_2->setGeometry(QRect(180, 210, 151, 61));
        registro_2->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629468732690.png);"));
        cargarPartida = new QPushButton(menu);
        cargarPartida->setObjectName(QStringLiteral("cargarPartida"));
        cargarPartida->setGeometry(QRect(160, 10, 161, 91));
        cargarPartida->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/CARGAR PARTIDA.png);"));
        multijugador = new QPushButton(menu);
        multijugador->setObjectName(QStringLiteral("multijugador"));
        multijugador->setGeometry(QRect(140, 140, 221, 91));
        multijugador->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/MULTIJUGADOR.png);"));
        nuevaPartida = new QPushButton(menu);
        nuevaPartida->setObjectName(QStringLiteral("nuevaPartida"));
        nuevaPartida->setGeometry(QRect(140, 80, 221, 91));
        nuevaPartida->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/NUEVA PARTIDA.png);"));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Dialog", Q_NULLPTR));
        iniciar->setText(QString());
        registro->setText(QString());
        iniciar_2->setText(QString());
        registro_2->setText(QString());
        cargarPartida->setText(QString());
        multijugador->setText(QString());
        nuevaPartida->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
