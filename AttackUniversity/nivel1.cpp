#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QString fileName,QString PassName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);
    uss = fileName;
    pass = PassName;
    //-------------------zona de eventos-------------------

    scene = new QGraphicsScene();    
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/piso1.png")));
    scene->setSceneRect(0,0,800,600); //definimos el 0,0 de la escena


    //-------------------graficador-------------------

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800,600);



    //-------------------bloqueos-------------------

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    generarBordes();


    //-------------------player-------------------

    jugador = new personaje(382,-81,50,55,100,100);
    scene->addItem(jugador);
    scene->setFocusItem(jugador);

    //-------------------boss-------------------

    sebastian = new boss1();
    agujeroNegro = new obstaculos(356,-2780,30,30);



    //-------------------timers-------------------

    puertas = new QTimer ;
    connect(puertas, &QTimer::timeout, this, &nivel1::Puertas);
    puertas->start(1);


    oleada = new QTimer();
    connect(oleada, &QTimer::timeout, this, &nivel1::oleadas);
    oleada->start(5000);

    tiempo = new QTimer();
    connect(tiempo, &QTimer::timeout, this, &nivel1::moverBalasJugador);
//    tiempo->start(20);

    balas_soldado = new QTimer();
    connect(balas_soldado,&QTimer::timeout,this,&nivel1::dispararSoldado);
//    balas_soldado->start(20);

    mover_Soldado = new QTimer();
    connect(mover_Soldado,&QTimer::timeout,this,&nivel1::moverSoldado);
//    mover_Soldado->start(3000);

    mover_arabe = new QTimer();
    connect(mover_arabe,&QTimer::timeout,this,&nivel1::moverArabe);  

    colision_arabe =  new QTimer();    
    connect(colision_arabe, &QTimer::timeout,this,&nivel1::colisionArabe);    

    balasB = new QTimer();
    connect(balasB,&QTimer::timeout,this,&nivel1::dispararBoss);

    timerGBB = new QTimer();
    connect(timerGBB, &QTimer::timeout,this,&nivel1::generarBalasBoss);
//    timerGBB->start(20);

    timerColisionBalasBoss = new QTimer();
    connect(timerColisionBalasBoss, &QTimer::timeout,this,&nivel1::ColisionBalasBoss);
//    timerColisionBalasBoss->start(1);

    timerMoverBoss = new QTimer();
    connect(timerMoverBoss, &QTimer::timeout,this,&nivel1::moverBoss) ;
//    timerMoverBoss->start(20);

    timerCBJCB = new QTimer;
    connect(timerCBJCB, &QTimer::timeout,this,&nivel1::CBJCB) ;

    timerColisionesJugador =  new QTimer;
    connect(timerColisionesJugador,&QTimer::timeout,this,&nivel1::colisionesJugador);
//    timerColisionesJugador->start(20);

    lvl1 = new QTimer();
    connect(lvl1, &QTimer::timeout,this,&nivel1::jefeFinal);
    lvl1->start(20);

    dialog = new QTimer();
    connect(dialog, &QTimer::timeout,this,&nivel1::dialogos);
    dialog->start(10000);

    timerGBB->stop();
    timerColisionBalasBoss->stop();
    timerMoverBoss->stop();
    tiempo->start(20);

    //-------------------foco-------------------
    scene->setSceneRect(0,jugador->getPosy()-515,800,600);    
    ui->lcdNumber->setVisible(false);
    ui->lcdNumber_2->setVisible(false);
    ui->lcdNumber_3->setVisible(false);    
    generarObstaculos();
    dialogosAgusto=new QMediaPlayer;
    dialogosAgusto->setMedia(QUrl("qrc:/musica/llegaranecdota.mp3"));
    dialogosAgusto->setVolume(100);
    dialogosAgusto->play();
    ui->ARDUINO->setVisible(false);
    ui->GUARDAPARTIDA->setVisible(false);
    ui->SALIR->setVisible(false);
}

nivel1::~nivel1()
{
    delete ui;
}

