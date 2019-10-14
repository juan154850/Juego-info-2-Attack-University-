#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
class personaje: public QGraphicsPixmapItem
{    
public:    
    personaje(double px, double py, float w, float h,double _vx, double _vy);     //sobrecarga
    void moverIzquierda(double dt);
    void moverDerecha(double dt);
    void moverArriba(double dt);
    void moverAbajo(double dt);    
    double getPosx() const;
    void setPosx(double value);
    void animacionArriba(void);
    void animacionAbajo(void);
    void animacionIzquierda(void);
    void animacionDerecha(void);
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

    int getAnimacion() const;
    void setAnimacion(int value);

    int getDamage() const;
    void setDamage(int value);

private:
    int animacion=0;
    double posx=0;
    double posy=0;
    float width=0;
    float high=0;
    double vx=0;
    double vy=0;    
    int vida=100;
    int damage = 5;
    char dire;


};

#endif // PERSONAJE_H
