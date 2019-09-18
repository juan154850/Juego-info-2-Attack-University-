#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //creamos la escena

    scene = new QGraphicsScene();    
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fond.png")));
    scene->setSceneRect(0,0,800,600); //definimos el 0,0 de la escena

    //le asignamos al graphicsView el tamaño de nuestro juego y ponemos nuestra escena en el graphicsView

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);



    //bloqueamos el aumentar y disminuir tamaño de la ventana

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //creamos un jugador, lo añadimos a la scena y lo ponemos como foco del juego.

    jugador = new personaje(50,525,50,55,100,100);
    //jugador->setFocus();
    scene->addItem(jugador);
    scene->setFocusItem(jugador);

    //creamos un timer que nos permite saber la posicion en x y en y del jugador en todo momento.

    tiempo = new QTimer(this);
    tiempo->start(100);
    connect(tiempo, &QTimer::timeout, this, &nivel1::actualizar);


    //añadimos una linea para detectarla como colision
//    QGraphicsLineItem *linea;
//    linea = new QGraphicsLineItem;
//    linea->setLine(800,0,0,0);
//    linea->setPen(QColor(Qt::red));
//    linea->setPos(0,-670);
//    scene->addItem(linea);
    scene->setSceneRect(0,jugador->getPosy()-522,800,600);

}

nivel1::~nivel1()
{
    delete ui;
}

void nivel1::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case (Qt::Key_A):
    {
        jugador->animacionIzquierda();
        jugador->moverIzquierda(0.04);
        break;
    }
    case (Qt::Key_D):
    {
        jugador->animacionDerecha();
        jugador->moverDerecha(0.04);
        break;
    }
    case (Qt::Key_W):
    {
        jugador->animacionArriba();
        //bloqueo de la camara
        if(jugador->getPosy()>=-678 && jugador->getPosy()<=520)
        {

            jugador->moverArriba(0.04);
            scene->setSceneRect(0,jugador->getPosy()-522,800,600);
        }
        else
        {
            jugador->moverArriba(0.04);
        }
        break;
    }
    case (Qt::Key_S):
    {
        jugador->animacionAbajo();
        //bloqueo de la camara
        if(jugador->getPosy()>=-678 && jugador->getPosy()<=520)
        {
                jugador->moverAbajo(0.04);
                scene->setSceneRect(0,jugador->getPosy()-522,800,600);
        }
        else
        {
            jugador->moverAbajo(0.04);
        }
        break;


    }
    }
}

void nivel1::actualizar()
{
    ui->lcdNumber->display(jugador->pos().x());
    ui->lcdNumber_2->display(jugador->pos().y());

     if ( jugador->collidingItems().size()>0)
     {
         //si el jugador colisiona con algun elemento...
         ui->lcdNumber->display(666);         
     }
}
