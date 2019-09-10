#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
class personaje: public QGraphicsPixmapItem
{    
public:
    personaje(double px, double py, float w, float h,double _vx, double _vy);
    void moverIzquierda();
    void moverDerecha();
    void moverArriba();
    void moverAbajo();

    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    float getWidth() const;
    void setWidth(float value);

    float getHigh() const;
    void setHigh(float value);

    int getVida() const;
    void setVida(int value);

    double getVx() const;
    void setVx(double value);

    double getVy() const;
    void setVy(double value);

private:
    double posx=0;
    double posy=0;
    float width=0;
    float high=0;
    double vx=0;
    double vy=0;
    double dt=0.1;
    int vida=0;

};

#endif // PERSONAJE_H
