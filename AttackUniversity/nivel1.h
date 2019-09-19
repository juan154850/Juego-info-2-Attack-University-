#ifndef NIVEL1_H
#define NIVEL1_H
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <personaje.h>
#include <QTimer>
#include "bala.h"
#include <QList>
#include "soldado.h"
#include "arabe.h"
#include <math.h>
#include <time.h>
namespace Ui {
class nivel1;
}

class nivel1 : public QWidget
{
    Q_OBJECT

public:
    explicit nivel1(QWidget *parent = nullptr);
    ~nivel1();
    void keyPressEvent(QKeyEvent *ev);

public slots:
    void actualizar(void);
    void moverSoldado(void);
    void generarSoldados(void);

private:
    Ui::nivel1 *ui;
    //jugador
    personaje *jugador;


    //escena
    QGraphicsScene *scene;


    //timers
    QTimer *tiempo;    
    QTimer *mover_Soldado;
    QTimer *generar_soldados;


    //listas
    QList<bala*>balas;
    QList<soldado*>soldados;
    QList<arabe*>arabes;    

    //otros
    char dire='W'; //controla la direccio en la que van las balas.
    double distancia; //calcula la distancia que hay entre un bicho y el personaje
    int adds=0;
    int animar;
    bool moverse = true;

};

#endif // NIVEL1_H
