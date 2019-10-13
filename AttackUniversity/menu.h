#ifndef MENU_H
#define MENU_H
#include <QMediaPlayer>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <string>
#include <QMessageBox>
#include "nivel1.h"
#include <string.h>
#include <fstream>
using namespace std;
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:


    void on_iniciar_clicked();

    void on_registro_clicked();

    void on_iniciar_2_clicked();

    void on_registro_2_clicked();

    void on_nuevaPartida_clicked();

    void on_cargarPartida_clicked();

    void on_multijugador_clicked();

private:
    Ui::menu *ui;   
    QString uss;
    QString pass;
    string clave;
    QMediaPlayer *music;//musica de fondo
    bool cargar=false;
};

#endif // MENU_H
