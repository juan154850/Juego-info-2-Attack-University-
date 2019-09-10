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
    //scene->addPixmap(QPixmap(":/imagenes/agujero.png"));

    jugador = new personaje(0,0,50,55,100,100);
    jugador->setPixmap(QPixmap(":/imagenes/personaje1.png"));
    //jugador->setPos(jugador->getPosx(),jugador->getPosy());
    //jugador->setPos(-720,250);
    //scene->setFocusItem(jugador);
    scene->addItem(jugador);
}

nivel1::~nivel1()
{
    delete ui;
}

void nivel1::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key()==Qt::Key_A)
    {
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverIzquierda();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());
    }
    else if (ev->key()==Qt::Key_D)
    {
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverDerecha();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());
    }
    else if(ev->key()==Qt::Key_W)
    {
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverArriba();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());
    }
    else if (ev->key()==Qt::Key_S)
    {
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverAbajo();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());
    }
}