void nivel1::keyPressEvent(QKeyEvent *ev)
{    

    ui->lcdNumber->display(jugador->getPosx());
    ui->lcdNumber_2->display(jugador->getPosy());    
    switch (ev->key())
    {

        case(Qt::Key_W):
    {
        dire = 'W';
        jugador->animacionArriba();
        if(!jugador->collidesWithItem(arrib1) && !jugador->collidesWithItem(arrib2)
                && !jugador->collidesWithItem(arrib3))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( !colisionConMesa())
            {
                if((jugador->getPosy()<=-1266 && jugador->getPosy()<= -2482 && jugador->getPosy()>=-2978))
                {
                    //para bloquear la camara en el ultimo nivel
                    jugador->moverArriba(0.04);
                }
                else
                {
                    jugador->moverArriba(0.04);
                    scene->setSceneRect(0,jugador->getPosy()-515,800,600);
                }
            }
            else
            {
                break;
            }


        }


        break;
    }
    case(Qt::Key_S):
    {
        dire = 'S';
        jugador->animacionAbajo();
        if(!jugador->collidesWithItem(abaj2) && !jugador->collidesWithItem(abaj1) && !jugador->collidesWithItem(abaj3))
        {
            if ( pausa_==true)
            {
                break;
            }
            if( !colisionConMesa())
            {
                if((jugador->getPosy()<=-1266 && jugador->getPosy()<= -2482 && jugador->getPosy()>=-2978))
                {
                    jugador->moverAbajo(0.04);
                }
                else
                {
                    jugador->moverAbajo(0.04);
                    scene->setSceneRect(0,jugador->getPosy()-515,800,600);
                }
            }
            else
            {
                break;
            }


        }
        break;
    }
    case(Qt::Key_D):
    {
        dire = 'D';
        jugador->animacionDerecha();
        if(!jugador->collidesWithItem(drch1))
        {
            if( pausa_==true)
            {
                break;
            }
            if( !colisionConMesa())
            {
                jugador->moverDerecha(0.04);
            }
            else
            {


                break;
            }


        }
        break;
    }
    case(Qt::Key_A):
    {
        dire = 'A';
        jugador->animacionIzquierda();
        if(!jugador->collidesWithItem(izq1) && !jugador->collidesWithItem(puenteIzq1) && !jugador->collidesWithItem(puenteIzq2))
        {
            if (pausa_==true)
            {
                break;
            }
            else
            {
                if( !colisionConMesa())
                {
                    jugador->moverIzquierda(0.04);
                }
                else
                {
                    break;
                }
            }


        }        
        break;
    }
    case (Qt::Key_Space):
    {
        if ( pausa_ == true)
        {
            break;
        }
        else
        {
            //-------------------creacion de balas-------------------
            balasJugador.append(new bala(jugador->getPosx()+8,jugador->getPosy()-10,20,20,dire));
            scene->addItem(balasJugador.last());
        }



//        timerCBJCB->start(1);
        break;
    }
    case(Qt::Key_P):
    {
        //parar todos los timers
        pausa();
        break;
    }
    }
}

