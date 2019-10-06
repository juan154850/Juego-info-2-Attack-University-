#ifndef SOLDADO_H
#define SOLDADO_H
#include <personaje.h>
#include <QGraphicsPixmapItem>
class soldado : public QGraphicsPixmapItem
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

    int getDistanciaX() const;
    void setDistanciaX(int value);

    bool getMoverse() const;
    void setMoverse(bool value);

    int getContadorBalas() const;
    void setContadorBalas(int value);

    int getDistanciaEntreSoldados() const;
    void setDistanciaEntreSoldados(int value);

    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    int getDistanciaEntreSoldadosY() const;
    void setDistanciaEntreSoldadosY(int value);

    int getVida() const;
    void setVida(int value);

private:
    double posx;
    double posy;
    double width; //ancho
    double high; //alto
    double vx =100;
    double vy = 100;
    int vida=50;
    int distancia= 0;
    int distanciaX=0;
    char dir='S';
    bool moverse=true;
    int contadorBalas=60;
    int distanciaEntreSoldados=0;
    int distanciaEntreSoldadosY=0;

};

#endif // SOLDADO_H
