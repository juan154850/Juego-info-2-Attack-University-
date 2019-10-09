#include "boss1.h"

boss1::boss1() : personaje (0,0,55,60,100,100)
{
    setPixmap(QPixmap(":/imagenes/personaje1.png"));
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
