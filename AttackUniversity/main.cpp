#include "MainWindow.h"
#include <QApplication>
#include "nivel1.h"
#include "nivel2.h"
#include "menu.h"
#include "ganar.h"
#include "multijugador1.h"
#include "multijugador2.h"
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);              
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/imagenes2/LOGOJUEGO.png"));
    splash->show();
    //Ganar w ("123","123",false,1);
    //nivel1 w("123","123",false,1);
    menu w;
    //nivel2 w("123","123",false,2);
    //multijugador1 w;
    //multijugador2 w;
    QTimer::singleShot(500,splash,SLOT(close()));
    QTimer::singleShot(500,&w,SLOT(show()));
    w.show();

    return a.exec();
}