void nivel1::generarBordes()
{
    izq1 =new QGraphicsLineItem(0,3000,0,0);
    izq1->setPos(40,-3000);
    izq1->setPen(QPen(Qt::transparent));
    scene->addItem(izq1);
    obs.push_back(izq1);
    drch1=(new QGraphicsLineItem(0,3000,0,0));
    drch1->setPen(QPen(Qt::transparent));
    drch1->setPos(760,-3000);
    scene->addItem(drch1);
    obs.push_back(drch1);
    abaj1=(new QGraphicsLineItem(800,0,0,0));
    abaj1->setPen(QPen(Qt::transparent));
    abaj1->setPos(0,-20);
    scene->addItem(abaj1);
    obs.push_back(abaj1);
    abaj2=(new QGraphicsLineItem(650,0,0,0));
    abaj2->setPen(QPen(Qt::transparent));
    abaj2->setPos(0,-1236);
    scene->addItem(abaj2);
    obs.push_back(abaj2);
    abaj3=(new QGraphicsLineItem(650,0,0,0));
    abaj3->setPen(QPen(Qt::transparent));
    abaj3->setPos(0,-2420);
    scene->addItem(abaj3);
    obs.push_back(abaj3);
    arrib1=(new QGraphicsLineItem(650,0,0,0));
    arrib1->setPen(QPen(Qt::transparent));
    arrib1->setPos(0,-580);
    scene->addItem(arrib1);
    obs.push_back(arrib1);
    arrib2=(new QGraphicsLineItem(650,0,0,0));
    arrib2->setPen(QPen(Qt::transparent));
    arrib2->setPos(0,-1768);
    scene->addItem(arrib2);
    obs.push_back(arrib2);
    arrib3=(new QGraphicsLineItem(800,0,0,0));
    arrib3->setPen(QPen(Qt::transparent));
    arrib3->setPos(0,-2968);
    scene->addItem(arrib3);
    obs.push_back(arrib3);
    puenteIzq1=(new QGraphicsLineItem(0,634,0,0));
    puenteIzq1->setPen(QPen(Qt::transparent));
    puenteIzq1->setPos(632,-1215);
    scene->addItem(puenteIzq1);    
    obs.push_back(puenteIzq1);
    puenteIzq2=(new QGraphicsLineItem(0,634,0,0));
    puenteIzq2->setPen(QPen(Qt::transparent));
    puenteIzq2->setPos(632,-2415);
    scene->addItem(puenteIzq2);
    obs.push_back(puenteIzq2);
    puertaBoss = new QGraphicsLineItem(120,0,0,0);
    puertaBoss->setPen(QPen(Qt::red));
    puertaBoss->setPos(650,-2400);
    obs.append(puertaBoss);
    scene->addItem(puertaBoss);
    puertaSala1 = new QGraphicsLineItem(120,0,0,0);
    puertaSala1->setPen(QPen(Qt::red));
    puertaSala1->setPos(635,-597);
    scene->addItem(puertaSala1);
    puertaSala2 = new QGraphicsLineItem(120,0,0,0);
    puertaSala2->setPen(QPen(Qt::red));
    puertaSala2->setPos(645,-1209);
    scene->addItem(puertaSala2);
    puertaSala3 = new QGraphicsLineItem(120,0,0,0);
    puertaSala3->setPen(QPen(Qt::red));
    puertaSala3->setPos(645,-1797);
    scene->addItem(puertaSala3);
    obs.append(puertaSala1);
    obs.append(puertaSala2);
    obs.append(puertaSala3);


}


void nivel1::moverSoldado()
{
   QList<soldado*>::iterator ms;

   for ( ms = soldados.begin(); ms != soldados.end(); ms++)
   {       
       int aleatorio = 1+rand()%4;
       if(aleatorio==1)
       {
           ms.i->t()->moverAr(0.02);
       }
       else if(aleatorio==2)
       {
            ms.i->t()->moverAb(0.02);
       }
       else if(aleatorio==3)
       {
           ms.i->t()->moverDr(0.02);
       }
       else if(aleatorio==4)
       {
           ms.i->t()->moverIz(0.02);
       }      
       ColisionArabesYSoldados(ms.i->t());
       balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
       balas.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
       scene->addItem(balas.last()); //con estas dos lineas creamos una bala.
   }



}

void nivel1::dispararSoldado()
{    
    for ( int i =0; i<balas.size() ;i++)
    {       
        balas.at(i)->moverBala();
        CBSCM(balas.at(i));
    }
    QList<soldado*>::iterator ms;

    for ( ms = soldados.begin(); ms != soldados.end(); ms++)
    {
        int aleatorio = 1+rand()%80;
        //qDebug() <<aleatorio;
        if(aleatorio==25)
        {
            balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
            balas.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            scene->addItem(balas.last()); //con estas dos lineas creamos una bala.
        }

    }


}

void nivel1::dispararBoss()
{
    if( poder ==4)
    {
        sebastian->dispararEnSol(L_balasBoss);
    }
    else if  ( poder == 5)
    {
        sebastian->lluviaNotas(L_balasBoss);
    }
    qDebug()<<jugador->getPosx() <<"     ::::   "<< jugador->getPosy();

}

void nivel1::ColisionBalasBoss()
{
    for ( int i = 0 ; i< L_balasBoss.size() ; i++)
    {
        if( L_balasBoss.at(i)->collidesWithItem(jugador))
        {            
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
            jugador->setVida(jugador->getVida()-5);
            if ( jugador->getVida() <=0 )
            {
                close();
            }
            else
            {                
            }

        }
        else if( L_balasBoss.at(i)->collidesWithItem(arrib3)
                 || L_balasBoss.at(i)->collidesWithItem(abaj3)
                 || L_balasBoss.at(i)->collidesWithItem(izq1)
                 || L_balasBoss.at(i)->collidesWithItem(drch1)
                 || L_balasBoss.at(i)->collidesWithItem(puertaBoss))
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }
        else if (L_balasBoss.at(i)->getPosx()<-10 || L_balasBoss.at(i)->getPosx()>810)
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }
        else if ( L_balasBoss.at(i)->collidesWithItem(mesa1) ||  L_balasBoss.at(i)->collidesWithItem(mesa2)
                  ||  L_balasBoss.at(i)->collidesWithItem(mesa3) ||  L_balasBoss.at(i)->collidesWithItem(mesa4))
        {
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
        }

    }    
    if(L_balasBoss.size()==0)
    {
        if(!timerGBB->isActive())
        {
            timerGBB->start(20);
        }
    }
}

