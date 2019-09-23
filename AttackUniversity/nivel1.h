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
#include <QDebug>
#include <boss1.h>
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
    void moverSoldado(void);
    void generarSoldados(void);
    void moverArabe(void);
    void generarArabe(void);    
    void colisionArabe(void);
    void moverBalasJugador(void);
    void dispararSoldado(void);   
    void dispararBoss(void);
    void balasBoss(void);
    void generarBalasBoss(void);

private:
    Ui::nivel1 *ui;
    //jugador
    personaje *jugador;
    //Boss
    boss1 *sebastian;

    //escena
    QGraphicsScene *scene;


    //timers
    QTimer *tiempo;    
    QTimer *mover_Soldado;
    QTimer *mover_arabe;
    QTimer *generar_soldados;
    QTimer *generar_arabes;
    QTimer *colision_arabe;
    QTimer *balas_soldado;
    QTimer *balasB;
    QTimer *timerGBB;


    //listas
    QList<bala*>balas;
    QList<bala*>balasJugador;
    QList<soldado*>soldados;
    QList<arabe*>arabes;    
    QList<bala*>L_balasBoss;

    //bloqueo de la camara
    bool sala1=true;
    QGraphicsLineItem * L_true;
    QGraphicsLineItem *L_false;


    //otros
    char dire='W'; //controla la direccio en la que van las balas.    
    double distancia; //calcula la distancia que hay entre un bicho y el personaje
    int adds=0;
    int addsAra=0;
    int animar;
    bool moverse = true;
    int contadoBalas = 30;   
    int nBala=1;

};

#endif // NIVEL1_H
