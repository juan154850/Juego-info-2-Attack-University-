#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel1)
{
    ui->setupUi(this);

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

    //-------------------player-------------------

    jugador = new personaje(394,-50,50,55,100,100);
    scene->addItem(jugador);
    scene->setFocusItem(jugador);

    //-------------------boss-------------------

    sebastian = new boss1();
    sebastian->setPosx(374);
    sebastian->setPosy(-1071);
    scene->addItem(sebastian);


    //-------------------timers-------------------

    tiempo = new QTimer();
    connect(tiempo, &QTimer::timeout, this, &nivel1::moverBalasJugador);
    tiempo->start(20);

    balas_soldado = new QTimer();
    connect(balas_soldado,&QTimer::timeout,this,&nivel1::dispararSoldado);
    balas_soldado->start(20);

    mover_Soldado = new QTimer();
    connect(mover_Soldado,&QTimer::timeout,this,&nivel1::moverSoldado);
    mover_Soldado->start(20);

    mover_arabe = new QTimer();
    connect(mover_arabe,&QTimer::timeout,this,&nivel1::moverArabe);


    generar_soldados = new QTimer();
    connect(generar_soldados,&QTimer::timeout,this,&nivel1::generarSoldados);
    generar_soldados->start(2000); //generamos soldados cada 5segundos

    generar_arabes = new QTimer();
    connect(generar_arabes,&QTimer::timeout, this   , &nivel1::generarArabe);
    generar_arabes->start(4000); //generamos arabes cada 4 segundos

    colision_arabe =  new QTimer();
    connect(colision_arabe, &QTimer::timeout,this,&nivel1::colisionArabe);    

    balasB = new QTimer();
    connect(balasB,&QTimer::timeout,this,&nivel1::dispararBoss);

    timerGBB = new QTimer();
    connect(timerGBB, &QTimer::timeout,this,&nivel1::generarBalasBoss);
    timerGBB->start(20);


    //-------------------foco-------------------
    scene->setSceneRect(0,jugador->getPosy()-522,800,600);





    //---------


}

nivel1::~nivel1()
{
    delete ui;
}

void nivel1::keyPressEvent(QKeyEvent *ev)
{
    ui->lcdNumber->display(jugador->getPosy());
    ui->lcdNumber_2->display(jugador->getPosx());
    switch (ev->key())
    {
    case (Qt::Key_A):
    {
        dire = 'A';
        jugador->animacionIzquierda();        
        jugador->moverIzquierda(0.04);
        break;
    }
    case (Qt::Key_D):
    {                
        dire = 'D';
        jugador->animacionDerecha();
        jugador->moverDerecha(0.04);
        break;
    }
    case (Qt::Key_W):
    {        
        dire = 'W';
        jugador->animacionArriba();
        //bloqueo de la camara
        if(jugador->getPosy()>=-2470)
        {
            jugador->moverArriba(0.04);
            scene->setSceneRect(0,jugador->getPosy()-522,800,600);
        }
        else
        {
            jugador->moverArriba(0.04);
        }
        break;
    }
    case (Qt::Key_S):
    {        
        dire = 'S';
        jugador->animacionAbajo();
        //bloqueo de la camara
        if(jugador->getPosy()>=-46 )
        {
            ev->ignore();

        }
        else
        {
            if(jugador->getPosy()>=-2470)
            {
                jugador->moverAbajo(0.04);
                scene->setSceneRect(0,jugador->getPosy()-522,800,600);
            }
            else
            {
                    jugador->moverAbajo(0.04);
            }

        }
        break;
    }
    case (Qt::Key_Space):
    {
        //-------------------creacion de balas-------------------
        balasJugador.append(new bala(jugador->getPosx(),jugador->getPosy()-10,20,20,dire));
        scene->addItem(balasJugador.last());
        break;
    }
    }
}
void nivel1::moverSoldado()
{
   QList<soldado*>::iterator ms;
   for ( ms = soldados.begin(); ms != soldados.end(); ms++)
   {       
       ms.i->t()->setDistancia(abs(ms.i->t()->pos().y()-jugador->pos().y()));
       ms.i->t()->setDistanciaX(abs(ms.i->t()->pos().x()-jugador->pos().x()));
//       ui->lcdNumber->display(ms.i->t()->getDistancia());
//       ui->lcdNumber_2->display(ms.i->t()->getDistanciaX());
       if (ms.i->t()->getDistancia()<=200)
       {
           ms.i->t()->setMoverse(false);
           if (ms.i->t()->getDistancia()<=150)
           {
               ms.i->t()->moverAr(0.02);
           }
           if (ms.i->t()->pos().x()<jugador->pos().x())
           {
               ms.i->t()->moverDr(0.02);
               int num = 0+rand()%30;
               if ( num == 5)
               {
                   ms.i->t()->moverAb(0.02);
               }
//               qDebug() <<ms.i->t()->getDir();
           }
           if (ms.i->t()->pos().x()>jugador->pos().x())
           {
               ms.i->t()->moverIz(0.02);
               int num = 0+rand()%30;
               if ( num == 5)
               {
                   ms.i->t()->moverAr(0.02);
               }
//               qDebug() <<ms.i->t()->getDir();
           }
           if (ms.i->t()->getDistanciaX()<5)
           {
              ms.i->t()->setDir('S');
              if ( ms.i->t()->getContadorBalas() ==60)
              {
                  ms.i->t()->setContadorBalas(0);
                  balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
                  scene->addItem(balas.last()); //con estas dos lineas creamos una bala.
              }
              ms.i->t()->setContadorBalas(ms.i->t()->getContadorBalas()+1);
           }

       }
       if (ms.i->t()->pos().x()<jugador->pos().x() && ms.i->t()->getMoverse() == true)
       {          
           ms.i->t()->moverDr(0.02);
       }
       if (ms.i->t()->pos().x()>jugador->pos().x()&& ms.i->t()->getMoverse() == true )
       {           
            ms.i->t()->moverIz(0.02);
       }
       if ( ms.i->t()->pos().y()<jugador->pos().y() && ms.i->t()->getMoverse() == true)
       {           
           ms.i->t()->moverAb(0.01);
       }
        if (ms.i->t()->pos().y()>jugador->pos().y() && ms.i->t()->getMoverse() == true)
        {            
            ms.i->t()->moverAr(0.01);
        }
        ms.i->t()->setMoverse(true);
   }


}

