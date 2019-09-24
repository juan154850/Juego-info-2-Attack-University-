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
#include <typeinfo>

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
    void generarBordes(void);
    void generarSoldados(void);


public slots:   
    void moverSoldado(void);
    void moverArabe(void);
    void generarArabe(void);    
    void colisionArabe(void);
    void moverBalasJugador(void);
    void dispararSoldado(void);   
    void dispararBoss(void);
    void ColisionBalasBoss(void);
    void CBJCS(void);
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
    QTimer *t_CBJCS;
    QTimer *tiempo;    
    QTimer *mover_Soldado;
    QTimer *mover_arabe;    
    QTimer *generar_arabes;
    QTimer *colision_arabe;
    QTimer *balas_soldado;
    QTimer *balasB;
    QTimer *timerGBB;    
    QTimer *timerColisionBalasBoss;



    //listas
    QList<bala*>balas;
    QList<bala*>balasJugador;
    QList<soldado*>soldados;
    QList<arabe*>arabes;    
    QList<bala*>L_balasBoss;    

    //muros
    QGraphicsLineItem *izq1;
    QGraphicsLineItem *drch1;
    QGraphicsLineItem *abaj1;
    QGraphicsLineItem *abaj2;
    QGraphicsLineItem *abaj3;
    QGraphicsLineItem *arrib1;
    QGraphicsLineItem *arrib2;
    QGraphicsLineItem *arrib3;
    QGraphicsLineItem *puenteIzq1;
    QGraphicsLineItem *puenteIzq2;






    //otros
    char dire='W'; //controla la direccio en la que van las balas.    
    double distancia; //calcula la distancia que hay entre un bicho y el personaje
    int adds=0; //tiene el valor de la cantidad de adds que hay por sala
    int addsAra=0; // cantidad de arabes por sala
    int nBala=1;    //para dar diferentes direcciones a las balas del primer boss    


};

#endif // NIVEL1_H
