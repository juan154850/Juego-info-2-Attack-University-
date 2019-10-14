#include "personaje.h"

//personaje::personaje()
//{

//}

personaje::personaje(double px, double py, float w, float h,double _vx, double _vy)
{
    posx = px;
    posy = py;
    width = w;
    high = h;
    vx=_vx;
    vy=_vy;
    setPos(posx,posy);
    setPixmap(QPixmap(":/imagenes/jugadorAtrasDerecho.png").scaled(45,50));
}

void personaje::moverIzquierda(double dt)
{
    posx=posx-(vx*dt);
    setX(posx);
}

void personaje::moverDerecha(double dt)
{
    posx=posx+(vx*dt);
    setX(posx);
}

void personaje::moverArriba(double dt)
{
    posy=posy-(vy*dt);
    setY(posy);
}

void personaje::moverAbajo(double dt)
{
    posy=posy+(vy*dt);
    setY(posy);
}


double personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(double value)
{
    posx = value;
    setX(posx);
}

void personaje::animacionArriba()
{        
        if (animacion<= 4)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAtrasIzquierdo.png").scaled(45,50));
        }
        if (animacion>4 && animacion <=8)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAtrasDerecho.png").scaled(45,50));
        }
        if (animacion>8 && animacion <=12)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAtrasQuieto.png").scaled(45,50));
        }
        if( animacion >= 13)
        {
          setPixmap(QPixmap(":/imagenes/jugadorAtrasQuieto.png").scaled(45,50));
          animacion=0;
        }
        animacion++;
}

void personaje::animacionAbajo()
{
        if (animacion<= 4)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAdelantePieIzquierdo.png").scaled(45,50));
        }
        if (animacion>4 && animacion <=8)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAdelantePieDerecho.png").scaled(45,50));
        }
        if (animacion>8 && animacion <=12)
        {
            setPixmap(QPixmap(":/imagenes/jugadorAdelanteQuieto.png").scaled(45,50));
        }
        if( animacion >= 13)
        {
          setPixmap(QPixmap(":/imagenes/jugadorAdelanteQuieto.png").scaled(45,50));
          animacion=0;
        }
        animacion++;
}

void personaje::animacionIzquierda()
{
        if (animacion<= 4)
        {
            setPixmap(QPixmap(":/imagenes/jugadorIzquierda1.png").scaled(45,50));
        }
        if (animacion>4 && animacion <=8)
        {
            setPixmap(QPixmap(":/imagenes/jugadorIzquierda2.png").scaled(45,50));
        }
        if (animacion>8 && animacion <=12)
        {
            setPixmap(QPixmap(":/imagenes/jugadorParadoIzquierda.png").scaled(45,50));
        }
        if( animacion >= 13)
        {
          setPixmap(QPixmap(":/imagenes/jugadorParadoIzquierda.png").scaled(45,50));
          animacion=0;
        }
         animacion++;
}

void personaje::animacionDerecha()
{
        if (animacion<= 4)
        {
            setPixmap(QPixmap(":/imagenes/jugadorDerecha1.png").scaled(45,50));
        }
        if (animacion>4 && animacion <=8)
        {
            setPixmap(QPixmap(":/imagenes/jugadorDerecha2.png").scaled(45,50));
        }
        if (animacion>8 && animacion <=12)
        {
            setPixmap(QPixmap(":/imagenes/jugadorParadoDerecha.png").scaled(45,50));
        }
        if( animacion >= 13)
        {
          setPixmap(QPixmap(":/imagenes/jugadorParadoDerecha.png").scaled(45,50));
          animacion=0;
        }
        animacion++;
}

double personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(double value)
{
    posy = value;
    setY(posy);
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

int personaje::getAnimacion() const
{
    return animacion;
}

void personaje::setAnimacion(int value)
{
    animacion = value;
}

int personaje::getDamage() const
{
    return damage;
}

void personaje::setDamage(int value)
{
    damage = value;
}
