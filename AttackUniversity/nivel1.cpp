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

    generarBordes();


    //-------------------player-------------------

    jugador = new personaje(362,-100,50,55,100,100);
    scene->addItem(jugador);
    scene->setFocusItem(jugador);

    //-------------------boss-------------------
    generarSoldados();
    sebastian = new boss1();
    sebastian->setPosx(374);
    sebastian->setPosy(-2900);
    scene->addItem(sebastian);
    srand(time(NULL));
    movimientoSebastian=86+rand()%(678-86);
    margenError = int((sebastian->getPosx() - movimientoSebastian));
    ui->lcdNumber_3->display(margenError);



    //-------------------timers-------------------


    tiempo = new QTimer();
    connect(tiempo, &QTimer::timeout, this, &nivel1::moverBalasJugador);
    tiempo->start(20);

    balas_soldado = new QTimer();
    connect(balas_soldado,&QTimer::timeout,this,&nivel1::dispararSoldado);
    balas_soldado->start(20);

    mover_Soldado = new QTimer();
    connect(mover_Soldado,&QTimer::timeout,this,&nivel1::moverSoldado);
    mover_Soldado->start(1000);

    mover_arabe = new QTimer();
    connect(mover_arabe,&QTimer::timeout,this,&nivel1::moverArabe);

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

    timerColisionBalasBoss = new QTimer();
    connect(timerColisionBalasBoss, &QTimer::timeout,this,&nivel1::ColisionBalasBoss);
    timerColisionBalasBoss->start(20);

    t_CBJCS = new QTimer();
    connect(t_CBJCS, &QTimer::timeout,this,&nivel1::CBJCS) ;
    t_CBJCS->start(20);

    timerMoverBoss = new QTimer();
    connect(timerMoverBoss, &QTimer::timeout,this,&nivel1::moverBoss) ;
    timerMoverBoss->start(20);

    timerCBJCB = new QTimer;
    connect(timerCBJCB, &QTimer::timeout,this,&nivel1::CBJCB) ;

    timerCBSCM =  new QTimer;
    connect(timerCBSCM,&QTimer::timeout,this,&nivel1::CBSCM);
    timerCBSCM->start(10);



    //-------------------foco-------------------
    scene->setSceneRect(0,jugador->getPosy()-515,800,600);    
    ui->lcdNumber->setVisible(false);
    ui->lcdNumber_2->setVisible(false);
    ui->lcdNumber_3->setVisible(false);



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
        if(!jugador->collidesWithItem(arrib1) && !jugador->collidesWithItem(arrib2) && !jugador->collidesWithItem(arrib3))
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


        break;
    }
    case(Qt::Key_S):
    {
        dire = 'S';
        jugador->animacionAbajo();
        if(!jugador->collidesWithItem(abaj2) && !jugador->collidesWithItem(abaj1) && !jugador->collidesWithItem(abaj3))
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
        break;
    }
    case(Qt::Key_D):
    {
        dire = 'D';
        jugador->animacionDerecha();
        if(!jugador->collidesWithItem(drch1))
        {
            jugador->moverDerecha(0.04);

        }
        break;
    }
    case(Qt::Key_A):
    {
        dire = 'A';
        jugador->animacionIzquierda();
        if(!jugador->collidesWithItem(izq1) && !jugador->collidesWithItem(puenteIzq1) && !jugador->collidesWithItem(puenteIzq2))
        {

            jugador->moverIzquierda(0.04);            
        }        
        break;
    }
    case (Qt::Key_Space):
    {
        //-------------------creacion de balas-------------------
        balasJugador.append(new bala(jugador->getPosx()+8,jugador->getPosy()-10,20,20,dire));
        scene->addItem(balasJugador.last());
        timerCBJCB->start(20);
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
    drch1=(new QGraphicsLineItem(0,3000,0,0));
    drch1->setPen(QPen(Qt::transparent));
    drch1->setPos(760,-3000);
    scene->addItem(drch1);
    abaj1=(new QGraphicsLineItem(800,0,0,0));
    abaj1->setPen(QPen(Qt::transparent));
    abaj1->setPos(0,-20);
    scene->addItem(abaj1);
    abaj2=(new QGraphicsLineItem(650,0,0,0));
    abaj2->setPen(QPen(Qt::transparent));
    abaj2->setPos(0,-1236);
    scene->addItem(abaj2);
    abaj3=(new QGraphicsLineItem(650,0,0,0));
    abaj3->setPen(QPen(Qt::transparent));
    abaj3->setPos(0,-2420);
    scene->addItem(abaj3);
    arrib1=(new QGraphicsLineItem(650,0,0,0));
    arrib1->setPen(QPen(Qt::transparent));
    arrib1->setPos(0,-580);
    scene->addItem(arrib1);
    arrib2=(new QGraphicsLineItem(650,0,0,0));
    arrib2->setPen(QPen(Qt::transparent));
    arrib2->setPos(0,-1768);
    scene->addItem(arrib2);
    arrib3=(new QGraphicsLineItem(800,0,0,0));
    arrib3->setPen(QPen(Qt::transparent));
    arrib3->setPos(0,-2968);
    scene->addItem(arrib3);
    puenteIzq1=(new QGraphicsLineItem(0,634,0,0));
    puenteIzq1->setPen(QPen(Qt::transparent));
    puenteIzq1->setPos(632,-1215);
    scene->addItem(puenteIzq1);
    puenteIzq2=(new QGraphicsLineItem(0,634,0,0));
    puenteIzq2->setPen(QPen(Qt::transparent));
    puenteIzq2->setPos(632,-2415);
    scene->addItem(puenteIzq2);

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
       balas.append(new bala(ms.i->t()->pos().x(),ms.i->t()->pos().y()+30,20,20,ms.i->t()->getDir()));
       scene->addItem(balas.last()); //con estas dos lineas creamos una bala.       
   }



}

