#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //creamos la escena
    scene = new QGraphicsScene();

    //ponemos nuestra escena en el graphicsView
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);
    //bloqueamos el aumentar y disminuir tamaño de la ventana
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addPixmap(QPixmap(":/imagenes/agujero.png"));
}

nivel1::~nivel1()
{
    delete ui;
}
