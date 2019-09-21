#include "arabe.h"

arabe::arabe() : personaje (0,0,0,0,100,100)
{

    setPixmap(QPixmap(":/imagenes/personaje1.png")); // se le asigna la imagen al add
    setPos(posx,posy);
}

int arabe::getDistancia() const
{
    return Distancia;
}

void arabe::setDistancia(int value)
{
    Distancia = value;
}

bool arabe::getExplotar() const
{
    return explotar;
}

void arabe::setExplotar(bool value)
{
    explotar = value;
}