void nivel1::dispararSoldado()
{    
    for ( int i =0; i<balas.size() ;i++)
    {       
        balas.at(i)->moverBala();
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

void nivel1::ColisionBalasBoss()
{
    for ( int i = 0 ; i< L_balasBoss.size() ; i++)
    {
        if( L_balasBoss.at(i)->collidesWithItem(jugador))
        {            
            scene->removeItem(L_balasBoss.at(i));
            L_balasBoss.removeOne(L_balasBoss.at(i));
            jugador->setVida(jugador->getVida()-1);
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
                 || L_balasBoss.at(i)->collidesWithItem(drch1))
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

void nivel1::CBJCS()
{
    /*plantear solucion*/
}

void nivel1::generarBalasBoss()
{

    if (L_balasBoss.size()<=4)
    {
        if ( sebastian->getVida()<0)
        {
            timerGBB->stop();
            for ( int i= 0; i<L_balasBoss.size();i++)
            {
                L_balasBoss.at(i)->~bala();
            }
            timerMoverBoss->stop();
            balasB->stop();
        }
        else
        {
            L_balasBoss.append(new bala(sebastian->pos().x(),sebastian->pos().y()+60,20,20,'S'));
            L_balasBoss.last()->setPixmap(QPixmap(":/imagenes/balaBoss1.png").scaled(30,30));
            scene->addItem(L_balasBoss.last());
            if(!balasB->isActive())
            {
                balasB->start(20);
            }
        }
    }
    else
    {
        timerGBB->stop();
    }

}

void nivel1::moverBoss()
{
    if  ((margenError>= 8  || margenError <=-8))
    {

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
                ui->progressBar->setValue(sebastian->getEscudo());
                scene->removeItem(balasJugador.at(i));
                balasJugador.removeOne(balasJugador.at(i));
                sebastian->setEscudo(sebastian->getEscudo()-jugador->getDamage());
            }
            else
            {
                if ( sebastian->getVida()>0)
                {
                    ui->progressBar->setValue(sebastian->getVida());                    
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
    }
}

void nivel1::CBSCM()
{
    for ( int i = 0 ; i<balas.size(); i++)
    {
            /*plantear solucion*/
//            if ( balas.at(i)->getPosx()<=0 || balas.at(i)->getPosx()>=800 || balas.at(i)->getPosy() >=-1 || balas.at(i)->getPosy()<=-590)
//            {
//                scene->removeItem(balas.at(i));
//                balas.removeOne(balas.at(i));
//            }
//            else if ( balas.at(i)->collidesWithItem(jugador))
//            {
//                qDebug ()<< "choque jugador";
//                scene->removeItem(balas.at(i));
//                balas.removeOne(balas.at(i));
//            }
    }
}


void nivel1::generarSoldados()
{
    soldados.append(new soldado(120,-200,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(500,-350,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(590,-158,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(200,-110,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(80,-298,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(420,-434,55,60));
    scene->addItem(soldados.last());
    soldados.append(new soldado(358,-238,55,60));
    scene->addItem(soldados.last());


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

void nivel1::generarArabe()
{
    addsAra++;
    if ( addsAra <=1)
    {
        int px, py;
        srand(time(NULL));
        px = 20+rand()%700;
        py = 100+rand()%500;
        arabes.append(new arabe());
        arabes.last()->setPosx(px);
        arabes.last()->setPosy(-py);
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
            balasJugador.at(i)->moverBala();
    }
}
