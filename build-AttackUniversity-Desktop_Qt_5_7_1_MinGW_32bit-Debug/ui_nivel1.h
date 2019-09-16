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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nivel1
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *nivel1)
    {
        if (nivel1->objectName().isEmpty())
            nivel1->setObjectName(QStringLiteral("nivel1"));
        nivel1->resize(800, 600);
        nivel1->setMaximumSize(QSize(800, 600));
        graphicsView = new QGraphicsView(nivel1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 256, 192));
        graphicsView->setStyleSheet(QStringLiteral(""));

        retranslateUi(nivel1);

        QMetaObject::connectSlotsByName(nivel1);
    } // setupUi

    void retranslateUi(QWidget *nivel1)
    {
        nivel1->setWindowTitle(QApplication::translate("nivel1", "ATTACK UNIVERSITY", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nivel1: public Ui_nivel1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL1_H
