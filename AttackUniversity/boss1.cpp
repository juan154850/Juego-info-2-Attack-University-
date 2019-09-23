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

void boss1::dispararIzquierda2(bala *bala)
{
    bala->setPosx((bala->getPosx()-(bala->getVx()*0.04))-4);
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

int boss1::getNumBalas() const
{
    return numBalas;
}

void boss1::setNumBalas(int value)
{
    numBalas = value;
}
