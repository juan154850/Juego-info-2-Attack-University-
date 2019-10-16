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
    void animarIzquierda();
    void animarDerecha();
    void animarArriba();
    void animarAbajo();

    bool getExplotar() const;
    void setExplotar(bool value);

    int getVida() const;
    void setVida(int value);

    char getDire() const;
    void setDire(char value);

private:
    double posx;
    double posy;
    double width;
    double high;
    double vx=200;
    double vy=200;
    int vida=35;
    int Distancia;
    bool explotar = false;
    char dire;
    int animacion=0;

};

#endif // ARABE_H
