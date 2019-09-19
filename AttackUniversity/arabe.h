#ifndef ARABE_H
#define ARABE_H
#include <personaje.h>


class arabe:public personaje
{
public:
    arabe();
    arabe(double px, double py, double w,  double h);
private:
    double posx;
    double posy;
    double width;
    double high;
    double vx=200;
    double vy=200;
    int vida=70;

};

#endif // ARABE_H
