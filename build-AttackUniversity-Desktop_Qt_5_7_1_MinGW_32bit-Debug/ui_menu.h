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

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(500, 280);
        menu->setStyleSheet(QStringLiteral(""));
        iniciar = new QPushButton(menu);
        iniciar->setObjectName(QStringLiteral("iniciar"));
        iniciar->setGeometry(QRect(110, 190, 151, 61));
        iniciar->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629482081336.png);"));
        registro = new QPushButton(menu);
        registro->setObjectName(QStringLiteral("registro"));
        registro->setGeometry(QRect(260, 190, 151, 61));
        registro->setStyleSheet(QStringLiteral("border-image: url(:/imagenes/cooltext335629468732690.png);"));
        uss = new QLineEdit(menu);
        uss->setObjectName(QStringLiteral("uss"));
        uss->setGeometry(QRect(130, 140, 113, 20));
        pass = new QLineEdit(menu);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(280, 140, 113, 20));
        pass->setEchoMode(QLineEdit::Password);

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Dialog", Q_NULLPTR));
        iniciar->setText(QString());
        registro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
