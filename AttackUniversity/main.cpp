#include "MainWindow.h"
#include <QApplication>
#include "nivel1.h"
#include "menu.h"
#include "ganar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Ganar w (false);
    nivel1 w("123","123",false);
   // menu w;
    w.show();

    return a.exec();
}
