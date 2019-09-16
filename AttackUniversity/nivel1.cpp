#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //creamos la escena

    scene = new QGraphicsScene();    
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/piso1.png")));
    scene->setSceneRect(0,0,200,600); //definimos el 0,0 de la escena

    //le asignamos al graphicsView el tamaño de nuestro juego
    //ponemos nuestra escena en el graphicsView

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);
    //scene->update();



    //bloqueamos el aumentar y disminuir tamaño de la ventana

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //creamos un jugador, lo añadimos a la scena y lo ponemos como foco del juego.

    jugador = new personaje(0,0,50,55,100,100);
    scene->addItem(jugador);
    scene->setFocusItem(jugador);    

    //creamos un timer que nos permite saber la posicion en x y en y del jugador en todo momento.

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
            jugador->moverIzquierda(0.04);
            scene->setSceneRect(jugador->getPosx(),jugador->getPosy(),200,600);
    }
    else if (ev->key()==Qt::Key_D)
    {
            jugador->moverDerecha(0.04);
            scene->setSceneRect(jugador->getPosx(),jugador->getPosy(),200,600);

    }
    else if(ev->key()==Qt::Key_W)
    {        
            jugador->moverArriba(0.04);
            scene->setSceneRect(jugador->getPosx(),jugador->getPosy(),200,600);

    }
    else if (ev->key()==Qt::Key_S)
    {
            jugador->moverAbajo(0.04);
            scene->setSceneRect(jugador->getPosx(),jugador->getPosy(),200,600);

    }
}

void nivel1::actualizar()
{
}
