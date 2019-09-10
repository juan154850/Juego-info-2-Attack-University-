#include "menu.h"
#include <QApplication>
#include "nivel1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    nivel1 w;
    w.show();

    return a.exec();
}
