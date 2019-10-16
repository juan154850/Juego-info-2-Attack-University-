#include "ganar.h"
#include "ui_ganar.h"

Ganar::Ganar(QString fileName,QString PassName,bool ganar_perder,int level,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ganar)
{
    ui->setupUi(this);    
    elNivel = level;
    uss = fileName;
    pass = PassName;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,600,600);
    ui->graphicsView->setScene(scene);
    ui->salir_del_juego->setVisible(false);
    ui->siguiente_nivel->setVisible(false);
    ui->volver_a_jugar->setVisible(false);
    ui->graphicsView->setFixedSize(600,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    if ( ganar_perder == true)
    {
        scene->setBackgroundBrush(QBrush(QImage(":/imagenes/youwin.png")));
        ui->salir_del_juego->setVisible(true);        
        ui->siguiente_nivel->setVisible(true);
    }
    else
    {
        scene->setBackgroundBrush(QBrush(QImage(":/imagenes/gameOver.png")));
        ui->salir_del_juego->setVisible(true);
        ui->volver_a_jugar->setVisible(true);
    }
}

Ganar::~Ganar()
{
    delete ui;
}

void Ganar::on_salir_del_juego_clicked()
{
    close();
}

void Ganar::on_volver_a_jugar_clicked()
{
    if ( elNivel ==1)
    {
        nivel1 *jugar;
        jugar = new nivel1(uss,pass,false,1);
        close();
        jugar->show();
    }
    else if ( elNivel ==2)
    {
        nivel2 *jugar;
        jugar = new nivel2(uss,pass,false,2);
        close();
        jugar->show();
    }

}

void Ganar::on_siguiente_nivel_clicked()
{
    nivel2 *jugar;
    jugar = new nivel2(uss,pass,false,2);
    close();
    jugar->show();
}
