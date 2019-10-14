#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QGraphicsPixmapItem>
#include <math.h>
#include <personaje.h>
class obstaculos : public QGraphicsPixmapItem
{
public:
    obstaculos(double posx, double posy, int anchoo, int altoo);
    bool getAgujero() const;
    void setAgujero(bool value);
    void movimientoCircular();
    void atraccionGravitacional(personaje *elJugador);

    bool getTragadoxD() const;
    void setTragadoxD(bool value);

private:
    double px;
    double py;
    int ancho;
    int alto;
    bool agujero = false;
    double anguloRad=0;
    double angulo=0;
    double radio =5;
    bool tragadoxD=false;



};

#endif // OBSTACULOS_H
