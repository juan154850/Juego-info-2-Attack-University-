#include "obstaculos.h"


obstaculos::obstaculos(int posx, int posy, int anchoo, int altoo)
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
