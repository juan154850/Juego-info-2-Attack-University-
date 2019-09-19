#ifndef SOLDADO_H
#define SOLDADO_H
#include <personaje.h>

class soldado : public personaje
{
public:
    soldado();
    soldado(double px, double py, double w,  double h);
    void moverAb(double dt);
    void moverAr(double dt);
    void moverIz(double dt);
    void moverDr(double dt);

    double getDistancia() const;
    void setDistancia(int value);

    char getDir() const;
    void setDir(char value);

private:
    double posx;
    double posy;
    double width; //ancho
    double high; //alto
    double vx =100;
    double vy = 100;
    int vida=100;
    int distancia= 0;
    char dir='W';

};

#endif // SOLDADO_H
