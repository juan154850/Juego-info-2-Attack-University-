#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{

    nivel1 *comenzarJuego = new nivel1();
    comenzarJuego->show();
    close();
}