void nivel1::CBJCS(bala * LaBala)
{
    for ( int i = 0 ; i< soldados.size(); i++)
    {
        if (soldados.at(i)->collidesWithItem(LaBala))
        {

            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);

            if( soldados.at(i)->getVida()<=0)
            {
                scene->removeItem(soldados.at(i));
                soldados.removeOne(soldados.at(i));
            }
            else
            {
                soldados.at(i)->setVida(soldados.at(i)->getVida()-jugador->getDamage());
            }
        }
    }
    for ( int i = 0 ; i< arabes.size(); i++)
    {
        if (arabes.at(i)->collidesWithItem(LaBala) && arabes.at(i)->getExplotar() == false)
        {

            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);
            if( arabes.at(i)->getVida()<=0)
            {
                arabes.at(i)->setPos(arabes.at(i)->getPosx()-20,arabes.at(i)->getPosy()-20);
                arabes.at(i)->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
                arabes.at(i)->setExplotar(true);
            }
            else
            {
                //qDebug() << arabes.at(i)->getVida();
                arabes.at(i)->setVida(arabes.at(i)->getVida()-jugador->getDamage());
            }
        }
    }
    for ( int i  = 0 ;  i < obs.size(); i++)
    {
        if (LaBala->collidesWithItem(obs[i]))
        {
            scene->removeItem(LaBala);
            balasJugador.removeOne(LaBala);
        }
    }
}

