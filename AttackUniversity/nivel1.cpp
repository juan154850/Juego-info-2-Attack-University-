#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //creamos la escena

    scene = new QGraphicsScene();    
    scene->setSceneRect(0,0,800,600); //definimos el 0,0 de la escena

    //le asignamos al graphicsView el tamaño de nuestro juego
    //ponemos nuestra escena en el graphicsView

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);
    scene->update();



    //bloqueamos el aumentar y disminuir tamaño de la ventana

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //creamos un jugador, lo añadimos a la scena y lo ponemos como foco del juego.

    jugador = new personaje(0,400,50,55,100,100);
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
        if(jugador->getPosx()>=jugador->getWidth()-30)
        {
            jugador->moverIzquierda(0.1);
       }
        else
        {
            ev->ignore();
        }

    }
    else if (ev->key()==Qt::Key_D)
    {       if(jugador->getPosx()<=800-jugador->getWidth()-15)
        {
            jugador->moverDerecha(0.1);            
        }
        else
        {
            ev->ignore();
        }
    }
    else if(ev->key()==Qt::Key_W)
    {        
        if(jugador->getPosy()>=10)
        {
            jugador->moverArriba(0.1);
        }
        else
        {
            ev->ignore();
        }

    }
    else if (ev->key()==Qt::Key_S)
    {
        if(jugador->getPosy()<=540)
        {
            jugador->moverAbajo(0.1);
        }
        else
        {
            ev->ignore();
        }

    }
}

void nivel1::actualizar()
{
    ui->lcdNumber->display(jugador->getPosx());
    ui->lcdNumber_2->display(jugador->getPosy());
}
