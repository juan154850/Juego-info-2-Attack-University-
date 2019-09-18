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

private:
    personaje *jugador;
    Ui::nivel1 *ui;
    QGraphicsScene *scene;
    QTimer *tiempo;    
    QList<bala*>balas;
    char dire;


    int animar;

};

#endif // NIVEL1_H
