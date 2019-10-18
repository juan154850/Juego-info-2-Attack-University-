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
                && !jugador->collidesWithItem(arrib3) && !jugador->collidesWithItem(arrib1Copia)
                && !jugador->collidesWithItem(arrib2Copia))
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
    case(Qt::Key_8):
    {
        direP2 = 'W';
        jugador2->animacionArribaP2();
        if(!jugador2->collidesWithItem(arrib1) && !jugador2->collidesWithItem(arrib2)
                && !jugador2->collidesWithItem(arrib3) && !jugador2->collidesWithItem(arrib1Copia)
                && !jugador2->collidesWithItem(arrib2Copia))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                if(sala == 1 || (sala ==2 && jugador2->getPosy()<-1285) || (sala ==3 && jugador2->getPosy()<-2480))
                {
                    //para bloquear la camara en el ultimo nivel
                    jugador2->moverArriba(0.04);
                }
                else
                {
                    jugador2->moverArriba(0.04);
                    //scene->setSceneRect(0,jugador->getPosy()-515,800,600);
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
    case(Qt::Key_5):
    {
        direP2 = 'S';
        jugador2->animacionAbajoP2();
        if(!jugador2->collidesWithItem(abaj2) && !jugador2->collidesWithItem(abaj1) && !jugador2->collidesWithItem(abaj3)
                && !jugador2->collidesWithItem(abaj2Copia))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                if(sala == 1 || (sala ==2 && jugador2->getPosy()<-1300)|| (sala ==3 && jugador2->getPosy()<-2480))
                {
                    jugador2->moverAbajo(0.04);
                }
                else
                {
                    jugador->moverAbajo(0.04);
                    //scene->setSceneRect(0,jugador->getPosy()-515,800,600);
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
    case(Qt::Key_6):
    {
        direP2 = 'D';
        jugador2->animacionDerechaP2();
        if(!jugador2->collidesWithItem(drch1) && !jugador2->collidesWithItem(puenteDrch1) && !jugador2->collidesWithItem(puenteDrch2))
        {
            if( pausa_==true)
            {
                break;
            }
            if( colision==false)
            {
                jugador2->moverDerecha(0.04);
            }
            else
            {
                ev->ignore();
                break;
            }
        }
        break;
    }
    case(Qt::Key_4):
    {
        direP2 = 'A';
        jugador2->animacionIzquierdaP2();
        if(!jugador2->collidesWithItem(izq1) && !jugador2->collidesWithItem(puenteIzq1) && !jugador2->collidesWithItem(puenteIzq2))
        {
            if (pausa_==true)
            {
                break;
            }
            else
            {
                if( colision==false)
                {
                    jugador2->moverIzquierda(0.04);
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
    case (Qt::Key_Control):
    {
        if ( pausa_ == true)
        {
            break;
        }
        else if ( delayDispararP2 >= 10)
        {
            //-------------------creacion de balas-------------------
            if( direP2 == 'D')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador2->getPosx()+28,jugador2->getPosy()+27,20,20,direP2));
                scene->addItem(balasJugador.last());
                delayDispararP2=0;
            }
            else if ( direP2 == 'A')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador2->getPosx(),jugador2->getPosy()+27,20,20,direP2));
                scene->addItem(balasJugador.last());
                delayDispararP2=0;
            }
            else if( direP2 == 'W')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador2->getPosx()+28,jugador2->getPosy()+0,20,20,direP2));
                scene->addItem(balasJugador.last());
                delayDispararP2=0;
            }
            else if( direP2 == 'S')
            {
                efectos->setMedia(QUrl("qrc:/musica/disparar1.mp3"));
                efectos->play();
                balasJugador.append(new bala(jugador2->getPosx()+10,jugador2->getPosy()+27,20,20,direP2));
                scene->addItem(balasJugador.last());
                delayDispararP2=0;
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

void multijugador2::generarBordes()
{
    izq1 =new QGraphicsLineItem(0,3000,0,0);
    izq1->setPos(30,-3000);
    izq1->setPen(QPen(Qt::transparent));
    scene->addItem(izq1);
    obs.push_back(izq1);
    drch1=(new QGraphicsLineItem(0,3000,0,0));
    drch1->setPen(QPen(Qt::transparent));
    drch1->setPos(770,-3000);
    scene->addItem(drch1);
    obs.push_back(drch1);
    abaj1=(new QGraphicsLineItem(800,0,0,0));
    abaj1->setPen(QPen(Qt::transparent));
    abaj1->setPos(0,-30);
    scene->addItem(abaj1);
    obs.push_back(abaj1);
    abaj2=(new QGraphicsLineItem(350,0,0,0));
    abaj2->setPen(QPen(Qt::transparent));
    abaj2->setPos(0,-1236);
    scene->addItem(abaj2);
    obs.push_back(abaj2);
    abaj2Copia=(new QGraphicsLineItem(350,0,0,0));
    abaj2Copia->setPen(QPen(Qt::transparent));
    abaj2Copia->setPos(480,-1236);
    scene->addItem(abaj2Copia);
    obs.push_back(abaj2Copia);
    abaj3=(new QGraphicsLineItem(650,0,0,0));
    abaj3->setPen(QPen(Qt::transparent));
    abaj3->setPos(0,-2420);
    scene->addItem(abaj3);
    obs.push_back(abaj3);
    arrib1=(new QGraphicsLineItem(350,0,0,0));
    arrib1->setPen(QPen(Qt::transparent));
    arrib1->setPos(0,-580);
    scene->addItem(arrib1);
    obs.push_back(arrib1);
    arrib1Copia=(new QGraphicsLineItem(350,0,0,0));
    arrib1Copia->setPen(QPen(Qt::transparent));
    arrib1Copia->setPos(480,-580);
    scene->addItem(arrib1Copia);
    obs.push_back(arrib1Copia);
    arrib2=(new QGraphicsLineItem(350,0,0,0));
    arrib2->setPen(QPen(Qt::transparent));
    arrib2->setPos(0,-1768);
    scene->addItem(arrib2);
    obs.push_back(arrib2);
    arrib2Copia=(new QGraphicsLineItem(350,0,0,0));
    arrib2Copia->setPen(QPen(Qt::transparent));
    arrib2Copia->setPos(480,-1768);
    scene->addItem(arrib2Copia);
    obs.push_back(arrib2Copia);
    arrib3=(new QGraphicsLineItem(800,0,0,0));
    arrib3->setPen(QPen(Qt::transparent));
    arrib3->setPos(0,-2968);
    scene->addItem(arrib3);
    obs.push_back(arrib3);
    puenteIzq1=(new QGraphicsLineItem(0,600,0,0));
    puenteIzq1->setPen(QPen(Qt::transparent));
    puenteIzq1->setPos(350,-1210);
    scene->addItem(puenteIzq1);
    obs.push_back(puenteIzq1);
    puenteDrch1=(new QGraphicsLineItem(0,600,0,0));
    puenteDrch1->setPen(QPen(Qt::transparent));
    puenteDrch1->setPos(465,-1210);
    scene->addItem(puenteDrch1);
    obs.push_back(puenteDrch1);
    puenteIzq2=(new QGraphicsLineItem(0,600,0,0));
    puenteIzq2->setPen(QPen(Qt::transparent));
    puenteIzq2->setPos(350,-2405);
    scene->addItem(puenteIzq2);
    obs.push_back(puenteIzq2);
    puenteDrch2=(new QGraphicsLineItem(0,600,0,0));
    puenteDrch2->setPen(QPen(Qt::transparent));
    puenteDrch2->setPos(465,-2405);
    scene->addItem(puenteDrch2);
    obs.push_back(puenteDrch2);
    puertaBoss = new QGraphicsLineItem(120,0,0,0);
    puertaBoss->setPen(QPen(Qt::transparent));
    puertaBoss->setPos(332,-2400);
    obs.append(puertaBoss);
    scene->addItem(puertaBoss);
    puertaSala1 = new QGraphicsLineItem(120,0,0,0);
    puertaSala1->setPen(QPen(Qt::transparent));
    puertaSala1->setPos(342,-590);
    scene->addItem(puertaSala1);
    puertaSala2 = new QGraphicsLineItem(120,0,0,0);
    puertaSala2->setPen(QPen(Qt::transparent));
    puertaSala2->setPos(339,-1210);
    scene->addItem(puertaSala2);
    puertaSala3 = new QGraphicsLineItem(120,0,0,0);
    puertaSala3->setPen(QPen(Qt::transparent));
    puertaSala3->setPos(350,-1800);
    scene->addItem(puertaSala3);
    obs.append(puertaSala1);
    obs.append(puertaSala2);
    obs.append(puertaSala3);
}

void multijugador2::generarSoldados()
{
    if (  sala == 1 && numOleada==0 )
    {
        soldados.append(new soldado(98,-197,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(234,-333,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(638,-249,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(398,-303,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(194,-496,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(454,-100,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 1 && numOleada==1 )
    {
        soldados.append(new soldado(94,-133,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(214,-269,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(302,-441,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(442,-417,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(682,-498,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(554,-252,55,60));
        scene->addItem(soldados.last());
    }
    else if ( sala == 1 && numOleada==2)
    {
        soldados.append(new soldado(78,-485,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(82,-125,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(618,-181,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(582,-315,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(390,-285,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(286,-213,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 2 && numOleada==0 )
    {
        soldados.append(new soldado(90,-1337,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(214,-1541,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(346,-1437,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(638,-1577,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(370,-1689,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(318,-1361,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 2 && numOleada==1 )
    {
        soldados.append(new soldado(86,-1537,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(278,-1585,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(478,-1357,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(570,-1297,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(378,-1517,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(50,-1725,55,60));
        scene->addItem(soldados.last());
    }
    else if ( sala == 2 && numOleada==2)
    {
        soldados.append(new soldado(42,-1425,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(118,-1581,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(274,-1737,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(534,-1681,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(654,-1553,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(542,-1277,55,60));
        scene->addItem(soldados.last());
    }
}

void multijugador2::CBJCS(bala *LaBala)
{
    for ( int i = 0 ; i< soldados.size(); i++)
    {
        if (soldados.at(i)->collidesWithItem(LaBala))
        {

            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);

            if( soldados.at(i)->getVida()<=0)
            {
                scene->removeItem(soldados.at(i));
                soldados.removeOne(soldados.at(i));
            }
            else
            {
                soldados.at(i)->setVida(soldados.at(i)->getVida()-jugador->getDamage());
            }
        }
    }
    for ( int i = 0 ; i< arabes.size(); i++)
    {
        if (arabes.at(i)->collidesWithItem(LaBala) && arabes.at(i)->getExplotar() == false)
        {

            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);
            if( arabes.at(i)->getVida()<=0)
            {
                arabes.at(i)->setPos(arabes.at(i)->getPosx()-20,arabes.at(i)->getPosy()-20);
                arabes.at(i)->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
                arabes.at(i)->setExplotar(true);
            }
            else
            {

                arabes.at(i)->setVida(arabes.at(i)->getVida()-jugador->getDamage());
            }
        }
    }
    for ( int i  = 0 ;  i < obs.size(); i++)
    {
        if (LaBala->collidesWithItem(obs[i]))
        {
            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);
        }
    }
}

void multijugador2::CBSCM(bala *LaBalaDelSoldado)
{
    for ( int i = 0 ; i< obs.size(); i++)
    {
        if ( LaBalaDelSoldado->collidesWithItem(obs.at(i)))
        {
            scene->removeItem(LaBalaDelSoldado);
            balas.removeOne(LaBalaDelSoldado);
        }
    }
    if ( LaBalaDelSoldado->collidesWithItem(jugador) || LaBalaDelSoldado->collidesWithItem(jugador2))
    {
        if(LaBalaDelSoldado->collidesWithItem(jugador))
        {
            jugador->setVida(jugador->getVida()-6);
            ui->vidaJugador->setValue(jugador->getVida());
            scene->removeItem(LaBalaDelSoldado);
            balas.removeOne(LaBalaDelSoldado);
        }
        else if(LaBalaDelSoldado->collidesWithItem(jugador2))
        {
            jugador2->setVida(jugador->getVida()-6);
            ui->vidaJugador2->setValue(jugador2->getVida());
            scene->removeItem(LaBalaDelSoldado);
            balas.removeOne(LaBalaDelSoldado);
        }
        if (  jugador->getVida()<=0 || jugador2->getVida()<=0)
        {
            pausa();
            Ganar * gano;
            gano = new Ganar(uss,pass,false,2);
            ui->~multijugador2();
            close();
            gano->show();
        }
    }
}

void multijugador2::ColisionArabesYSoldados(soldado *solda)
{
    for ( int i = 0 ; i < arabes.size() ; i++)
    {
        if ( arabes.at(i)->collidesWithItem(solda) && arabes.at(i)->getExplotar()== true)
        {
            solda->moverAr(0.1);
        }
    }
}

void multijugador2::generarObstaculos()
{
    //esta funcion genera todos los obstaculos del primer nivel
    mesa1=(new obstaculos( 226,-2512,30,30));
    mesa1->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(60,60));
    mesas.push_back(mesa1);
    scene->addItem(mesa1);
    mesa2=(new obstaculos( 118,-2744,30,30));
    mesa2->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    mesas.push_back(mesa2);
    scene->addItem(mesa2);
    mesa3=(new obstaculos( 450,-2540,30,30));
    mesa3->setPixmap(QPixmap(":/imagenes/Led.png").scaled(60,60));
    mesas.push_back(mesa3);
    scene->addItem(mesa3);
    mesa4=(new obstaculos( 650,-2796,30,30));
    mesa4->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    mesas.push_back(mesa4);
    scene->addItem(mesa4);
    barril1=(new obstaculos( 95,-191,60,60));
    mesas.push_back(barril1);
    barril1->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(60,60));
    scene->addItem(barril1);
    barril2=(new obstaculos( 571,-179,60,60));
    mesas.push_back(barril2);
    barril2->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(60,60));
    scene->addItem(barril2);
    barril3=(new obstaculos( 571,-359,60,60));
    mesas.push_back(barril3);
    barril3->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(60,60));
    scene->addItem(barril3);
    barril4=(new obstaculos( 691,-275,60,60));
    mesas.push_back(barril4);
    barril4->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(60,60));
    scene->addItem(barril4);
    trincho1=(new obstaculos( 335,-367,30,30));
    mesas.push_back(trincho1);
    trincho1->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    scene->addItem(trincho1);
    trincho2=(new obstaculos( 99,-480,30,30));
    mesas.push_back(trincho2);
    trincho2->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    scene->addItem(trincho2);
    trincho3=(new obstaculos( 620,-420,30,30));
    mesas.push_back(trincho3);
    trincho3->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    scene->addItem(trincho3);
    trincho4=(new obstaculos( 451,-447,30,30));
    mesas.push_back(trincho4);
    trincho4->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(70,70));
    scene->addItem(trincho4);
    caja1=(new obstaculos( 687,-1476,60,60));
    mesas.push_back(caja1);
    caja1->setPixmap(QPixmap(":/imagenes/Led.png").scaled(60,60));
    scene->addItem(caja1);
    caja2=(new obstaculos( 571,-1388,60,60));
    mesas.push_back(caja2);
    caja2->setPixmap(QPixmap(":/imagenes/Led.png").scaled(60,60));
    scene->addItem(caja2);
    bolaDeFuego1 = new obstaculos(578,-482,30,30);
    bolaDeFuego1->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego1);
    bolaDeFuego2 = new obstaculos(384,-868,30,30);
    bolaDeFuego2->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego2);
    bolaDeFuego3 = new obstaculos(384,-1176,30,30);
    bolaDeFuego3->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego3);
    bolaDeFuego4 = new obstaculos(384,-1465,30,30);
    bolaDeFuego4->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego4);
    bolaDeFuego5 = new obstaculos(152,-1657,30,30);
    bolaDeFuego5->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego5);
    bolaDeFuego6 = new obstaculos(384,-2197,30,30);
    bolaDeFuego6->setPixmap(QPixmap(":/imagenes/bolaFuego.png").scaled(50,50));
    scene->addItem(bolaDeFuego6);
    bolasDeFuego.push_back(bolaDeFuego1);
    bolasDeFuego.push_back(bolaDeFuego2);
    bolasDeFuego.push_back(bolaDeFuego3);
    bolasDeFuego.push_back(bolaDeFuego4);
    bolasDeFuego.push_back(bolaDeFuego5);
    bolasDeFuego.push_back(bolaDeFuego6);
    obj1 = new obstaculos(459,-1300,30,30);
    obj1->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(50,50));
    scene->addItem(obj1);
    obj2 = new obstaculos(224,-1472,30,30);
    obj2->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(50,50));
    scene->addItem(obj2);
    obj3 = new obstaculos(100,-1384,30,30);
    obj3->setPixmap(QPixmap(":/imagenes/condensador.png").scaled(50,50));
    scene->addItem(obj3);
    obj4 = new obstaculos(340,-1560,30,30);
    obj4->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(50,50));
    scene->addItem(obj4);
    obj5 = new obstaculos(104,-1728,30,30);
    obj5->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(50,50));
    scene->addItem(obj5);
    obj6 = new obstaculos(457,-1652,30,30);
    obj6->setPixmap(QPixmap(":/imagenes/Bobina.png").scaled(50,50));
    scene->addItem(obj6);
    mesas.push_back(obj1);
    mesas.push_back(obj2);
    mesas.push_back(obj3);
    mesas.push_back(obj4);
    mesas.push_back(obj5);
    mesas.push_back(obj6);
}

void multijugador2::jefeFinal()
{
    if( (jugador->collidesWithItem(puertaBoss) && agujeroNegro->getAgujero()==false) || (jugador2->collidesWithItem(puertaBoss) && agujeroNegro->getAgujero()==false))
    {
        agujeroNegro->setPixmap(QPixmap(":/imagenes/agujero.png"));
        scene->addItem(agujeroNegro);
        agujeroNegro->setAgujero(true);
        sala = 3;

    }
    else if ( (agujeroNegro->getAgujero() == true && !jugador->collidesWithItem(agujeroNegro))
               || ( agujeroNegro->getAgujero() == true && !jugador2->collidesWithItem(agujeroNegro)))
    {
        if( agujeroNegro->getTragadoxD() == false)
        {
            agujeroNegro->atraccionGravitacional(jugador);
            agujeroNegro->atraccionGravitacional(jugador2);
        }
        if(!(sala ==3 && jugador->getPosy()<-2480))
        {
            scene->setSceneRect(0,jugador->getPosy()-515,800,600);
        }
    }
    else if ((agujeroNegro->getAgujero()==true && jugador->collidesWithItem(agujeroNegro))
             || (agujeroNegro->getAgujero()==true && jugador2->collidesWithItem(agujeroNegro)))
    {
        //hay que sacar el boss
        agujeroNegro->setTragadoxD(true);
        ui->vida_boss->setVisible(true);
        timerCBJCB->start(1);
        sebastian->setActivo(true);
        sebastian->setPosx(374);
        sebastian->setPosy(-2900);
        scene->addItem(sebastian);
        srand(time(NULL));
        movimientoSebastian=86+rand()%(678-86);
        margenError = int((sebastian->getPosx() - movimientoSebastian));
        //hay que conectar todos los timers que activen cosas del boss
        timerGBB->start(10);
        timerColisionBalasBoss->start(1);
        timerMoverBoss->start(20);
        //hay que hacer que agusto empieze a decir cosas
        scene->removeItem(agujeroNegro);
        dialogosSebastian->setMedia(QUrl());//Falta colocar el audio;
        dialogosSebastian->setVolume(100);
        dialogosSebastian->play();
        lvl1->stop();
    }
}

void multijugador2::generarArabe()
{
    if ( sala==1 && numOleada ==0)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(393);
        arabes.last()->setPosy(-372);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(740);
        arabes.last()->setPosy(-372);
        scene->addItem(arabes.last());
    }
    else if ( sala == 1 && numOleada ==1)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(86);
        arabes.last()->setPosy(-546);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(393);
        arabes.last()->setPosy(-372);
        scene->addItem(arabes.last());
    }
    else if ( sala == 1 && numOleada==2)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(710);
        arabes.last()->setPosy(-481);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(393);
        arabes.last()->setPosy(-372);
        scene->addItem(arabes.last());
    }
    else if ( sala==2 && numOleada ==0)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(386);
        arabes.last()->setPosy(-1537);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(476);
        arabes.last()->setPosy(-1700);
        scene->addItem(arabes.last());
    }
    else if ( sala == 2 && numOleada ==1)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(56);
        arabes.last()->setPosy(-1765);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(393);
        arabes.last()->setPosy(-1463);
        scene->addItem(arabes.last());
    }
    else if ( sala == 2 && numOleada==2)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(366);
        arabes.last()->setPosy(-1505);
        scene->addItem(arabes.last());
        arabes.append(new arabe());
        arabes.last()->setPosx(480);
        arabes.last()->setPosy(-1603);
        scene->addItem(arabes.last());
    }
    if ( !mover_arabe->isActive())
    {
        mover_arabe->start(20);
        colision_arabe->start(20);
    }
}

void multijugador2::pausa()
{
    if( sebastian->getVida()<=0)
    {
        //no diga que le salio falda
    }
    else
    {
        dialogosSebastian->setMedia(QUrl("qrc:/musica/lesaliofaldita_1.mp3"));
        dialogosSebastian->setVolume(100);
        dialogosSebastian->play();
    }

    pausa_=true ;
    if(tiempo->isActive())
    {
        tiempo->stop();
    }
    if ( mover_Soldado->isActive())
    {
        mover_Soldado->stop();
    }
    if( mover_arabe->isActive())
    {
        mover_arabe->stop() ;
    }
    if ( colision_arabe->isActive())
    {
        colision_arabe->stop();
    }
    if (balas_soldado->isActive())
    {
        balas_soldado->stop();
    }
    if ( balasB->isActive())
    {
        balasB->stop();
    }
    if( timerGBB->isActive() )
    {
        timerGBB->stop();
    }
    if ( timerColisionBalasBoss->isActive())
    {
        timerColisionBalasBoss->stop();
    }
    if ( timerMoverBoss->isActive())
    {
        timerMoverBoss->stop();
    }
    if( timerCBJCB->isActive())
    {
        timerCBJCB->stop();
    }
    if ( timerColisionesJugador->isActive())
    {
        timerColisionesJugador->stop();
    }
    if( lvl1->isActive())
    {
        lvl1->stop();
    }
    if( dialog->isActive())
    {
        dialog->stop();
    }
    if( oleada->isActive())
    {
        oleada->stop();
    }
    if( puertas->isActive())
    {
        puertas->stop();
    }
    if ( timerColisionDeMesas->isActive())
    {
        timerColisionDeMesas->stop();
    }
    if( Timer_MoverYColisionBolasDeFuego->isActive())
    {
        Timer_MoverYColisionBolasDeFuego->stop();
    }
    ui->SALIR->setVisible(true);
    ui->pushButton->setVisible(true);
}

void multijugador2::nuevaPartida()
{
    //-------------------zona de eventos-------------------

        scene = new QGraphicsScene();
        scene->setBackgroundBrush(QBrush(QImage(":/imagenes/Nivel2Fondo.png")));
        scene->setSceneRect(0,0,800,600); //definimos el 0,0 de la escena


        //-------------------graficador-------------------

        ui->graphicsView->setScene(scene);
        ui->graphicsView->setFixedSize(800,600);



        //-------------------bloqueos-------------------

        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        generarBordes();


        //-------------------player-------------------

        jugador = new personaje(384,-81,50,55,100,100);
        scene->addItem(jugador);
        scene->setFocusItem(jugador);
        jugador2 = new personaje(320,-81,50,55,100,100);
        jugador2->setPixmap(QPixmap(":/imagenes/es1.png").scaled(30,50));
        scene->addItem(jugador2);
        scene->setFocusItem(jugador2);

        //-------------------boss-------------------

        sebastian = new boss1();
        agujeroNegro = new obstaculos(356,-2780,30,30);



        //-------------------timers-------------------

        puertas = new QTimer ;
        connect(puertas, &QTimer::timeout, this, &multijugador2::Puertas);
        puertas->start(1);

        Timer_MoverYColisionBolasDeFuego = new QTimer ;
        connect(Timer_MoverYColisionBolasDeFuego, &QTimer::timeout, this, &multijugador2::MoverYColisionBolasDeFuego);
        Timer_MoverYColisionBolasDeFuego->start(20);

        oleada = new QTimer();
        connect(oleada, &QTimer::timeout, this, &multijugador2::oleadas);
        oleada->start(5000);

        tiempo = new QTimer();
        connect(tiempo, &QTimer::timeout, this, &multijugador2::moverBalasJugador);

        balas_soldado = new QTimer();
        connect(balas_soldado,&QTimer::timeout,this,&multijugador2::dispararSoldado);

        mover_Soldado = new QTimer();
        connect(mover_Soldado,&QTimer::timeout,this,&multijugador2::moverSoldado);

        mover_arabe = new QTimer();
        connect(mover_arabe,&QTimer::timeout,this,&multijugador2::moverArabe);

        colision_arabe =  new QTimer();
        connect(colision_arabe, &QTimer::timeout,this,&multijugador2::colisionArabe);

        balasB = new QTimer();
        connect(balasB,&QTimer::timeout,this,&multijugador2::dispararBoss);

        timerGBB = new QTimer();
        connect(timerGBB, &QTimer::timeout,this,&multijugador2::generarBalasBoss);

        timerColisionBalasBoss = new QTimer();
        connect(timerColisionBalasBoss, &QTimer::timeout,this,&multijugador2::ColisionBalasBoss);

        timerMoverBoss = new QTimer();
        connect(timerMoverBoss, &QTimer::timeout,this,&multijugador2::moverBoss) ;

        timerCBJCB = new QTimer;
        connect(timerCBJCB, &QTimer::timeout,this,&multijugador2::CBJCB) ;

        timerColisionesJugador =  new QTimer;
        connect(timerColisionesJugador,&QTimer::timeout,this,&multijugador2::colisionesJugador);

        lvl1 = new QTimer();
        connect(lvl1, &QTimer::timeout,this,&multijugador2::jefeFinal);
        lvl1->start(20);

        dialog = new QTimer();
        connect(dialog, &QTimer::timeout,this,&multijugador2::dialogos);
        dialog->start(10000);

        timerColisionDeMesas = new QTimer;
        connect(timerColisionDeMesas, &QTimer::timeout,this,&multijugador2::colisionBalasConMesasETC);
        timerColisionDeMesas->start(1);

        timerGBB->stop();
        timerColisionBalasBoss->stop();
        timerMoverBoss->stop();
        tiempo->start(20);


        //-------------------foco-------------------
        scene->setSceneRect(0,jugador->getPosy()-515,800,600);
        generarObstaculos();
        dialogosSebastian=new QMediaPlayer;
        dialogosSebastian->setMedia(QUrl("qrc:/musica/cariñonomepidas.mp3"));
        dialogosSebastian->setVolume(100);
        dialogosSebastian->play();
        musica=new QMediaPlayer;
        musica->setMedia(QUrl("qrc:/musica/musicaFondo.mp3"));
        musica->setVolume(30 );
        musica->play();
        efectos=new QMediaPlayer;
        efectos->setVolume(50);
        ui->SALIR->setVisible(false);
        ui->vida_boss->setVisible(false);
        ui->pushButton->setVisible(false);
}

void multijugador2::colisionConMesasETC()
{
    for ( int i = 0 ; i< mesas.size(); i++)
    {
        if ( jugador->collidesWithItem(mesas.at(i)) || jugador2->collidesWithItem(mesas.at(i)))
        {
            if( jugador->collidesWithItem(mesas.at(i)))
            {
                switch (dire)
                {
                case('W'):
                {
                    jugador->setPosy(jugador->getPosy()+1);
                    jugador->setPos(jugador->getPosx(),jugador->getPosy());
                    colision=true;
                    break;
                }
                case('A'):
                {
                    jugador->setPosx(jugador->getPosx()+1);
                    jugador->setPos(jugador->getPosx(),jugador->getPosy());
                    colision=true;
                    break;
                }
                case('S'):
                {
                    jugador->setPosy(jugador->getPosy()-1);
                    jugador->setPos(jugador->getPosx(),jugador->getPosy());
                    colision=true;
                    break;
                }
                case('D'):
                {
                    jugador->setPosx(jugador->getPosx()-1);
                    jugador->setPos(jugador->getPosx(),jugador->getPosy());
                    colision=true;
                    break;
                }
                }
            }
            else if( jugador2->collidesWithItem(mesas.at(i)))
            {
                switch (direP2)
                {
                case('W'):
                {
                    jugador2->setPosy(jugador2->getPosy()+1);
                    jugador2->setPos(jugador2->getPosx(),jugador2->getPosy());
                    colisionP2=true;
                    break;
                }
                case('A'):
                {
                    jugador2->setPosx(jugador2->getPosx()+1);
                    jugador2->setPos(jugador2->getPosx(),jugador2->getPosy());
                    colisionP2=true;
                    break;
                }
                case('S'):
                {
                    jugador2->setPosy(jugador2->getPosy()-1);
                    jugador2->setPos(jugador2->getPosx(),jugador2->getPosy());
                    colisionP2=true;
                    break;
                }
                case('D'):
                {
                    jugador2->setPosx(jugador2->getPosx()-1);
                    jugador2->setPos(jugador2->getPosx(),jugador2->getPosy());
                    colisionP2=true;
                    break;
                }
                }
            }
        }
        else
        {
            colision=false;
            colisionP2=false;
        }
    }
    for ( int i = 0 ; i < mesas.size(); i++)
    {
        for ( int j = 0 ; j < soldados.size(); j++)
        {
            if ( soldados.at(j)->collidesWithItem(mesas.at(i)))
            {
                switch (soldados.at(j)->getDir())
                {
                case('W'):
                {
                    soldados.at(j)->setPosy(soldados.at(j)->getPosy()+1);
                    soldados.at(j)->setPos(soldados.at(j)->getPosx(),soldados.at(j)->getPosy());
                    break;
                }
                case('A'):
                {
                    soldados.at(j)->setPosx(soldados.at(j)->getPosx()+1);
                    soldados.at(j)->setPos(soldados.at(j)->getPosx(),soldados.at(j)->getPosy());
                    break;
                }
                case('S'):
                {
                    soldados.at(j)->setPosy(soldados.at(j)->getPosy()-1);
                    soldados.at(j)->setPos(soldados.at(j)->getPosx(),soldados.at(j)->getPosy());
                    break;
                }
                case('D'):
                {
                    soldados.at(j)->setPosx(soldados.at(j)->getPosx()-1);
                    soldados.at(j)->setPos(soldados.at(j)->getPosx(),soldados.at(j)->getPosy());
                    break;
                }
                }
            }
        }
    }
}

void multijugador2::moverSoldado()
{
    QList<soldado*>::iterator ms;
    for ( int i = 0 ; i < obs.size(); i++)
    {
        for ( int j = 0 ; j < soldados.size(); j++)
        {
            if ( soldados.at(j)->collidesWithItem(obs.at(i)))
            {
                mover_Soldado->start(100);
                switch (soldados.at(j)->getDir())
                {
                case('W'):
                {
                    soldados.at(j)->AnimarAbajo();
                    soldados.at(j)->moverAb(0.04);
                    soldados.at(j)->setDir('W');


                    break;
                }
                case('A'):
                {
                    soldados.at(j)->AnimarDerecha();
                    soldados.at(j)->moverDr(0.04);
                    soldados.at(j)->setDir('A');
                    break;
                }
                case('S'):
                {
                    soldados.at(j)->AnimarArriba();
                    soldados.at(j)->moverAr(0.04);
                    soldados.at(j)->setDir('S');
                    break;
                }
                case('D'):
                {
                    soldados.at(j)->AnimarIzquierda();;
                    soldados.at(j)->moverIz(0.04);
                    soldados.at(j)->setDir('D');

                    break;
                }
                }
                return;
            }
            else
            {
                mover_Soldado->start(1000);
            }
        }
    }
    for ( ms = soldados.begin(); ms != soldados.end(); ms++)
    {
        int aleatorio = 1+rand()%4;
        if(aleatorio==1)
        {
            ms.i->t()->AnimarArriba();
            ms.i->t()->moverAr(0.04);

        }
        else if(aleatorio==2)
        {
            ms.i->t()->AnimarAbajo();
             ms.i->t()->moverAb(0.04);


        }
        else if(aleatorio==3)
        {
                       ms.i->t()->AnimarDerecha();
            ms.i->t()->moverDr(0.04);


        }
        else if(aleatorio==4)
        {
            ms.i->t()->AnimarIzquierda();
            ms.i->t()->moverIz(0.04);

        }
        ColisionArabesYSoldados(ms.i->t());
        balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
        balas.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
        scene->addItem(balas.last()); //con estas dos lineas creamos una bala.
    }
}

void multijugador2::moverArabe()
{
    QList<arabe*>::iterator ma;
    for ( ma = arabes.begin(); ma != arabes.end() ; ma++)
    {
        ma.i->t()->setDistancia(abs(ma.i->t()->pos().y()-jugador2->pos().y()));
        if (ma.i->t()->pos().x()<jugador2->pos().x() && (ma.i->t()->getExplotar() == false))
        {
            ma.i->t()->moverDerecha(0.02);
            ma.i->t()->animarDerecha();
        }
        if (ma.i->t()->pos().x()>jugador2->pos().x() && (ma.i->t()->getExplotar() == false) )
        {
             ma.i->t()->moverIzquierda(0.02);
             ma.i->t()->animarIzquierda();
        }
        if ( ma.i->t()->pos().y()<jugador2->pos().y() && (ma.i->t()->getExplotar() == false))
        {
            ma.i->t()->moverAbajo(0.01);
            ma.i->t()->animarAbajo();
        }
         if (ma.i->t()->pos().y()>jugador2->pos().y() && (ma.i->t()->getExplotar() == false))
         {
             ma.i->t()->moverArriba(0.01);
             ma.i->t()->animarArriba();
         }
    }
}

void multijugador2::Puertas()
{
    if ( jugador->collidesWithItem(puertaSala2) || jugador2->collidesWithItem(puertaSala2))
    {
        sala=2;
        numOleada=0;
    }
     if ( ((jugador->collidesWithItem(puertaSala1) &&  sala == 1  && soldados.size()!= 0))
          || ((jugador2->collidesWithItem(puertaSala1) &&  sala == 1  && soldados.size()!= 0)))
     {
         if ( ((jugador->collidesWithItem(puertaSala1) &&  sala == 1  && soldados.size()!= 0)) )
         {
             jugador->setPosy(jugador->getPosy()+10);
         }
         else if( ((jugador2->collidesWithItem(puertaSala1) &&  sala == 1  && soldados.size()!= 0)))
         {
             jugador2->setPosy(jugador2->getPosy()+10);
         }
     }
     else if ((jugador->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()!= 0 ) ||
              (jugador2->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()!= 0 ))
     {
         if (jugador->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()!= 0 )
         {
             jugador->setPosy(jugador->getPosy()+10);
         }
         else if (jugador2->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()!= 0 )
         {
             jugador2->setPosy(jugador2->getPosy()+10);
         }
     }
     else if ((jugador->collidesWithItem(puertaSala2) &&  sala ==2  && soldados.size()!= 0)
              || (jugador2->collidesWithItem(puertaSala2) &&  sala ==2  && soldados.size()!= 0))
     {
         if ((jugador->collidesWithItem(puertaSala2) &&  sala ==2  && soldados.size()!= 0))
         {
             jugador->setPosy(jugador->getPosy()-10);
         }
         else if((jugador2->collidesWithItem(puertaSala2) &&  sala ==2  && soldados.size()!= 0))
         {
             jugador2->setPosy(jugador2->getPosy()-10);
         }
     }
     else if ( (jugador->collidesWithItem(puertaSala1) && numOleada >=2 && soldados.size()==0)
               || (jugador2->collidesWithItem(puertaSala1) && numOleada >=2 && soldados.size()==0))
     {
         if ( (jugador2->collidesWithItem(puertaSala1) && numOleada >=2 && soldados.size()==0))
         {
             sala = 5;
         }
         else if ((jugador->collidesWithItem(puertaSala1) && numOleada >=2 && soldados.size()==0))
         {
             sala = 5;
         }
     }
     else if ((jugador->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()== 0 )
              || (jugador2->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()== 0 ))
     {
         if ((jugador->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()== 0 ))
         {
             sala =5;
         }
         else if ( (jugador2->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()== 0 ))
         {
             sala = 5;
         }
     }
}

void multijugador2::colisionArabe()
{
    //esta funcion se encarga de detectar cuando un arabe colisiona con el jugador para explotarse y dejar el rastro.
    QList<arabe*>::iterator ca;
    for (ca = arabes.begin(); ca != arabes.end(); ca ++)
    {
        if ( ca.i->t()->collidesWithItem(jugador))
        {
           //hacemos que explote.
           ca.i->t()->setPos(ca.i->t()->getPosx()-20,ca.i->t()->getPosy()-20);
           ca.i->t()->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
           ca.i->t()->setExplotar(true);
        }
        else if ( ca.i->t()->collidesWithItem(jugador2))
        {
            //hacemos que explote.
            ca.i->t()->setPos(ca.i->t()->getPosx()-20,ca.i->t()->getPosy()-20);
            ca.i->t()->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
            ca.i->t()->setExplotar(true);
        }
    }
}

void multijugador2::moverBalasJugador()
{
    for ( int i = 0 ; i < balasJugador.size(); i++)
    {
            balasJugador.at(i)->moverBala();
            CBJCS(balasJugador.at(i));
    }
    if ( delayDisparar<10)
    {
        delayDisparar++;
    }
    if(delayDispararP2<10)
    {
        delayDispararP2++;
    }
}

void multijugador2::dispararSoldado()
{
    for ( int i =0; i<balas.size() ;i++)
    {
        balas.at(i)->moverBala();
        CBSCM(balas.at(i));
    }
    QList<soldado*>::iterator ms;
    for ( ms = soldados.begin(); ms != soldados.end(); ms++)
    {
        int aleatorio = 1+rand()%80;
        if(aleatorio==25)
        {
            balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
            balas.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            scene->addItem(balas.last()); //con estas dos lineas creamos una bala.
        }
    }
}

void multijugador2::dispararBoss()
{
    if( poder ==4)
    {
        sebastian->dispararEnSol(L_balasBoss);
    }
    else if  ( poder == 5)
    {
        sebastian->lluviaNotas(L_balasBoss);
    }
}

void multijugador2::ColisionBalasBoss()
{
    for ( int i = 0 ; i< L_balasBoss.size() ; i++)
    {
        if( (L_balasBoss.at(i)->collidesWithItem(jugador)) || (L_balasBoss.at(i)->collidesWithItem(jugador2))
                || (L_balasBoss.at(i)->collidesWithItem(jugador) && L_balasBoss.at(i)->collidesWithItem(jugador2)))
        {
            if( L_balasBoss.at(i)->getSumarVida() == true)
            {
                if( L_balasBoss.at(i)->collidesWithItem(jugador))
                {
                    //sumamos 5 unidades a la vida del jugador
                    efectos->setMedia(QUrl("qrc:/musica/cogerVida.mp3"));
                    efectos->play();
                    scene->removeItem(L_balasBoss.at(i));
                    L_balasBoss.removeOne(L_balasBoss.at(i));
                    jugador->setVida(jugador->getVida()+5);
                    ui->vidaJugador->setValue(jugador->getVida());
                }
                else if ( L_balasBoss.at(i)->collidesWithItem(jugador2))
                {
                    //sumamos 5 unidades a la vida del jugador
                    efectos->setMedia(QUrl("qrc:/musica/cogerVida.mp3"));
                    efectos->play();
                    scene->removeItem(L_balasBoss.at(i));
                    L_balasBoss.removeOne(L_balasBoss.at(i));
                    jugador2->setVida(jugador2->getVida()+5);
                    ui->vidaJugador2->setValue(jugador2->getVida());
                }
            }
            else
            {
                if( L_balasBoss.at(i)->collidesWithItem(jugador))
                {
                    efectos->setMedia(QUrl("qrc:/musica/golpeAugusto.mp3"));
                    efectos->play();
                    scene->removeItem(L_balasBoss.at(i));
                    L_balasBoss.removeOne(L_balasBoss.at(i));
                    jugador->setVida(jugador->getVida()-5);
                    ui->vidaJugador->setValue(jugador->getVida());
                }
                else if (L_balasBoss.at(i)->collidesWithItem(jugador2))
                {
                    efectos->setMedia(QUrl("qrc:/musica/golpeAugusto.mp3"));
                    efectos->play();
                    scene->removeItem(L_balasBoss.at(i));
                    L_balasBoss.removeOne(L_balasBoss.at(i));
                    jugador2->setVida(jugador2->getVida()-5);
                    ui->vidaJugador2->setValue(jugador2->getVida());
                }
            }

            if ( jugador->getVida() <=0 || jugador2->getVida()<=0 )
            {
                pausa();
                Ganar * gano;
                gano = new Ganar(uss,pass,false,2);
                ui->~multijugador2();
                close();
                gano->show();
            }
            else
            {
            }

        }
        else if( L_balasBoss.at(i)->collidesWithItem(arrib3)
                 || L_balasBoss.at(i)->collidesWithItem(abaj3)
                 || L_balasBoss.at(i)->collidesWithItem(izq1)
                 || L_balasBoss.at(i)->collidesWithItem(drch1)
                 || L_balasBoss.at(i)->collidesWithItem(puertaBoss)
                 || L_balasBoss.at(i)->collidesWithItem(abaj2Copia)
                 || L_balasBoss.at(i)->collidesWithItem(arrib1Copia)
                 || L_balasBoss.at(i)->collidesWithItem(arrib2Copia)
                 )
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }
        else if (L_balasBoss.at(i)->getPosx()<-10 || L_balasBoss.at(i)->getPosx()>810)
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }
        else if ( L_balasBoss.at(i)->collidesWithItem(mesa1) ||  L_balasBoss.at(i)->collidesWithItem(mesa2)
                  ||  L_balasBoss.at(i)->collidesWithItem(mesa3) ||  L_balasBoss.at(i)->collidesWithItem(mesa4))
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }
        if(L_balasBoss.size()==0)
        {
            if(!timerGBB->isActive())
            {
                timerGBB->start(10);
            }
        }
    }
}

void multijugador2::generarBalasBoss()
{
    if ( L_balasBoss.size()==0 && sebastian->getMoviendome()==false && sebastian->getVida()>0)
    {
        poder = 1+rand()%3;
        if ( poder ==1)
        {
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(1);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(2);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(3);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(4);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(5);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(6);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(7);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(8);
            scene->addItem(L_balasBoss.last());
            poder = 4;
        }
        else if ( poder ==2)
        {
            int cinco=0+rand()%14;
            L_balasBoss.push_back(new bala(50,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(100,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(150,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(200,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(250,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(300,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(350,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(400,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(450,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(500,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(550,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(600,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(650,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(700,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(750,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.at(cinco)->setPixmap(QPixmap(":/imagenes/vida.png").scaled(30,30));
            L_balasBoss.at(cinco)->setSumarVida(true);
            poder= 5;
        }
        if ( !balasB->isActive() )
        {
            balasB->start(10);
        }
    }
}

void multijugador2::moverBoss()
{
    if  ((margenError>= 8  || margenError <=-8))
    {
        sebastian->setMoviendome(true);
        if ( (margenError<0))
        {
            sebastian->moverDerecha(0.04);
            sebastian->animarDerechaSEBAS();
        }
        else if ( margenError > 0 )
        {
            sebastian->moverIzquierda(0.04);
            sebastian->animarIzquierdaSEBAS();
        }

    }
    else
    {
        sebastian->setMoviendome(false);
        sebastian->setPixmap(QPixmap(":/imagenes2/fr1s.png"));
    }
    if( contador==200)
    {
        movimientoSebastian=86+rand()%(678-86);
        contador= 0;
    }
    margenError = int((sebastian->getPosx() - movimientoSebastian));
    contador++;
}

void multijugador2::CBJCB()
{
    for ( int i = 0 ; i<balasJugador.size(); i++)
    {
        if ( balasJugador.at(i)->collidesWithItem(sebastian))
        {
            if ( sebastian->getEscudo()>0)
            {

                scene->removeItem(balasJugador.at(i));
                balasJugador.removeOne(balasJugador.at(i));
                sebastian->setEscudo(sebastian->getEscudo()-jugador->getDamage());
                ui->vida_boss->setValue(sebastian->getEscudo());
            }
            else
            {
                if ( sebastian->getVida()>0)
                {

                    scene->removeItem(balasJugador.at(i));
                    balasJugador.removeOne(balasJugador.at(i));
                    sebastian->setVida(sebastian->getVida()-jugador->getDamage());
                    ui->vida_boss->setValue(sebastian->getVida());

                }
                else
                {
                    timerCBJCB->stop();
                    sebastian->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
                    timerMoverBoss->stop();
                    timerGBB->stop();
                    pausa();
                    QMessageBox::information(this,"JUEGO","JUEGO COMPLETADO CON ÉXITO");
                    ui->pushButton->setVisible(true);
                }
            }
        }
    }
}

void multijugador2::colisionesJugador()
{
    //este primer for es para detecta la colision del jugador con los arabes cuando estan muertos, generando friccion
    for ( int i = 0 ; i < arabes.size(); i++)
    {
        if ( (jugador->collidesWithItem(arabes.at(i)) && arabes.at(i)->getExplotar()== true) ||
             (jugador2->collidesWithItem(arabes.at(i)) && arabes.at(i)->getExplotar()== true))
        {
            if((jugador->collidesWithItem(arabes.at(i)) && arabes.at(i)->getExplotar()== true))
            {
                jugador->setVx(30);
                jugador->setVy(30);
                mermarVida++;
            }
            else if((jugador2->collidesWithItem(arabes.at(i)) && arabes.at(i)->getExplotar()== true))
            {
                jugador2->setVx(30);
                jugador2->setVy(30);
                mermarVidaP2++;
            }

        }
        else
        {
            jugador->setVx(100);
            jugador->setVy(100);
            jugador2->setVx(100);
            jugador2->setVy(100);
        }
        if ( mermarVida >= 100)
        {
            jugador->setVida(jugador->getVida()-10);
            mermarVida=0;
            ui->vidaJugador->setValue(jugador->getVida());
            if (  jugador->getVida()<=0)
            {
                pausa();
                Ganar * gano;
                gano = new Ganar(uss,pass,false,2);
                ui->~multijugador2();
                close();
                gano->show();
            }
        }
        if ( mermarVidaP2 >= 100)
        {
            jugador2->setVida(jugador2->getVida()-10);
            mermarVidaP2=0;
            ui->vidaJugador2->setValue(jugador2->getVida());
            if (  jugador2->getVida()<=0)
            {
                pausa();
                Ganar * gano;
                gano = new Ganar(uss,pass,false,2);
                ui->~multijugador2();
                close();
                gano->show();
            }
        }
    }
}

void multijugador2::dialogos()
{
    if (agujeroNegro->getAgujero()==false)
    {
        int numero  = 1 + rand()%10;
        if ( numero ==5)
        {
            dialogosSebastian->setMedia(QUrl("qrc:/musica/esperaloqueseviene.mp3"));
            dialogosSebastian->setVolume(100);
            dialogosSebastian->play();
        }
    }
    else if ( agujeroNegro->getAgujero() == true && !lvl1->isActive())
    {
        int numero = 1+rand()%3;
        if (  numero ==1)
        {
            dialogosSebastian->setMedia(QUrl("qrc:/musica/cariñonomepidas.mp3"));
            dialogosSebastian->setVolume(100);
            dialogosSebastian->play();
        }
        else if ( numero ==2)
        {
            dialogosSebastian->setMedia(QUrl("qrc:/musica/esperaloqueseviene.mp3"));
            dialogosSebastian->setVolume(100);
            dialogosSebastian->play();
        }
        else if( numero ==3)
        {
            dialogosSebastian->setMedia(QUrl("qrc:/musica/plazamercado.mp3"));
            dialogosSebastian->setVolume(100);
            dialogosSebastian->play();
        }
    }
}

void multijugador2::oleadas()
{
    if( numOleada==0 && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
         balas_soldado->start(20);
         mover_Soldado->start(1000);
         timerColisionesJugador->start(20);
         numOleada++;
    }
    else if (numOleada==1  && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
        balas_soldado->start(20);
        mover_Soldado->start(1000);
        timerColisionesJugador->start(20);
        numOleada++;
    }
    else if(numOleada==2 && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
        balas_soldado->start(20);
        mover_Soldado->start(1000);
        timerColisionesJugador->start(20);
        numOleada=3;
        if ( sala ==2 )
        {
            oleada->stop();
        }
    }
}

void multijugador2::colisionBalasConMesasETC()
{
    colisionConMesasETC();
    for ( int j = 0 ; j < mesas.size() ; j++)
    {
        for (int i = 0 ; i < balas.size(); i ++)
        {
            if ( balas.at(i)->collidesWithItem(mesas.at(j)))
            {
                scene->removeItem(balas.at(i));
                balas.removeOne(balas.at(i));
            }
        }
    }
    for ( int j = 0 ; j < mesas.size() ; j++)
    {
        for (int i = 0 ; i < balasJugador.size(); i ++)
        {
            if ( balasJugador.at(i)->collidesWithItem(mesas.at(j)))
            {
                scene->removeItem(balasJugador.at(i));
                balasJugador.removeOne(balasJugador.at(i));
            }
        }
    }
}

void multijugador2::MoverYColisionBolasDeFuego()
{
    for ( int i = 0 ; i< bolasDeFuego.size(); i++)
    {
        if( bolasDeFuego.at(i)->collidesWithItem(jugador) || bolasDeFuego.at(i)->collidesWithItem(jugador2) )
        {
            if(bolasDeFuego.at(i)->collidesWithItem(jugador))
            {
                jugador->setVida(jugador->getVida()-3);
                ui->vidaJugador->setValue(jugador->getVida());
                if( jugador->getVida()<=0)
                {
                    pausa();
                    Ganar * gano;
                    gano = new Ganar(uss,pass,false,2);
                    ui->~multijugador2();
                    close();
                    gano->show();
                }
            }
            else if (bolasDeFuego.at(i)->collidesWithItem(jugador2))
            {
                jugador2->setVida(jugador2->getVida()-3);
                ui->vidaJugador2->setValue(jugador2->getVida());
                if( jugador2->getVida()<=0)
                {
                    pausa();
                    Ganar * gano;
                    gano = new Ganar(uss,pass,false,2);
                    ui->~multijugador2();
                    close();
                    gano->show();
                }
            }
        }
        bolasDeFuego.at(i)->movimientoCircular();
    }
}

void multijugador2::on_SALIR_clicked()
{
    pausa_=false;
    if(!tiempo->isActive())
    {
        tiempo->start(20);
    }
    if ( !mover_Soldado->isActive())
    {
        mover_Soldado->start(1000);
    }
    if( !mover_arabe->isActive())
    {
        mover_arabe->start(20) ;
    }
    if ( !colision_arabe->isActive())
    {
        colision_arabe->start(20);
    }
    if (!balas_soldado->isActive())
    {
        balas_soldado->start(20);
    }
    if ( !balasB->isActive() && agujeroNegro->getAgujero()==true)
    {
        balasB->start(10);
    }
    if( !timerGBB->isActive() && agujeroNegro->getAgujero()==true)
    {
        timerGBB->start(10);
    }
    if ( !timerColisionBalasBoss->isActive() && agujeroNegro->getAgujero()==true)
    {
        timerColisionBalasBoss->start(1);
    }
    if ( !timerMoverBoss->isActive() && agujeroNegro->getAgujero()==true)
    {
        timerMoverBoss->start(20);
    }
    if(! timerCBJCB->isActive() && agujeroNegro->getAgujero()==true)
    {
        timerCBJCB->start(1);
    }
    if ( !timerColisionesJugador->isActive())
    {
        timerColisionesJugador->start(20);
    }
    if( !lvl1->isActive())
    {
        lvl1->start(20);
    }
    if( !dialog->isActive())
    {
        dialog->start(10000);
    }
    if( !oleada->isActive())
    {
        oleada->start(5000);
    }
    if(! puertas->isActive())
    {
        puertas->start(1);
    }
    if (  !timerColisionDeMesas->isActive())
    {
        timerColisionDeMesas->start(1);
    }
    if( !Timer_MoverYColisionBolasDeFuego->isActive())
    {
        Timer_MoverYColisionBolasDeFuego->start(20);
    }
    ui->SALIR->setVisible(false);
    ui->pushButton->setVisible(false);
}

void multijugador2::on_pushButton_clicked()
{
    close();
}
