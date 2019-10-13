#include "MainWindow.h"
#include <QApplication>
#include "nivel1.h"
#include "menu.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    nivel1 w("admin","admin",false);
    menu w;
    w.show();

    return a.exec();
}
