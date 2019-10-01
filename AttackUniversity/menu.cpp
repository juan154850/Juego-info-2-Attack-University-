#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->uss->setVisible(false);
    ui->pass->setVisible(false);
}

menu::~menu()
{
    delete ui;
}


void menu::on_iniciar_clicked()
{
    //nos pide iniciar sesion
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->iniciar->setVisible(false);
    ui->registro->setVisible(false);
}

void menu::on_registro_clicked()
{
    //nos despliega el menu para crear la cuenta
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->iniciar->setVisible(false);
    ui->registro->setVisible(false);
}
