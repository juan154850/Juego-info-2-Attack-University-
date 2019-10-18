#include "boss1.h"

boss1::boss1() : personaje (0,0,55,60,100,100)
{
    setPixmap(QPixmap(":/imagenes/afr1.png").scaled(100,100));
}

void boss1::dispararIzquierda(bala *bala)
{
    bala->setPosx((bala->getPosx()-(bala->getVx()*0.04)));
    bala->setPosy((bala->getPosy()+(bala->getVy()*0.04)));
    bala->setPos(bala->getPosx(),bala->getPosy());

}

void boss1::dispararDerecha(bala *bala)
{
    bala->setPosx((bala->getPosx()+(bala->getVx()*0.04)));
    bala->setPosy((bala->getPosy()+(bala->getVy()*0.04)));
    bala->setPos(bala->getPosx(),bala->getPosy());
}
int boss1::getDelayDisparo() const
{
    return delayDisparo;
}

void boss1::setDelayDisparo(int value)
{
    delayDisparo = value;
}

void boss1::dispararEnSol(QList<bala *> balas)
{
    for (int i = 0;i<balas.size();i++)
    {
        if (balas.at(i)->getNumBala()== 0 )
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()-4.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+1);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());

        }
        else if (balas.at(i)->getNumBala() == 1)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()-3.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+2);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if (balas.at(i)->getNumBala() ==2)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()-2.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+3);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==3)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()-1.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+4);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==4)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx());
            balas.at(i)->setPosy(balas.at(i)->getPosy()+4.25);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==5)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()+1.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+4.0);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==6)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()+2.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+3.0);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==7)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()+3.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+2.0);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
        else if( balas.at(i)->getNumBala()==8)
        {
            balas.at(i)->setPosx(balas.at(i)->getPosx()+4.0);
            balas.at(i)->setPosy(balas.at(i)->getPosy()+1.0);
            balas.at(i)->setPos(balas.at(i)->getPosx(),balas.at(i)->getPosy());
        }
    }
}

void boss1::lluviaNotas(QList<bala *> balas)
{
    for ( int i = 0 ; i < balas.size(); i++)
    {
        balas.at(i)->caidaLibre(0.009);
    }
}

//void boss1::sacarBichitos(QList<arabe *> balas, personaje *jugador)
//{
//    for ( int i = 0 ; i < balas.size() ; i++)
//    {
//        if ( jugador->getPosx() < balas.at(i)->getPosx())
//        {
//            balas.at(i)->animarIzquierda();
//            balas.at(i)->moverIzquierda(0.04);
//        }
//        else if (  jugador->getPosx() > balas.at(i)->getPosx())
//        {
//            balas.at(i)->animarDerecha();
//            balas.at(i)->moverDerecha(0.04);
//        }
//        else if (  jugador->getPosy() > balas.at(i)->getPosx())
//        {
//            balas.at(i)->animarAbajo();
//            balas.at(i)->moverAbajo(0.04);
//        }
//        else if (  jugador->getPosy() < balas.at(i)->getPosx())
//        {
//            balas.at(i)->animarArriba();
//            balas.at(i)->moverArriba(0.04);
//        }
//        balas.at(i)->moverIzquierda(0.04);
//    }
//}

void boss1::generarBalasEnSol()
{
}

int boss1::getNumBalas() const
{
    return numBalas;
}

void boss1::setNumBalas(int value)
{
    numBalas = value;
}

int boss1::getEscudo() const
{
    return escudo;
}

void boss1::setEscudo(int value)
{
    escudo = value;
}

int boss1::getVida() const
{
    return vida;
}

void boss1::setVida(int value)
{
    vida = value;
}

bool boss1::getMoviendome() const
{
    return moviendome;
}

void boss1::setMoviendome(bool value)
{
    moviendome = value;
}

bool boss1::getActivo() const
{
    return activo;
}

void boss1::setActivo(bool value)
{
    activo = value;
}

void boss1::animarIzquierda()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/diz1.png").scaled(100,100));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/diz2.png").scaled(100,100));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/diz3.png").scaled(100,100));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/diz1.png").scaled(100,100));
      animacion=0;
    }
     animacion++;
}

void boss1::animarDerecha()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/ddr1.png").scaled(100,100));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/ddr2.png").scaled(100,100));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/ddr3.png").scaled(100,100));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/ddr1.png").scaled(100,100));
      animacion=0;
    }
    animacion++;
}

void boss1::animarQuieto()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/afr1.png").scaled(100,100));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/afr2.png").scaled(100,100));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/afr3.png").scaled(100,100));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/afr1.png").scaled(100,100));
      animacion=0;
    }
    animacion++;
}

void boss1::animarIzquierdaSEBAS()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes2/iz1s.png").scaled(100,100));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes2/iz2s.png").scaled(100,100));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes2/iz3s.png").scaled(100,100));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes2/iz1s.png").scaled(100,100));
      animacion=0;
    }
    animacion++;
}

void boss1::animarDerechaSEBAS()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes2/dr1s.png").scaled(100,100));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes2/dr2s.png").scaled(100,100));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes2/dr3s.png").scaled(100,100));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes2/dr1s.png").scaled(100,100));
      animacion=0;
    }
    animacion++;
}
