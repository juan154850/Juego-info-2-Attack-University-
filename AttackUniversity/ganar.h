#ifndef GANAR_H
#define GANAR_H

#include <QDialog>
#include <QGraphicsScene>
#include <nivel1.h>
#include <QMessageBox>
namespace Ui {
class Ganar;
}

class Ganar : public QDialog
{
    Q_OBJECT

public:
    explicit Ganar(QString fileName,QString PassName,bool ganar_perder, QWidget *parent = nullptr);
    ~Ganar();

private slots:
    void on_salir_del_juego_clicked();

    void on_volver_a_jugar_clicked();

    void on_siguiente_nivel_clicked();

private:
    Ui::Ganar *ui;
    QGraphicsScene * scene;
    QString uss;
    QString pass;

};

#endif // GANAR_H
