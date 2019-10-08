#include "bala.h"

bala::bala(double x, double y, double w, double h, char dir)
{
    posx= x;
    posy = y;
    width = w ;
    high = h;
    setPos(x,y);
    direccion = dir;
    switch (direccion)
    {
        case ('A'):
        {
            setPixmap(QPixmap(":/imagenes/bullet.png").scaled(10,10));
            break;
        }

        case('D'):
        {
             setPixmap(QPixmap(":/imagenes/bulletDr.png").scaled(10,10));
            break;
        }
        case('W'):
        {
            setPixmap(QPixmap(":/imagenes/bulletAr.png").scaled(10,10));
            break;
        }
        case('S'):
        {
            setPixmap(QPixmap(":/imagenes/bulletAb.png").scaled(10,10));
            break;
        }

    }

}


void bala::moverBala()
{
    switch (direccion)
    {
    case ('A'):
    {
        //movemos la bala hacia la izquierda
        moverIzquierda(0.06);
        break;
    }
    case ('D'):
    {
        //movemos la bala hacia la derecha
        moverDerecha(0.06);
        break;
    }
    case('W'):
    {
        //movemos la bala hacia arriba
        moverArriba(0.06);
        break;
    }
    case ('S'):
    {
        //movemos la bala hacia abajo
        moverAbajo(0.06);
        break;
    }
    }
}

void bala::moverIzquierda(double dt)
{
    posx= posx-(vx*dt);
    setX(posx);
}

void bala::moverDerecha(double dt)
{
    posx= posx+(vx*dt);
    setX(posx);
}

void bala::moverArriba(double dt)
{
    posy=posy-(vy*dt);
    setY(posy);
}

void bala::moverAbajo(double dt)
{
    posy=posy+(vy*dt);
    setY(posy);
}

void bala::moverDiagonalIzquierda(double dt)
{
    posx= posx-(vx*dt);
    posy=posy+(vy*dt);
    setPos(posx,posy);
}

void bala::moverDiagonalDerecha(double dt)
{
    posx= posx+(vx*dt);
    posy=posy+(vy*dt);
    setPos(posx,posy);
}

void bala::animar()
{
    setRotation(angulo);
    angulo+=10;
}

double bala::getPosx() const
{
    return posx;
}

void bala::setPosx(double value)
{
    posx = value;
}

double bala::getPosy() const
{
    return posy;
}

void bala::setPosy(double value)
{
    posy = value;
}

double bala::getWidth() const
{
    return width;
}

void bala::setWidth(double value)
{
    width = value;
}

double bala::getHigh() const
{
    return high;
}

void bala::setHigh(double value)
{
    high = value;
}

double bala::getVx() const
{
    return vx;
}

void bala::setVx(double value)
{
    vx = value;
}

double bala::getVy() const
{
    return vy;
}

void bala::setVy(double value)
{
    vy = value;
}

char bala::getDireccion() const
{
    return direccion;
}

void bala::setDireccion(char value)
{
    direccion = value;
}

int bala::getNumBala() const
{
    return numBala;
}

void bala::setNumBala(int value)
{
    numBala = value;
}


