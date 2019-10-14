#include "obstaculos.h"


obstaculos::obstaculos(double posx, double posy, int anchoo, int altoo)
{
    px= posx;
    py = posy;
    ancho = anchoo;
    alto = altoo;
    setPixmap(QPixmap(":/imagenes/mesa.png").scaled(40,40));
    setPos(px,py);
}

bool obstaculos::getAgujero() const
{
    return agujero;
}

void obstaculos::setAgujero(bool value)
{
    agujero = value;
}

void obstaculos::movimientoCircular()
{
    anguloRad=angulo*3.14/180;
    px= px+radio*cos(anguloRad);
    py=py+radio*sin(anguloRad);
    setPos(px,py);
    angulo+=5;
    if (angulo>=360)
    {
        angulo=0;
    }
}

void obstaculos::atraccionGravitacional(personaje *elJugador)
{
    if( px > elJugador->getPosx())
    {
        elJugador->moverDerecha(0.05);
    }
    else
    {
        elJugador->moverIzquierda(0.05);
    }
    if( py< elJugador->getPosy())
    {
        elJugador->moverArriba(0.05);


    }
    else
    {
        elJugador->moverAbajo(0.05);
    }
}

bool obstaculos::getTragadoxD() const
{
    return tragadoxD;
}

void obstaculos::setTragadoxD(bool value)
{
    tragadoxD = value;
}