void nivel1::generarBalasBoss()
{       
    if ( L_balasBoss.size()==0 && sebastian->getMoviendome()==false)
    {
        poder = 1+rand()%3;
        if ( poder ==1)
        {
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(1);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(2);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(3);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(4);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(5);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(6);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(7);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(sebastian->getPosx(),sebastian->getPosy(),20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(8);
            scene->addItem(L_balasBoss.last());
            poder = 4;
        }
        else if ( poder ==2)
        {
            int cinco=0+rand()%14;
            L_balasBoss.push_back(new bala(50,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(100,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(150,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(200,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(250,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(300,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(350,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(400,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(450,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(500,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(550,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(600,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(650,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(700,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.push_back(new bala(750,-2950,20,20,'A'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/F augusto.png").scaled(30,30));
            L_balasBoss.last()->setNumBala(0);
            scene->addItem(L_balasBoss.last());
            L_balasBoss.at(cinco)->setPixmap(QPixmap(":/imagenes/vida.png").scaled(30,30));
            poder= 5;
        }
        if ( !balasB->isActive())
        {
            balasB->start(10);
        }
    }
}

void nivel1::moverBoss()
{
    if  ((margenError>= 8  || margenError <=-8))
    {
        sebastian->setMoviendome(true);
        if ( (margenError<0))
        {
            sebastian->moverDerecha(0.04);
            ui->lcdNumber->display(sebastian->getPosx());
        }
        else if ( margenError > 0 )
        {
            sebastian->moverIzquierda(0.04);
            ui->lcdNumber_2->display(sebastian->getPosx());
        }

    }
    else
    {     
        sebastian->setMoviendome(false);
    }
    if( contador==200)
    {
        movimientoSebastian=86+rand()%(678-86);
        contador= 0;
    }
    margenError = int((sebastian->getPosx() - movimientoSebastian));
    ui->lcdNumber_3->display(margenError);
    contador++;
}

void nivel1::CBJCB()
{
    for ( int i = 0 ; i<balasJugador.size(); i++)
    {
        if ( balasJugador.at(i)->collidesWithItem(sebastian))
        {
            if ( sebastian->getEscudo()>0)
            {                

                scene->removeItem(balasJugador.at(i));
                balasJugador.removeOne(balasJugador.at(i));
                sebastian->setEscudo(sebastian->getEscudo()-jugador->getDamage());
            }
            else
            {
                if ( sebastian->getVida()>0)
                {

                    scene->removeItem(balasJugador.at(i));
                    balasJugador.removeOne(balasJugador.at(i));
                    sebastian->setVida(sebastian->getVida()-jugador->getDamage());
                }
                else
                {                    
                    timerCBJCB->stop();
                    sebastian->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
                    timerMoverBoss->stop();
                    timerGBB->stop();
                    balasB->stop();
                }
            }
        }
        else if ( balasJugador.at(i)->collidesWithItem(mesa1) || balasJugador.at(i)->collidesWithItem(mesa2)
                    ||balasJugador.at(i)->collidesWithItem(mesa3) || balasJugador.at(i)->collidesWithItem(mesa4))
        {
            scene->removeItem(balasJugador.at(i));
            balasJugador.removeOne(balasJugador.at(i));
        }
    }
}

void nivel1::colisionesJugador()
{
//    qDebug() << balasJugador.size()<<"balas jugador size";
    //este primer for es para detecta la colision del jugador con los arabes cuando estan muertos, generando friccion
    for ( int i = 0 ; i < arabes.size(); i++)
    {
        if ( jugador->collidesWithItem(arabes.at(i)) && arabes.at(i)->getExplotar()== true)
        {
            jugador->setVx(30);
            jugador->setVy(30);
            mermarVida++;
        }
        else
        {
            jugador->setVx(100);
            jugador->setVy(100);
        }
        if ( mermarVida >= 100)
        {
            jugador->setVida(jugador->getVida()-10);
            mermarVida=0;
            ui->progressBar->setValue(jugador->getVida());
            if (  jugador->getVida()<=0)
            {
//                qDebug()<<"perdio papi";
            }
        }
    }
}

void nivel1::dialogos()
{
    if (agujeroNegro->getAgujero()==false)
    {
        int numero  = 1 + rand()%2;
        if ( numero ==1)
        {
            dialogosAgusto->setMedia(QUrl("qrc:/musica/Completardoshoras.mp3"));
            dialogosAgusto->setVolume(100);
            dialogosAgusto->play();
        }
        else
        {
            dialogosAgusto->setMedia(QUrl("qrc:/musica/llegaranecdota.mp3"));
            dialogosAgusto->setVolume(100);
            dialogosAgusto->play();
        }
    }
    else if ( agujeroNegro->getAgujero() == true && !lvl1->isActive())
    {
        int numero = 1+rand()%3;
        if (  numero ==1)
        {
            dialogosAgusto->setMedia(QUrl("qrc:/musica/Completardoshoras.mp3"));
            dialogosAgusto->setVolume(100);
            dialogosAgusto->play();
        }
        else if ( numero ==2)
        {
            dialogosAgusto->setMedia(QUrl("qrc:/musica/noseacochini.mp3"));
            dialogosAgusto->setVolume(100);
            dialogosAgusto->play();
        }
        else if( numero ==3)
        {
            dialogosAgusto->setMedia(QUrl("qrc:/musica/vencerme cuestióncarpintería.mp3"));
            dialogosAgusto->setVolume(100);
            dialogosAgusto->play();
        }
    }


}

void nivel1::oleadas()
{
    if( numOleada==0 && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
         balas_soldado->start(20);
         mover_Soldado->start(3000);
         timerColisionesJugador->start(20);
         numOleada++;
    }
    else if (numOleada==1  && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
        numOleada++;
    }
    else if(numOleada==2 && soldados.size()==0)
    {
        generarSoldados();
        generarArabe();
        numOleada=0;
        if ( sala ==2 )
        {
            oleada->stop();
        }
        sala = 5;
    }


}

void nivel1::CBSCM(bala *LaBalaDelSoldado)
{

    if ( LaBalaDelSoldado->collidesWithItem(jugador))
    {
        jugador->setVida(jugador->getVida()-3);
        ui->progressBar->setValue(jugador->getVida());
        scene->removeItem(LaBalaDelSoldado);
        balas.removeOne(LaBalaDelSoldado);
        if (  jugador->getVida()<=0)
        {
//            qDebug()<<"perdio papi";
        }

    }
    for ( int i = 0 ; i< obs.size(); i++)
    {
        if ( LaBalaDelSoldado->collidesWithItem(obs.at(i)))
        {
            scene->removeItem(LaBalaDelSoldado);
            balas.removeOne(LaBalaDelSoldado);
            //qDebug()<< balas.size();
        }

    }


}

void nivel1::ColisionArabesYSoldados(soldado *solda)
{
    for ( int i = 0 ; i < arabes.size() ; i++)
    {
        if ( arabes.at(i)->collidesWithItem(solda) && arabes.at(i)->getExplotar()== true)
        {
            //qDebug() <<"hola, estoy tapando un soldado jaja";
            solda->moverAr(0.1);

        }
    }
}

void nivel1::generarObstaculos()
{
    //esta funcion genera todos los obstaculos del primer nivel
    mesa1=(new obstaculos( 226,-2512,30,30));
    scene->addItem(mesa1);
    mesa2=(new obstaculos( 118,-2744,30,30));
    scene->addItem(mesa2);
    mesa3=(new obstaculos( 344,-2696,30,30));
    scene->addItem(mesa3);
    mesa4=(new obstaculos( 650,-2796,30,30));
    scene->addItem(mesa4);
}

bool nivel1::colisionConMesa()
{
    if(dire=='W' && (jugador->collidesWithItem(mesa1) || jugador->collidesWithItem(mesa2)
                     || jugador->collidesWithItem(mesa3) || jugador->collidesWithItem(mesa4)))
    {
        jugador->setPosy(jugador->getPosy()+2);
        jugador->setPos(jugador->getPosx(), jugador->getPosy());
        return true;
    }
    else if(dire=='S'&& (jugador->collidesWithItem(mesa1) || jugador->collidesWithItem(mesa2)
                         || jugador->collidesWithItem(mesa3) || jugador->collidesWithItem(mesa4)))
    {
        jugador->setPosy(jugador->getPosy()-2);
        jugador->setPos(jugador->getPosx(), jugador->getPosy());
        return true;
    }
    else if(dire=='A'&& (jugador->collidesWithItem(mesa1) || jugador->collidesWithItem(mesa2)
                         || jugador->collidesWithItem(mesa3) || jugador->collidesWithItem(mesa4)))
    {
        jugador->setPosx(jugador->getPosx()+2);
        jugador->setPos(jugador->getPosx(), jugador->getPosy());
        return true;
    }
    else if(dire=='D'&& (jugador->collidesWithItem(mesa1) || jugador->collidesWithItem(mesa2)
                         || jugador->collidesWithItem(mesa3) || jugador->collidesWithItem(mesa4)))
    {
        jugador->setPosx(jugador->getPosx()-2);
        jugador->setPos(jugador->getPosx(), jugador->getPosy());
        return true;
    }
}

void nivel1::generarSoldados()
{
    if (  sala == 1 && numOleada==0 )
    {
        soldados.append(new soldado(98,-197,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(234,-333,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(638,-249,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(398,-303,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(194,-496,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(454,-552,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 1 && numOleada==1 )
    {
        soldados.append(new soldado(94,-133,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(214,-269,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(302,-441,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(442,-417,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(682,-498,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(554,-252,55,60));
        scene->addItem(soldados.last());
    }
    else if ( sala == 1 && numOleada==2)
    {
        soldados.append(new soldado(78,-485,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(82,-125,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(618,-181,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(582,-481,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(390,-285,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(286,-213,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 2 && numOleada==0 )
    {
        soldados.append(new soldado(90,-1337,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(214,-1541,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(346,-1437,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(638,-1577,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(370,-1689,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(318,-1361,55,60));
        scene->addItem(soldados.last());
    }
    else if (  sala == 2 && numOleada==1 )
    {
        soldados.append(new soldado(86,-1537,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(278,-1585,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(478,-1357,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(570,-1297,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(378,-1517,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(50,-1725,55,60));
        scene->addItem(soldados.last());
    }
    else if ( sala == 2 && numOleada==2)
    {
        soldados.append(new soldado(42,-1425,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(118,-1581,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(274,-1737,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(534,-1681,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(654,-1553,55,60));
        scene->addItem(soldados.last());
        soldados.append(new soldado(542,-1277,55,60));
        scene->addItem(soldados.last());
    }

}

void nivel1::moverArabe()
{
    QList<arabe*>::iterator ma;
    for ( ma = arabes.begin(); ma != arabes.end() ; ma++)
    {
        ma.i->t()->setDistancia(abs(ma.i->t()->pos().y()-jugador->pos().y()));        
        if (ma.i->t()->pos().x()<jugador->pos().x() && (ma.i->t()->getExplotar() == false))
        {
            ma.i->t()->moverDerecha(0.02);
        }
        if (ma.i->t()->pos().x()>jugador->pos().x() && (ma.i->t()->getExplotar() == false) )
        {
             ma.i->t()->moverIzquierda(0.02);
        }
        if ( ma.i->t()->pos().y()<jugador->pos().y() && (ma.i->t()->getExplotar() == false))
        {
            ma.i->t()->moverAbajo(0.01);
        }
         if (ma.i->t()->pos().y()>jugador->pos().y() && (ma.i->t()->getExplotar() == false))
         {
             ma.i->t()->moverArriba(0.01);
         }
    }    

}

void nivel1::Puertas()
{
if ( jugador->collidesWithItem(puertaSala2))
{
    sala=2;
}
 if ( jugador->collidesWithItem(puertaSala1) &&  sala == 1  && soldados.size()!= 0)
 {
     jugador->setPosy(jugador->getPosy()+10);
 }
 else if (jugador->collidesWithItem(puertaSala3) &&  sala ==2  && soldados.size()!= 0 )
 {
     jugador->setPosy(jugador->getPosy()+10);
 }
 else if (jugador->collidesWithItem(puertaSala2) &&  sala ==2  && soldados.size()!= 0 )
 {
     jugador->setPosy(jugador->getPosy()-10);
 }
}

void nivel1::generarArabe()
{
    if ( sala==1 && numOleada ==0)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(393);
        arabes.last()->setPosy(-372);
        scene->addItem(arabes.last());
    }
    else if ( sala == 1 && numOleada ==1)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(86);
        arabes.last()->setPosy(-546);
        scene->addItem(arabes.last());
    }
    else if ( sala == 1 && numOleada==2)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(710);
        arabes.last()->setPosy(-481);
        scene->addItem(arabes.last());
    }
    else if ( sala==2 && numOleada ==0)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(386);
        arabes.last()->setPosy(-1537);
        scene->addItem(arabes.last());
    }
    else if ( sala == 2 && numOleada ==1)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(390);
        arabes.last()->setPosy(-1765);
        scene->addItem(arabes.last());
    }
    else if ( sala == 2 && numOleada==2)
    {
        arabes.append(new arabe());
        arabes.last()->setPosx(366);
        arabes.last()->setPosy(-1505);
        scene->addItem(arabes.last());
    }

    if ( !mover_arabe->isActive())
    {
        mover_arabe->start(20);
        colision_arabe->start(20);
    }


}

void nivel1::pausa()
{
    pausa_=true ;
    if(tiempo->isActive())
    {
        tiempo->stop();
    }
    if ( mover_Soldado->isActive())
    {
        mover_Soldado->stop();
    }
    if( mover_arabe->isActive())
    {
        mover_arabe->stop() ;
    }
    if ( colision_arabe->isActive())
    {
        colision_arabe->stop();
    }
    if (balas_soldado->isActive())
    {
        balas_soldado->stop();
    }
    if ( balasB->isActive())
    {
        balasB->stop();
    }
    if( timerGBB->isActive())
    {
        timerGBB->stop();
    }
    if ( timerColisionBalasBoss->isActive())
    {
        timerColisionBalasBoss->stop();
    }
    if ( timerMoverBoss->isActive())
    {
        timerMoverBoss->stop();
    }
    if( timerCBJCB->isActive())
    {
        timerCBJCB->stop();
    }
    if ( timerColisionesJugador->isActive())
    {
        timerColisionesJugador->stop();
    }
    if( lvl1->isActive())
    {
        lvl1->stop();
    }
    if( dialog->isActive())
    {
        dialog->stop();
    }
    if( oleada->isActive())
    {
        oleada->stop();
    }
    if( puertas->isActive())
    {
        puertas->stop();
    }
    ui->ARDUINO->setVisible(true);
    ui->GUARDAPARTIDA->setVisible(true);
    ui->SALIR->setVisible(true);
}

void nivel1::colisionArabe()
{
    //esta funcion se encarga de detectar cuando un arabe colisiona con el jugador para explotarse y dejar el rastro.
    QList<arabe*>::iterator ca;
    for (ca = arabes.begin(); ca != arabes.end(); ca ++)
    {
        if ( ca.i->t()->collidesWithItem(jugador))
        {
           //hacemos que explote.
           ca.i->t()->setPos(ca.i->t()->getPosx()-20,ca.i->t()->getPosy()-20);
           ca.i->t()->setPixmap(QPixmap(":/imagenes/arabeExplosion.png"));
           ca.i->t()->setExplotar(true);

        }
    }
}

void nivel1::moverBalasJugador()
{
    for ( int i = 0 ; i < balasJugador.size(); i++)
    {        
            balasJugador.at(i)->moverBala();
            CBJCS(balasJugador.at(i));
    }
    qDebug()<< jugador->getPosx()<<"   ::::   "<<jugador->getPosy();
}


void nivel1::jefeFinal()
{
    if( jugador->collidesWithItem(puertaBoss) && agujeroNegro->getAgujero()==false)
    {
        agujeroNegro->setPixmap(QPixmap(":/imagenes/agujero.png"));
        scene->addItem(agujeroNegro);
        agujeroNegro->setAgujero(true);
    }
    else if (agujeroNegro->getAgujero()==true && jugador->collidesWithItem(agujeroNegro))
    {
        //hay que sacar el boss
        timerCBJCB->start(1);
        sebastian->setActivo(true);
        sebastian->setPosx(374);
        sebastian->setPosy(-2900);
        scene->addItem(sebastian);
        srand(time(NULL));
        movimientoSebastian=86+rand()%(678-86);
        margenError = int((sebastian->getPosx() - movimientoSebastian));
        ui->lcdNumber_3->display(margenError);
        //hay que conectar todos los timers que activen cosas del boss
        timerGBB->start(20);
        timerColisionBalasBoss->start(1);
        timerMoverBoss->start(20);
        //hay que hacer que agusto empieze a decir cosas
        scene->removeItem(agujeroNegro);
        agujeroNegro->~obstaculos();
        dialogosAgusto->setMedia(QUrl("qrc:/musica/vencerme cuestióncarpintería.mp3"));
        dialogosAgusto->setVolume(100);
        dialogosAgusto->play();
        lvl1->stop();
    }

}

void nivel1::on_SALIR_clicked()
{
    pausa_=false;
    if(!tiempo->isActive())
    {
        tiempo->start(20);
    }
    if ( !mover_Soldado->isActive())
    {
        mover_Soldado->start(3000);
    }
    if( !mover_arabe->isActive())
    {
        mover_arabe->start(20) ;
    }
    if ( colision_arabe->isActive())
    {
        colision_arabe->start(20);
    }
    if (!balas_soldado->isActive())
    {
        balas_soldado->start(20);
    }
    if ( !balasB->isActive())
    {
        balasB->start(10);
    }
    if( !timerGBB->isActive())
    {
        timerGBB->start(20);
    }
    if ( !timerColisionBalasBoss->isActive())
    {
        timerColisionBalasBoss->start(1);
    }
    if ( !timerMoverBoss->isActive())
    {
        timerMoverBoss->start(20);
    }
    if(! timerCBJCB->isActive())
    {
        timerCBJCB->start(1);
    }
    if ( !timerColisionesJugador->isActive())
    {
        timerColisionesJugador->start(20);
    }
    if( !lvl1->isActive())
    {
        lvl1->start(20);
    }
    if( !dialog->isActive())
    {
        dialog->start(10000);
    }
    if( !oleada->isActive())
    {
        oleada->start(5000);
    }
    if(! puertas->isActive())
    {
        puertas->start(1);
    }
    ui->ARDUINO->setVisible(false);
    ui->GUARDAPARTIDA->setVisible(false);
    ui->SALIR->setVisible(false);
}

void nivel1::on_ARDUINO_clicked()
{
    qDebug() <<"en desa";
}

void nivel1::on_GUARDAPARTIDA_clicked()
{
    QFile file(uss);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "error abriendo la cuenta ";
    }
    else
    {
        QTextStream cuenta(&file);
        cuenta<<uss<<endl<<pass<<endl;
        //estando en la tercera linea empezamos a guardar datos
        cuenta << jugador->getPosx()<<","<<jugador->getPosy()<<endl;
        file.close();
    }
    //abrimos el archivo de texto modo escritura
    //nos situamos en la linea 3
}
