#ifndef ARABE_H
#define ARABE_H
#include <personaje.h>
#include <soldado.h>

class arabe:public personaje
{
public:
    arabe();    
    int getDistancia() const;
    void setDistancia(int value);


    bool getExplotar() const;
    void setExplotar(bool value);

private:
    double posx;
    double posy;
    double width;
    double high;
    double vx=200;
    double vy=200;
    int vida=70;
    int Distancia;
    bool explotar = false;

};

#endif // ARABE_H