void nivel1::dispararSoldado()
{
    for ( int i =0; i<balas.size() ;i++)
    {
        if (balas.at(i)->collidesWithItem(jugador))
        {
            scene->removeItem(balas.at(i));
            balas.removeAt(i);

            //falta restar las vidas del jugador.
            //delete balas.at(i);
        }
        else
        {
         balas.at(i)->moverBala();
        }
    }
}

void nivel1::dispararBoss()
{
    //esta funcion hace que el boss dispare en forma circular
    QList<bala*>::iterator bala;
    for (bala = L_balasBoss.begin();bala!=L_balasBoss.end();bala++ )
    {
        if(nBala==1)
        {
            sebastian->dispararIzquierda(bala.i->t());
            nBala++;

        }
        else if(nBala==2)
        {
            sebastian->dispararDerecha(*bala);
            nBala++;
        }
        else if(nBala==3)
        {
            bala.i->t()->moverAbajo(0.04);
            nBala++;
        }
        else if (nBala ==4)
        {
            sebastian->dispararIzquierda2(*bala);
        }


    }
    nBala=1;



}

void nivel1::balasBoss()
{

}

void nivel1::generarBalasBoss()
{
    if (L_balasBoss.size()<=4)
    {
        L_balasBoss.append(new bala(sebastian->pos().x(),sebastian->pos().y()+30,20,20,'S'));
        scene->addItem(L_balasBoss.last());
        balasB->start(20);
    }
    else
    {
        timerGBB->stop();
    }

}


void nivel1::generarSoldados()
{
    adds++;
    if ( adds <=1)
    {
        int px, py;
        srand(time(NULL));
        px = 50+rand()%700;
        py = 50+rand()%500;
        soldados.append(new soldado(px,py,50,55));
        scene->addItem(soldados.last());
    }
    else
    {
        generar_soldados->stop();
    }

}

void nivel1::moverArabe()
{
    QList<arabe*>::iterator ma;
    for ( ma = arabes.begin(); ma != arabes.end() ; ma++)
    {
        ma.i->t()->setDistancia(abs(ma.i->t()->pos().y()-jugador->pos().y()));
        //ui->lcdNumber->display(ma.i->t()->getDistancia());
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

void nivel1::generarArabe()
{
    addsAra++;
    if ( addsAra <=1)
    {
        int px, py;
        srand(time(NULL));
        px = 20+rand()%700;
        py = 20+rand()%500;
        arabes.append(new arabe());
        arabes.last()->setPosx(px);
        arabes.last()->setPosy(py);
        scene->addItem(arabes.last());
    }
    else
    {
        generar_arabes->stop();
    }
    mover_arabe->start(20);
    colision_arabe->start(20);
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
        if ( balasJugador.at(i)->collidesWithItem(soldados.at(0)) && soldados.size()!=1)
        {
            scene->removeItem(soldados.at(0));
            soldados.removeAt(0);
        }
        balasJugador.at(i)->moverBala();
    }
}
