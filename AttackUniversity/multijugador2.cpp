#include "multijugador2.h"
#include "ui_multijugador2.h"
#include <ganar.h>
multijugador2::multijugador2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multijugador2)
{
    ui->setupUi(this);
    nuevaPartida();
}

multijugador2::~multijugador2()
{
    delete ui;
}

void multijugador2::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case(Qt::Key_W):
    {
        dire = 'W';
        jugador->animacionArriba();
        if(!jugador->collidesWithItem(arrib1) && !jugador->collidesWithItem(arrib2)
                && !jugador->collidesWithItem(arrib3) && !jugador->collidesWithItem(arrib1Copia) && !jugador->collidesWithItem(arrib2Copia))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                if(sala == 1 || (sala ==2 && jugador->getPosy()<-1285) || (sala ==3 && jugador->getPosy()<-2480))
                {
                    //para bloquear la camara en el ultimo nivel
                    jugador->moverArriba(0.04);
                }
                else
                {
                    jugador->moverArriba(0.04);
                    scene->setSceneRect(0,jugador->getPosy()-515,800,600);
                }
            }
            else
            {
                ev->ignore();
                break;
            }
        }
        break;
    }
    case(Qt::Key_S):
    {
        dire = 'S';
        jugador->animacionAbajo();
        if(!jugador->collidesWithItem(abaj2) && !jugador->collidesWithItem(abaj1) && !jugador->collidesWithItem(abaj3)
                && !jugador->collidesWithItem(abaj2Copia))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                if(sala == 1 || (sala ==2 && jugador->getPosy()<-1300)|| (sala ==3 && jugador->getPosy()<-2480))
                {
                    jugador->moverAbajo(0.04);
                }
                else
                {
                    jugador->moverAbajo(0.04);
                    scene->setSceneRect(0,jugador->getPosy()-515,800,600);
                }
            }
            else
            {
                ev->ignore();
                break;
            }
        }
        break;
    }
    case(Qt::Key_D):
    {
        dire = 'D';
        jugador->animacionDerecha();
        if(!jugador->collidesWithItem(drch1) && !jugador->collidesWithItem(puenteDrch1) && !jugador->collidesWithItem(puenteDrch2))
        {
            if( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                jugador->moverDerecha(0.04);
            }
            else
            {
                ev->ignore();
                break;
            }
        }
        break;
    }
    case(Qt::Key_A):
    {
        dire = 'A';
        jugador->animacionIzquierda();
        if(!jugador->collidesWithItem(izq1) && !jugador->collidesWithItem(puenteIzq1) && !jugador->collidesWithItem(puenteIzq2))
        {
            if (pausa_==true)
            {
                break;
            }
            else
            {
                if( colision==false)
                {
                    jugador->moverIzquierda(0.04);
                }
                else
                {
                    ev->ignore();
                    break;
                }
            }
        }
        break;
    }
    case (Qt::Key_Space):
    {
        if ( pausa_ == true)
        {
            break;
        }
        else if ( delayDisparar >= 10)
        {
            //-------------------creacion de balas-------------------
            if( dire == 'D')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador->getPosx()+28,jugador->getPosy()+27,20,20,dire));
                scene->addItem(balasJugador.last());
                delayDisparar=0;
            }
            else if ( dire == 'A')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador->getPosx(),jugador->getPosy()+27,20,20,dire));
                scene->addItem(balasJugador.last());
                delayDisparar=0;
            }
            else if( dire == 'W')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador->getPosx()+28,jugador->getPosy()+0,20,20,dire));
                scene->addItem(balasJugador.last());
                delayDisparar=0;
            }
            else if( dire == 'S')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador->getPosx()+10,jugador->getPosy()+27,20,20,dire));
                scene->addItem(balasJugador.last());
                delayDisparar=0;
            }
        }
        break;
    }
    case(Qt::Key_P):
    {
        //parar todos los timers
        pausa();
        break;
    }
    }
}
