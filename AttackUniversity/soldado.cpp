#include "soldado.h"

soldado::soldado()
{

}

soldado::soldado(double px, double py, double w, double h)
{
    posx = px;
    posy = py;
    width = w;
    high = h ;
    setPixmap(QPixmap(":/imagenes/avt3_fr1.png")); // se le asigna la imagen al add
    setPos(posx,posy);

}

void soldado::moverAr(double dt)
{
    posy=posy-(vy*dt);
    setY(posy);
    dir = 'W';
}

void soldado::moverIz(double dt)
{
    posx=posx-(vx*dt);
    setX(posx);
    dir = 'A';
}

void soldado::moverDr(double dt)
{
    posx=posx+(vx*dt);
    setX(posx);
    dir = 'D';
}


double soldado::getDistancia() const
{
    return distancia;
}

void soldado::setDistancia(int value)
{
    distancia = value;
}

char soldado::getDir() const
{
    return dir;
}

void soldado::setDir(char value)
{
    dir = value;
}

int soldado::getDistanciaX() const
{
    return distanciaX;
}

void soldado::setDistanciaX(int value)
{
    distanciaX = value;
}

bool soldado::getMoverse() const
{
    return moverse;
}

void soldado::setMoverse(bool value)
{
    moverse = value;
}

int soldado::getContadorBalas() const
{
    return contadorBalas;
}

void soldado::setContadorBalas(int value)
{
    contadorBalas = value;
}

void soldado::moverAb(double dt)
{

    posy=posy+(vy*dt);
    setY(posy);
    dir='S';
}
