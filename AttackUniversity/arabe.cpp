#include "arabe.h"

arabe::arabe()
{

}

arabe::arabe(double px, double py, double w, double h)
{
    posx  =px;
    posy=py;
    width=w;
    high=h;
    setPixmap(QPixmap(":/imagenes/personaje1.png")); // se le asigna la imagen al add
    setPos(posx,posy);

}
