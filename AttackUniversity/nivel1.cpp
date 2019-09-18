#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

    //-------------------zona de eventos-------------------

    scene = new QGraphicsScene();    
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fond.png")));
    scene->setSceneRect(0,0,800,600); //definimos el 0,0 de la escena

    //-------------------graficador-------------------

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);



    //-------------------bloqueos-------------------

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //-------------------player-------------------

    jugador = new personaje(50,525,50,55,100,100);
    //jugador->setFocus();
    scene->addItem(jugador);
    scene->setFocusItem(jugador);

    //-------------------timers-------------------

    tiempo = new QTimer(this);
    tiempo->start(100);
    connect(tiempo, &QTimer::timeout, this, &nivel1::actualizar);


    //-------------------foco-------------------
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
        dire = 'A';
        jugador->animacionIzquierda();
        jugador->moverIzquierda(0.04);
        break;
    }
    case (Qt::Key_D):
    {        
        dire = 'D';
        jugador->animacionDerecha();
        jugador->moverDerecha(0.04);
        break;
    }
    case (Qt::Key_W):
    {        
        dire = 'W';
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
        dire = 'S';
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
    case (Qt::Key_Space):
    {
        //-------------------creacion de balas-------------------
        balas.append(new bala(jugador->getPosx(),jugador->getPosy()+30,20,20,dire));
        scene->addItem(balas.last());
        break;
    }
    }
}

void nivel1::actualizar()
{

    ui->lcdNumber->display(jugador->pos().x());
    ui->lcdNumber_2->display(jugador->pos().y());
    for ( int i  = 0 ; i< balas.size();i++)
    {
        if ( balas.at(i)->getPosy()<=-678)
        {
            scene->removeItem(balas.at(i));
            balas.removeAt(i);
            //delete balas.at(i);
        }
        else
        {
            balas.at(i)->moverBala();
        }
    }
}
