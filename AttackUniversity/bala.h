#ifndef BALA_H
#define BALA_H
#include <QGraphicsPixmapItem>

class bala : public QGraphicsPixmapItem
{
public:
    bala(double x, double y, double w, double h,char dir);
    //-------------------movimiento de la particula-------------------
    void moverBala();
    void moverIzquierda(double dt);
    void moverDerecha(double dt);
    void moverArriba(double dt);
    void moverAbajo(double dt);
    void moverDiagonalIzquierda(double dt);
    void moverDiagonalDerecha(double dt);
    //-------------------metodos get y set-------------------
    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    double getWidth() const;
    void setWidth(double value);

    double getHigh() const;
    void setHigh(double value);

    double getVx() const;
    void setVx(double value);

    double getVy() const;
    void setVy(double value);


    char getDireccion() const;
    void setDireccion(char value);

private:
    //-------------------atributos-------------------
    double posx;
    double posy;
    double width; //ancho
    double high; //alto
    double vx=200;
    double vy=200;
    char direccion='W'; //esta variable indica la direccion en que se esta disparando.
};

#endif // BALA_H
