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

void arabe::animarIzquierda()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/araIz1.png").scaled(45,50));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/araIz2.png").scaled(45,50));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/araIz3.png").scaled(45,50));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/araIz1.png").scaled(45,50));
      animacion=0;
    }
     animacion++;
}

void arabe::animarDerecha()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/araDr1.png").scaled(45,50));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/araDr2.png").scaled(45,50));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/araDr3.png").scaled(45,50));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/araDr1.png").scaled(45,50));
      animacion=0;
    }
    animacion++;
}

void arabe::animarArriba()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/arabeEs1.png").scaled(45,50));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/arabeEs2.png").scaled(45,50));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/arabeEs3.png").scaled(45,50));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/arabeEs3.png").scaled(45,50));
      animacion=0;
    }
    animacion++;
}

void arabe::animarAbajo()
{
    if (animacion<= 4)
    {
        setPixmap(QPixmap(":/imagenes/arabeFr1.png").scaled(45,50));
    }
    if (animacion>4 && animacion <=8)
    {
        setPixmap(QPixmap(":/imagenes/arabeFr2.png").scaled(45,50));
    }
    if (animacion>8 && animacion <=12)
    {
        setPixmap(QPixmap(":/imagenes/arabeFr3.png").scaled(45,50));
    }
    if( animacion >= 13)
    {
      setPixmap(QPixmap(":/imagenes/arabeFr1.png").scaled(45,50));
      animacion=0;
    }
    animacion++;
}

bool arabe::getExplotar() const
{
    return explotar;
}

void arabe::setExplotar(bool value)
{
    explotar = value;
}

int arabe::getVida() const
{
    return vida;
}

void arabe::setVida(int value)
{
    vida = value;
}

char arabe::getDire() const
{
    return dire;
}

void arabe::setDire(char value)
{
    dire = value;
}
