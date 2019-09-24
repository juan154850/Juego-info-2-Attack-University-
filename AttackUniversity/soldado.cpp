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

int soldado::getDistanciaEntreSoldados() const
{
    return distanciaEntreSoldados;
}

void soldado::setDistanciaEntreSoldados(int value)
{
    distanciaEntreSoldados = value;
}

double soldado::getPosx() const
{
    return posx;
}

void soldado::setPosx(double value)
{
    posx = value;
}

double soldado::getPosy() const
{
    return posy;
}

void soldado::setPosy(double value)
{
    posy = value;
}

int soldado::getDistanciaEntreSoldadosY() const
{
    return distanciaEntreSoldadosY;
}

void soldado::setDistanciaEntreSoldadosY(int value)
{
    distanciaEntreSoldadosY = value;
}

int soldado::getVida() const
{
    return vida;
}

void soldado::setVida(int value)
{
    vida = value;
}

void soldado::moverAb(double dt)
{
    
    posy=posy+(vy*dt);
    setY(posy);
    dir='S';
}
