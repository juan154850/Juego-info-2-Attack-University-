#ifndef BOSS1_H
#define BOSS1_H
#include <personaje.h>
#include <bala.h>
class boss1 : public personaje
{
public:
    boss1();
    //funciones direfentes que realice este boss
    void dispararIzquierda(bala *bala);
    void dispararDerecha(bala *bala);
    void dispararIzquierda2(bala *bala);
    int getDelayDisparo() const;
    void setDelayDisparo(int value);

    int getNumBalas() const;
    void setNumBalas(int value);

private:
    //atributos especiales de un boss
    int escudo=500;
    int delayDisparo=30;
    int numBalas=1;

};

#endif // BOSS1_H
