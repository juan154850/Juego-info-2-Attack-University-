#ifndef BOSS1_H
#define BOSS1_H
#include <personaje.h>
#include <bala.h>
#include <arabe.h>
class boss1 : public personaje
{
public:
    boss1();
    //funciones direfentes que realice este boss
    void dispararIzquierda(bala *bala);
    void dispararDerecha(bala *bala);        
    int getDelayDisparo() const;
    void setDelayDisparo(int value);
    void dispararEnSol(QList<bala*>balas);
    void lluviaNotas(QList<bala*>balas);
    //void sacarBichitos(QList <arabe*>balas, personaje *jugador);
    void generarBalasEnSol(void);

    int getNumBalas() const;
    void setNumBalas(int value);

    int getEscudo() const;
    void setEscudo(int value);

    int getVida() const;
    void setVida(int value);

    bool getMoviendome() const;
    void setMoviendome(bool value);

    bool getActivo() const;
    void setActivo(bool value);


    void animarIzquierda();
    void animarDerecha();
    void animarQuieto();
    void animarIzquierdaSEBAS();
    void animarDerechaSEBAS();

private:
    QList<bala*>misBalas;
    //atributos especiales de un boss
    int escudo=500;
    int vida=500;
    int delayDisparo=30;
    int numBalas=1;
    bool moviendome=false;
    bool activo = false;
    int animacion=0;

};

#endif // BOSS1_H
