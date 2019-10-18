#include "MainWindow.h"
#include <QApplication>
#include "nivel1.h"
#include "nivel2.h"
#include "menu.h"
#include "ganar.h"
#include "multijugador1.h"
#include "multijugador2.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Ganar w (false);
    //nivel1 w("123","123",false,1);
    //menu w;
    //nivel2 w("123","123",false,2);
    //wmultijugador1 w;
    multijugador2 w;

    w.show();

    return a.exec();
}
