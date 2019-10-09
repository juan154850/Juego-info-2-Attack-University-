#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QGraphicsPixmapItem>

class obstaculos : public QGraphicsPixmapItem
{
public:
    obstaculos(int posx, int posy, int anchoo, int altoo);
    bool getAgujero() const;
    void setAgujero(bool value);

private:
    int px;
    int py;
    int ancho;
    int alto;
    bool agujero = false;




};

#endif // OBSTACULOS_H
