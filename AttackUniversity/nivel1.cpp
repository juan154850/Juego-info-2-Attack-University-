#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //creamos la escena
    scene = new QGraphicsScene();    
    scene->setSceneRect(0,0,800,600);
    //ponemos nuestra escena en el graphicsView
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);
    //bloqueamos el aumentar y disminuir tamaño de la ventana
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    
    //scene->addPixmap(QPixmap(":/imagenes/agujero.png"));
    jugador = new personaje(0,0,50,55,100,100);
    scene->addItem(jugador);
    scene->setFocusItem(jugador);
    qreal posx = 0;
    qreal posy= 400;
    jugador->setPosx(posx);
    jugador->setPosy(posy);
    jugador->setPos(posx,posy);
    tiempo = new QTimer(this);
    tiempo->start(100);
    connect(tiempo, &QTimer::timeout, this, &nivel1::actualizar);

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
            jugador->moverIzquierda(0.1);
            //jugador->setPos(jugador->getPosx(),jugador->getPosy());
            jugador->advance(10);

    }
    else if (ev->key()==Qt::Key_D)
    {       
            ui->lcdNumber->display(jugador->getPosx());
            ui->lcdNumber_2->display(jugador->getPosy());
            jugador->moverDerecha(0.1);
            jugador->advance(10);
          //  jugador->setPos(jugador->getPosx(),jugador->getPosy());

    }
    else if(ev->key()==Qt::Key_W)
    {
        ev->ignore();/*
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverArriba();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());*/
    }
    else if (ev->key()==Qt::Key_S)
    {
        ev->ignore();/*
        ui->lcdNumber->display(jugador->getPosx());
        ui->lcdNumber_2->display(jugador->getPosy());
        jugador->moverAbajo();
        jugador->setPos(jugador->getPosx(),jugador->getPosy());*/
    }
}

void nivel1::actualizar()
{
    jugador->moverDerecha(0.1);
}
