#ifndef NIVEL2_H
#define NIVEL2_H
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
#include<stdlib.h>
#include <QDebug>
#include <boss1.h>
#include <typeinfo>
#include <obstaculos.h>
#include <QMediaPlayer>
#include <QString>
#include <QFile>
#include <fstream>
#include <QDialog>

using namespace std;
namespace Ui {
class nivel2;
}

class nivel2 : public QDialog
{
    Q_OBJECT

public:
    explicit nivel2(QString fileName,QString PassName,bool cargar,QWidget *parent = nullptr);
    ~nivel2();
    void keyPressEvent(QKeyEvent *ev);
    void generarBordes(void);
    void generarSoldados(void);
    void CBJCS(bala *LaBala);
    void CBSCM(bala *LaBalaDelSoldado);
    void ColisionArabesYSoldados(soldado *solda);
    void generarObstaculos(void);
    void jefeFinal();
    void generarArabe(void);
    void pausa();
    void cargarPartida();
    void nuevaPartida();
    void nuevaPartida(int posx, int posy, int numOleada_, int numSala, int VidaJugador);
    void colisionConMesasETC();

public slots:
    void moverSoldado(void);//YA
    void moverArabe(void);
    void Puertas(void);
    void colisionArabe(void);
    void moverBalasJugador(void);
    void dispararSoldado(void);
    void dispararBoss(void);
    void ColisionBalasBoss(void);
    void generarBalasBoss(void);
    void moverBoss(void);
    void CBJCB(void);
    void colisionesJugador(void);
    void dialogos(void);
    void oleadas(void);
    void colisionBalasConMesasETC();
    void MoverYColisionBolasDeFuego();

private slots:
    void on_ARDUINO_clicked();

    void on_GUARDAPARTIDA_clicked();

    void on_SALIR_clicked();

    void on_pushButton_clicked();

private:
    Ui::nivel2 *ui;
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
    QTimer *colision_arabe;
    QTimer *balas_soldado;
    QTimer *balasB;
    QTimer *timerGBB;
    QTimer *timerColisionBalasBoss;
    QTimer *timerMoverBoss;
    QTimer *timerCBJCB;
    QTimer *timerColisionesJugador;
    QTimer *lvl1;
    QTimer *dialog;
    QTimer *oleada;
    QTimer *puertas;
    QTimer *timerColisionDeMesas;
    QTimer *Timer_MoverYColisionBolasDeFuego;





    //listas
    QList<bala*>balas; //balas del soldado
    QList<bala*>balasJugador;
    QList<soldado*>soldados;
    QList<arabe*>arabes;
    QList<bala*>L_balasBoss;
    QList<QGraphicsLineItem*> obs;
    QList<obstaculos*> mesas;
    QList<obstaculos*>bolasDeFuego;
    //muros POR CAMBIAR
    QGraphicsLineItem *izq1;
    QGraphicsLineItem *drch1;
    QGraphicsLineItem *abaj1;
    QGraphicsLineItem *abaj2;
    QGraphicsLineItem *abaj2Copia;
    QGraphicsLineItem *abaj3;
    QGraphicsLineItem *arrib1;
    QGraphicsLineItem *arrib1Copia;
    QGraphicsLineItem *arrib2;
    QGraphicsLineItem *arrib2Copia;
    QGraphicsLineItem *arrib3;
    QGraphicsLineItem *puenteIzq1;
    QGraphicsLineItem *puenteDrch1;
    QGraphicsLineItem *puenteIzq2;
    QGraphicsLineItem *puenteDrch2;
    QGraphicsLineItem *puertaBoss;
    QGraphicsLineItem *puertaSala1;
    QGraphicsLineItem *puertaSala2;
    QGraphicsLineItem *puertaSala3;

    //mesas POR CAMBIAR
    obstaculos *mesa1; //mesas son los condensadores
    obstaculos *mesa2;
    obstaculos *mesa3;
    obstaculos *mesa4;
    obstaculos *barril1; //barriles son las bobinas
    obstaculos *barril2;
    obstaculos *barril3;
    obstaculos *barril4;
    obstaculos *trincho1; //trinchos son los leds
    obstaculos *trincho2;
    obstaculos *trincho3;
    obstaculos *trincho4;
    obstaculos *caja1; //puede ser cualquiera
    obstaculos *caja2;
    obstaculos *obj1;
    obstaculos *obj2;
    obstaculos *obj3;
    obstaculos *obj4;
    obstaculos *obj5;
    obstaculos *obj6;
    //agujero negro
    obstaculos *agujeroNegro;
    //bolas de fuego con movimiento circular
    obstaculos *bolaDeFuego1;
    obstaculos *bolaDeFuego2;
    obstaculos *bolaDeFuego3;
    obstaculos *bolaDeFuego4;
    obstaculos *bolaDeFuego5;
    obstaculos *bolaDeFuego6;



    //otros
    char dire='W'; //controla la direccio en la que van las balas.
    double distancia; //calcula la distancia que hay entre un bicho y el personaje
    int adds=0; //tiene el valor de la cantidad de adds que hay por sala
    int addsAra=0; // cantidad de arabes por sala
    int nBala=1;    //para dar diferentes direcciones a las balas del primer boss
    int dirBala=1;
    int movimientoSebastian;
    int contador=0;
    int margenError=0;
    int mermarVida=99;
    int poder=1;
    QMediaPlayer *dialogosSebastian;
    QMediaPlayer *musica;
    QMediaPlayer *efectos;
    int numOleada=4;
    int sala=2;
    bool salaCompleta=false;
    bool pausa_ = false;
    QString uss;
    QString pass;
    int delayDisparar=10;
    bool colision=false;

};

#endif // NIVEL2_H