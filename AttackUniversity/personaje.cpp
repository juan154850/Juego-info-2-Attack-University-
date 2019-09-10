#include "personaje.h"

personaje::personaje(double px, double py, float w, float h,double _vx, double _vy)
{
    posx = px;
    posy = py;
    width = w;
    high = h;
    vx=_vx;
    vy=_vy;
    setPos(posx,posy);
}

void personaje::moverIzquierda()
{
    posx=posx-(vx*dt);
}

void personaje::moverDerecha()
{
    posx=posx+(vx*dt);
}

void personaje::moverArriba()
{
    posy=posy-(vy*dt);
}

void personaje::moverAbajo()
{
    posy=posy+(vy*dt);
}

double personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(double value)
{
    posx = value;
}

double personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(double value)
{
    posy = value;
}

float personaje::getWidth() const
{
    return width;
}

void personaje::setWidth(float value)
{
    width = value;
}

float personaje::getHigh() const
{
    return high;
}

void personaje::setHigh(float value)
{
    high = value;
}

int personaje::getVida() const
{
    return vida;
}

void personaje::setVida(int value)
{
    vida = value;
}

double personaje::getVx() const
{
    return vx;
}

void personaje::setVx(double value)
{
    vx = value;
}

double personaje::getVy() const
{
    return vy;
}

void personaje::setVy(double value)
{
    vy = value;
}
